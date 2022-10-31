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
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<tuple<int,int,int>> a,b;
  REP(i,n){
    int x,y;
    cin >> x >> y;
    if(x < y) a.push_back(tie(x,y,i));
    else b.push_back(tie(y,x,i));
  }

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  if(a.size() > b.size()){
    cout << a.size() << endl;
    RREP(i,a.size()){
      int x,y,z;
      tie(x,y,z) = a[i];
      cout << z+1 << " ";
    }
  }
  else{
    cout << b.size() << endl;
    REP(i,b.size()){
      int x,y,z;
      tie(x,y,z) = b[i];
      cout << z+1 << " ";
    }
  }

  return 0;
}