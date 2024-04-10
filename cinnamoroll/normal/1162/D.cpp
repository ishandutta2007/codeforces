// warm heart, wagging tail,and a smile just for you!
//                                                                     
//                                                                   
//                                                                
//                                                   
//                                      
//                               
//                             
//                           
//                         
//                       
//                     
//                 
//     
//   
// 
// 
// 
// 
//   
//         
//                                                      
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<int> divisor(const int n){
  vector<int> ret;
  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      ret.push_back(i);
      if(i*i!= n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
}

const int N = 1e5+10, M = 2e5+10;
int n,m;
vector<int> a(M),b(M);
set<int> st[N];
bool check(int t){
  REP(i,m){
    int x = (a[i]+t)%n, y = (b[i]+t)%n;
    if(x > y) swap(x,y);
    if(st[x].count(y) == 0){
      return false;
    }
  }
  return true;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;

  REP(i,m){
    cin >> a[i] >> b[i];
    a[i] %= n; b[i] %= n;
    if(a[i] > b[i]) swap(a[i],b[i]);
    st[a[i]].insert(b[i]);
  }

  vec tmp = divisor(n);

  REP(i,tmp.size()-1){
    if(check(tmp[i])){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}