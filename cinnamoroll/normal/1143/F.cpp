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
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
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

int det(P x,P y){
  return x.fs*y.sc-x.sc*y.fs;
}
P sub(P x,P y){
    return P(x.first-y.first, x.second-y.second);
}

vector<P> Convex_Hull(vector<P>& p){
  int n = p.size(), k = 0;
  sort(p.begin(),p.end());
  vector<P> q(2*n);
  REP(i,n){
    while(k > 1 && det(sub(q[k-1],q[k-2]),sub(p[i],q[k-1])) >= 0) k--;
    q[k++] = p[i];
  }
  q.resize(k);
  return q;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  map<int,int> mp;
  REP(i,n){
    int x,y;
    cin >> x >> y;
    // xy
    if(!mp.count(x)) mp[x] = y-x*x;
    else mp[x] = max(mp[x],y-x*x);
  }
  vector<P> point;
  ITR(itr,mp) point.push_back(P(itr->fs,itr->sc));
  
  vector<P> tmp = Convex_Hull(point);

  cout << tmp.size()-1 << endl;

  return 0;
}