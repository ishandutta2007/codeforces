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
#define MOD 998244353
#define INF 1LL<<60
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
#define range(i,a,b) (a)<=(i) && (i)<(b)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int t;
  cin >> t;

  REP(_,t){
    int n;
    cin >> n;

    vector<int> l(n),r(n);
    REP(i,n) cin >> l[i] >> r[i];
    
    vector<tuple<int,int,int>> tp(n);
    REP(i,n) tp[i] = make_tuple(l[i],r[i],i);
    sort(tp.begin(),tp.end());
    
    //REP(i,n) debug(get<0>(tp[i]));

    vector<int> ans(n,0);
    int tmp = 0;
    bool check = false;
    ans[get<2>(tp[0])] = 1;
    int id = 1;
    tmp = get<1>(tp[0]);
    FOR(i,1,n){
      if(tmp >= get<0>(tp[i])){
        ans[get<2>(tp[i])] = id;
        tmp = max(tmp,get<1>(tp[i]));
      }
      else{
        id *= -1;
        ans[get<2>(tp[i])] = id;
        tmp = max(tmp,get<1>(tp[i]));
        check = true;
      }
    }

    if(!check) cout << -1 << endl;
    else{
      REP(i,n) cout << (ans[i]==1?1:2) << " ";
      
    cout << endl;}
    }

  return 0;
}