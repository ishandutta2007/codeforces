#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

struct sumbit{
  int n;
  vector<Int> bit;
  sumbit(int n):n(n),bit(n+1,0){
  }
  void add(int pos, Int val){
    pos++;
    while(pos <= n){
      bit[pos] += val;
      pos += pos & -pos;
    }
  }
  Int get(int pos){
    pos++;
    Int res = 0;
    while(pos){
      res += bit[pos];
      pos -= pos & -pos;
    }
    return res;
  }
};

void solve(){
  Int n;
  string s, t;
  cin >> n;
  cin >> t >> s;
  vector<int> tpos[26];
  for(int i = n-1;i >= 0;i--){
    int c = t[i] - 'a';
    tpos[c].push_back(i);
  }
  sumbit used(n+10);
  Int ans = LINF;
  Int accum = 0;
  for(int i = 0;i < n;i++){
    int c = s[i] - 'a';
    int first_less = INF;
    int first_less_char;
    for(int j = 0;j < c;j++){
      if(!tpos[j].empty()){
	int candidate = tpos[j].back();
	if(candidate < first_less){
	  first_less = candidate;
	  first_less_char = j;
	}
      }
    }
    if(first_less != INF){
      ans = min(ans, accum + first_less - used.get(first_less));
    }
    if(tpos[c].empty())break;
    int from = tpos[c].back();
    tpos[c].pop_back();
    accum += from - used.get(from);
    used.add(from, 1);
  }

  if(ans == LINF)ans = -1;
  cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}