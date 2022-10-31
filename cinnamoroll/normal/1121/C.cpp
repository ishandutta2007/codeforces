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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //
  //DP

  int n,k;
  cin >> n >> k;

  vec a(n);
  REP(i,n) cin >> a[i];
  
  priority_queue<P,vector<P>,greater<P>> que;
  
  int cnt = 0;
  REP(i,min(k,n)-1) que.push(P(a[i],i));

  vec now(n,0);
  vec ans(n,0);
  while(cnt < n){
    if(cnt+min(k,n)-1 < n) que.push(P(a[cnt+min(k,n)-1],cnt+min(k,n)-1));
    priority_queue<P,vector<P>,greater<P>> que2;
    P tmp = que.top(); que.pop();
    if(now[tmp.sc] < round((double)cnt/n*100) && round((double)cnt/n*100) <= now[tmp.sc]+tmp.fs) ans[tmp.sc]++; 
    now[tmp.sc] += tmp.fs;
    while(que.size()){
      P cur = que.top(); que.pop();
      if(now[cur.sc] < round((double)cnt/n*100) && round((double)cnt/n*100) <= now[cur.sc]+tmp.fs) ans[cur.sc]++; 
      now[cur.sc] += tmp.fs;
      que2.push(P(cur.fs-tmp.fs,cur.sc));
    }
    cnt++;
    que = que2;
    //REP(i,n) cout << now[i] << " ";
    //cout <<  round((double)(cnt-1)/n*100) << endl;
  }
  int res = 0;
  REP(i,n) if(ans[i]) res++;
  cout << res << endl;

  return 0;
}