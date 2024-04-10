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
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int n;
void f(string &s, int id){
  //debug(id);
  string u = s.substr(n-id,2000);
  reverse(u.begin(),u.end());
  s = u+s.substr(0,n-id);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s,t;
  cin >> n >> s >> t;

  vec cnt(26,0);
  REP(i,n){
    cnt[s[i]-'a']++;
    cnt[t[i]-'a']--;
  }

  REP(i,26) if(cnt[i]){
    cout << -1 << endl;
    return 0;
  }

  vec ans; int in = (n)/2;
  REP(i,n){
    int id; //debug(in);
    REP(j,n-i) if(s[j]==t[in]) id = j;
    ans.push_back(n-id); //debug(id);
    f(s,n-id);
    //debug(s);
    ans.push_back(id+1);
    f(s,id+1);
   // debug(s);
    ans.push_back(n-id-1-i);
    f(s,n-id-1-i);
    if(i%2==0) in -= i+1;
    else in += i+1;
    //debug(s);
  }

  if(s!=t) ans.push_back(n);

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i] << " ";

  return 0;
}