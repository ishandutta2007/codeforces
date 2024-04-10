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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<int> b(n);
  REP(i,n) cin >> b[i];
  
  int x = 1, y = 0;
  set<int> st[2]; st[0].insert(a[0]);
  vec index;
  while(1){
    while(st[0].size()){
      if(st[0].find(b[y]) != st[0].end()) st[0].erase(st[0].find(b[y]));
      else st[1].insert(b[y]);
      y++;
    }
    if(st[1].size()==0){
      index.push_back(x);
      if(x==n) break;
      st[0].insert(a[x]);
      x++;
      continue;
    }
    while(st[1].size()){
      if(st[1].find(a[x]) != st[1].end()) st[1].erase(st[1].find(a[x]));
      else st[0].insert(a[x]);
      x++;
    }   
    if(st[0].size()==0){
      index.push_back(x);
      if(x==n) break;
      st[0].insert(a[x]);
      x++;
      continue;
    }
  }
  //cout << index.size() << endl;

  if(index.size() < k) cout << "No" << endl;
  else{
    cout << "Yes" << endl;
    int id = 0;
    string ans(n,'-');
    REP(i,n){
      if(index[id]==i) id++;
      ans[a[i]-1] = 'a'+min(id,25LL);
    }
    cout << ans << endl;
  }

  return 0;
}