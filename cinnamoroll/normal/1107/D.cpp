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
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
  int n;
  int bit[5300][5300];
bool check(int x){
  REP(i,n/x){
    REP(j,n/x){
      int pos = bit[x*i][x*j];
      //debug(pos);
      REP(s,x){
        REP(t,x){
          //cout << x*i+s SP x*j+t << endl;
          if(pos != bit[x*i+s][x*j+t]) return false; 
        }
      }
    }
  }
  return true;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  


  cin >> n;

  vector<string> s(n);
  REP(i,n) cin >> s[i];
  
  map<char,int> mp;
  REP(i,10) mp['0'+i] = i;
  REP(i,6) mp['A'+i] = 10+i;


  REP(i,n){
    REP(j,n/4){
      int tmp = mp[s[i][j]];
      REP(k,4) bit[i][j*4+k] = (tmp&(1<<(3-k))?1:0);
    }
  }

  vector<P> pri;
  int cnt = n;
  for(int i=2;i<=sqrt(cnt);i+=2){
    bool flag = true;
      for(int j=3; j<=sqrt(i);j+=2){
      if(i%j == 0){
      flag = false;
      break;
      }
    }
    if(flag || i == 2){
      int pos = 0;
      while(cnt%i == 0) pos++,cnt/=i;
      if(pos) pri.pb(P(i,pos));
    }
    if(i == 2) i--;
  }

  if(cnt != 1) pri.pb(P(cnt,1));

  int ans = 1;
  REP(i,pri.size()){
    P cur = pri[i];
    //cout << cur.fs SP cur.sc << endl;
    int tmp = 1;
    REP(j,cur.sc){
      if(check(tmp*cur.fs)) tmp *= cur.fs;
      else break;
    }
    ans *= tmp;
  }

  cout << ans << endl;

  return 0;
}