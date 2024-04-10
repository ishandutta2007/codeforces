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
#define MOD 1000000007
//#define MOD 998244353
#define INF (1LL<<60)
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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<char,char> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int n;
vector<P> calc(vector<string> &s, bool flag){
  vector<string> t[n];
  REP(i,s.size()) t[s[i].size()].push_back(s[i]);
  vec cnt(26,0); REP(i,t[n-1][0].size()) cnt[t[n-1][0][i]-'a']++;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;

  if(n==1){
    cout << "? 1 1" << endl;
    string s; cin >> s;
    cout << "!" SP s << endl;
    return 0;
  }

  vec ans(n,-1);

  cout << "?" SP 1 SP n << endl;
  multiset<vec> s[n+1];
  REP(i,n*(n+1)/2){
    string x;
    cin >> x;
    vec cnt(26,0);
    REP(j,x.size()) cnt[x[j]-'a']++;
    s[x.size()].insert(cnt);
  }
  
  cout << "?" SP 2 SP n << endl;
  multiset<vec> t[n+1];
  REP(i,n*(n-1)/2){
    string x;
    cin >> x;
    vec cnt(26,0);
    REP(j,x.size()) cnt[x[j]-'a']++;
    t[x.size()].insert(cnt);
  }

  vec a = *s[n].begin(), b = *t[n-1].begin();
  REP(i,26) if(a[i]!=b[i]) ans[0] = i;
  
  FOR(i,1,n/2+1){
    vec used(i,0);
    ITR(itr,s[n-i]){
      vec x = *itr;
      bool flag = false;
      //i-1
      REP(j,i){
        if(used[j] || flag) continue;
        REP(k,j) x[ans[n-1-k]]++;
        REP(k,i-j) x[ans[k]]++;
        if(x==a) flag = true, used[j]++;
        REP(k,j) x[ans[n-1-k]]--;
        REP(k,i-j) x[ans[k]]--;        
      }
      if(flag) continue;
      REP(j,i-1) x[ans[n-1-j]]++;
      REP(j,26) if(a[j]!=x[j]) ans[n-i] = j;
      break;
    }
    used.assign(i,0);
    ITR(itr,t[n-1-i]){
      vec x = *itr;
      bool flag = false;
      //i-1
      REP(j,i){
        if(used[j] || flag) continue;
        REP(k,j) x[ans[k+1]]++;
        REP(k,i-j) x[ans[n-1-k]]++;
        if(x==b) flag = true, used[j]++;
        REP(k,j) x[ans[k+1]]--;
        REP(k,i-j) x[ans[n-1-k]]--;    
      }
      if(flag) continue;
      REP(j,i-1) x[ans[j+1]]++;
      REP(j,26) if(b[j]!=x[j]) ans[i] = j;
      break;
    }
  }

  cout << "! ";
  REP(i,n) cout << (char)(ans[i]+'a');
  cout << endl;

  return 0;
}