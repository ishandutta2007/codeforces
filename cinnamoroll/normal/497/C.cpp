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

  int n;
  cin >> n;

  using T = tuple<int,int,int>;
  using U = tuple<int,int,int,int>;
  
  vector<T> a(n);
  REP(i,n){
    int x,y;
    cin >> x >> y;
    a[i] = T(x,y,i);
  }

  int m;
  cin >> m;

  vector<U> b(m);
  REP(i,m){
    int x,y,z;
    cin >> x >> y >> z;
    b[i] = U(x,y,z,i+1);
  }
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  //priority_queue<T,vector<T>,greater<T>> que;
  set<T> st;
  int id = 0; vec ans(n);
  REP(i,n){
    int u,v,w;
    tie(u,v,w) = a[i];
    while(id<m){
      int x,y,z,in;
      tie(x,y,z,in) = b[id];
      if(u >= x){
        id++;
        //que.push(T(y,z,in));
        st.insert(T(y,z,in));
      }
      else break;
    }

    auto itr = st.lower_bound(T(v,-1,-1));
    if(itr == st.end()){
      cout << "NO" << endl;
      return 0;
    }
    else{
      int x,y,z;
      tie(x,y,z) = *itr;
      st.erase(itr);
      ans[w] = z;
      if(y>1) st.insert(T(x,y-1,z));
    }

    //bool flag = false;
    //vector<T> st;
    //while(que.size()){
      //int x,y,z;
      //tie(x,y,z) = que.top(); que.pop();
      // if(x >= v){
      //   ans[w] = z;
      //   if(y>1) que.push(T(x,y-1,z));
      //   flag = true;
      //   break;
      // }
      //else if(u <= x) st.emplace_back(T(x,y,z));
    //}
    //REP(i,st.size()) que.push(st[i]);
    // if(flag==false){
    //   cout << "NO" << endl;
    //   return 0;
    // }
  }

  cout << "YES" << endl;
  REP(i,n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}