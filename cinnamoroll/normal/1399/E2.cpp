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
#include "bits/stdc++.h"
using namespace std;
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<P> edge[101010];
priority_queue<P,vector<P>,function<bool(P,P)>> p([](P a, P b){return (a.fs+1)/2*a.sc < (b.fs+1)/2*b.sc;}),q([](P a, P b){return (a.fs+1)/2*a.sc < (b.fs+1)/2*b.sc;});
int sum = 0;
map<P,int> mp;

int dfs(int no, int par = -1){
  int cnt = 0;
  for(P to: edge[no]){
    if(to.fs==par) continue;
    int x = dfs(to.fs,no);
    if(mp[P(no,to.fs)] == 1) p.push(P(to.sc,x));
    else q.push(P(to.sc,x));
    cnt += x;
    sum += to.sc*x;
  }
  if(edge[no].size()==1) return 1;
  else return cnt;
}

void init(int N){
  REP(i,N) edge[i].clear();
  while(p.size()) p.pop();
  while(q.size()) q.pop();
  sum = 0;
}

bool f(P x, P y, P z){
  return (x.fs+1)/2*x.sc+(y.fs+1)/2*y.sc > (z.fs+1)/2*z.sc;
}

void solve(){
  int N,S;
  cin >> N >> S;
  init(N);

  REP(_,N-1){
    int x,y,c,d;
    cin >> x >> y >> c >> d;
    x--; y--;
    edge[x].emplace_back(y,c);
    edge[y].emplace_back(x,c);
    mp[P(x,y)] = mp[P(y,x)] = d;
  }

  dfs(0);
  int ans = 0;

  if(!p.size()){
    while(sum > S){
      P x = q.top();
      sum -= (x.fs-x.fs/2)*x.sc;
      q.pop();
      q.push(P(x.fs/2,x.sc));
      ans+=2;
    }
  }
  else if(!q.size()){
    while(sum > S){
      P x = p.top();
      sum -= (x.fs-x.fs/2)*x.sc;
      p.pop();
      p.push(P(x.fs/2,x.sc));
      ans++;
    }
  }

  else{ 
    priority_queue<P,vector<P>,function<bool(P,P)>> r([](P a, P b){return (a.fs+1)/2*a.sc < (b.fs+1)/2*b.sc;}),s([](P a, P b){return (a.fs+1)/2*a.sc < (b.fs+1)/2*b.sc;});
    r = p; s = q; int tmp = sum;
    bool flag;
    while(sum > S){
      P x = p.top(), z = q.top();
      if(sum - (x.fs+1)/2*x.sc <= S){
        ans++;
        break;
      }
      p.pop(); P y;
      if(p.size() && (p.top().fs+1)/2*p.top().sc > (x.fs/2+1)/2*x.sc) y = p.top(), flag = true;
      else y = P(x.fs/2, x.sc), flag = false;

      if(f(x,y,z)){
        sum -= (x.fs+1)/2*x.sc+(y.fs+1)/2*y.sc;
        if(flag) p.pop(),p.push(P(x.fs/2,x.sc));
        p.push(P(y.fs/2,y.sc));
      }
      else{
        sum -= (z.fs+1)/2*z.sc;
        p.push(x);
        q.pop();
        q.push(P(z.fs/2,z.sc));
      }
      ans+=2;
    }

    int ans2 = 1;
    p = r; q = s; sum = tmp;
    P x = p.top();
    sum -= (x.fs-x.fs/2)*x.sc;
    p.pop();
    p.push(P(x.fs/2,x.sc));
    while(sum > S){
      P x = p.top(), z = q.top();
      if(sum - (x.fs+1)/2*x.sc <= S){
        ans2++;
        break;
      }
      p.pop(); P y;
      if(p.size() && (p.top().fs+1)/2*p.top().sc > (x.fs/2+1)/2*x.sc) y = p.top(), flag = true;
      else y = P(x.fs/2, x.sc), flag = false;

      if(f(x,y,z)){
        sum -= (x.fs+1)/2*x.sc+(y.fs+1)/2*y.sc;
        if(flag) p.pop(),p.push(P(x.fs/2,x.sc));
        p.push(P(y.fs/2,y.sc));
      }
      else{
        sum -= (z.fs+1)/2*z.sc;
        p.push(x);
        q.pop();
        q.push(P(z.fs/2,z.sc));
      }
      ans2+=2;
    }
    chmin(ans,ans2);
  }

  cout << ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}