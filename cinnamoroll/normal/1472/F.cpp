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
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (1&(i>>j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}

void solve(){
  int N,M;
  cin >> N >> M;

  //debug(N); debug(M);
  
  set<P> ng;
  vector<P> a(M);
  vec b(M);
  REP(i,M){
    cin >> a[i].sc >> a[i].fs;
    a[i].fs--; a[i].sc--;
    ng.insert(a[i]);
    b[i] = a[i].fs;
  }

  b = compress(b);
  map<int,int> mp;
  REP(i,b.size()) mp[b[i]] = i;

  b[0] = b[0] % 2;

  REP(i,b.size()-1){
    if(b[i]+2 < b[i+1]){
      b[i+1] = b[i]+2 + (b[i+1]-b[i])%2;
    }
  }

  if(M%2){
    cout << "NO" << endl;
    return;
  }
  
  sort(a.begin(),a.end());
  
  mat f(b.back()+1,vec(2,0));
  REP(i,M){
    int id = mp[a[i].fs];
    a[i].fs = b[id];
    f[a[i].fs][a[i].sc] = 1;
  }

  int K = b.back()+1;
  
  // REP(i,2){
  //   REP(j,K) cout << f[j][i];
  //   cout << endl;
  // }

  REP(i,K){
    if(!f[i][0] && !f[i][1]){
      f[i][0] = f[i][1] = 1;
    }
    else if(!f[i][0] && f[i][1]){
      if(i+1 >= K || f[i+1][0]){
        cout << "NO" << endl;
        return;
      }
      f[i][0] = f[i+1][0] = 1;
    }
    else if(f[i][0] && !f[i][1]){
      if(i+1 >= K || f[i+1][1]){
        cout << "NO" << endl;
        return;
      }
      f[i][1] = f[i+1][1] = 1;
    }
    else if(f[i][0] && f[i][1]){
    }

  // REP(i,2){
  //   REP(j,K) cout << f[j][i];
  //   cout << endl;
  // }

  }

  cout << "YES" << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}