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
#define D double
#define fs first
#define sc second
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

string calc(deque<int> &dq){
  if(dq.size() == 1) return "L";
  string res;
  int l = 1, r = 1;
  REP(i,dq.size()-1){
    if(dq[i] < dq[i+1]) l++;
    else break;
  }
  RREP(i,dq.size()-1){
    if(dq[i+1] < dq[i]) r++;
    else break;
  }
  if(l > r) REP(_,l) res += "L";
  else REP(_,r) res += "R";

  return res;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  deque<int> dq(n);
  REP(i,n) cin >> dq[i];

  string ans;
  int cur = 0;
  while(dq.size()){
    if(dq.front() < dq.back()){
      if(cur < dq.front()){
        cur = dq.front();
        dq.pop_front();
        ans += "L";
      }
      else if(cur < dq.back()){
        cur = dq.back();
        dq.pop_back();
        ans += "R";
      }
      else break;
    }
    else if(dq.front() > dq.back()){
      if(cur < dq.back()){
        cur = dq.back();
        dq.pop_back();
        ans += "R";
      }
      else if(cur < dq.front()){
        cur = dq.front();
        dq.pop_front();
        ans += "L";
      }
      else break;      
    }
    else{
      if(cur < dq.front()) ans += calc(dq);
      break;
    }
  }

  cout << ans.size() << endl << ans << endl;

  return 0;
}