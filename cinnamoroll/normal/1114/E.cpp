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

random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<> rand2000000(1,2000000);

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  int n;
  cin >> n;

  // ok 30
  int ng = 0, ok = 1e9;
  while (abs(ng-ok)>1) {
    int mid = (ng+ok)/2;
    cout << "> " << mid << endl;
    cout.flush();
    int f;
    cin >> f;
    if(f) ng = mid;
    else ok = mid; 
  }

  int m = min(30LL,n);
  vector<int> tmp(m);
  vector<int> flag(n,0);
  REP(i,m){
    int pos;
    pos = rand2000000(mt) % n;
    while(flag[pos]) pos = rand2000000(mt) % n;
    flag[pos]++;
    cout << "? " << pos+1 << endl;
    cout.flush();
    cin >> tmp[i];
  }

  sort(tmp.begin(),tmp.end());
  int sa = tmp[1]-tmp[0];
  REP(i,m) FOR(j,i+1,m) sa = __gcd(sa,tmp[j]-tmp[i]);

  cout << "!" SP ok-sa*(n-1) SP sa << endl;
  cout.flush(); 

  return 0;
}