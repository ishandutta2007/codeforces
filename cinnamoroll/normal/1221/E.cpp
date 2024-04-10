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
 
bool check(int a, int b, vec &c){
  int n = c.size(), cnt = 0, cnt2 = 0, sz;
  REP(i,n){
    if(c[i] < b) continue;
    if(range(c[i],b,a)) return false;
    if(c[i] >= 2*b) cnt2++, sz = c[i];
    cnt++;
  }
  if(cnt==0||cnt2>1) return false;
  if(cnt2==0) return cnt%2;
  REP(i,sz-a+1){
    int l = i, r = sz-a-i;
    if(range(l,b,a)||range(r,b,a)||l>=2*b||r>=2*b) continue;
    int tmp = cnt;
    if(l>=a) tmp++; if(r>=b) tmp++;
    if(tmp%2) return true;
  }
  return false;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int q;
  cin >> q;
 
  REP(_,q){
    int a,b;
    string s;
    cin >> a >> b >> s;
    int n = s.size();
    vec c;
    int cnt = 0;
    REP(i,n){
      if(s[i]=='.') cnt++;
      else{
        if(cnt) c.push_back(cnt);
        cnt = 0;
      }
    }
    if(cnt) c.push_back(cnt);
 
    if(check(a,b,c)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
 
 
  return 0;
}