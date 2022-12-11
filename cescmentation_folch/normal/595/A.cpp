#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define pb push_back
#define REP(i,a,f) for(int i = a; i < f; ++i) 

int main() {
  int n, m;
  cin >> n >> m;
  int res = 0;
  REP(i,0,n){
    REP(j,0,m){
      int x, y;
      cin >> x >> y;
      if(x + y) ++res;
    }
  }
  cout << res << endl;
}