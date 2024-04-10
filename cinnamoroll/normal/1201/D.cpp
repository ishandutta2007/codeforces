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
#define INF (1LL<<30)
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m,k,q;
  cin >> n >> m >> k >> q;

  vector<P> a(k);
  REP(i,k) cin >> a[i].fs >> a[i].sc;

  sort(a.begin(),a.end());
  
  vec distL(m+1,-INF), distR(m+1,INF);
  vector<int> b(q);
  REP(i,q) cin >> b[i], distL[b[i]] = b[i], distR[b[i]] = b[i];

  sort(b.begin(),b.end());

  REP(i,m) distL[i+1] = max(distL[i+1],distL[i]);
  RREP(i,m) distR[i] = min(distR[i+1],distR[i]);
  
  int r = a[0].fs, id = 0;
  int Lmn = 0, Rmn = 0, inL = 1, inR = 1;
  while(id < k){
    int L = a[id].sc, R = a[id].sc; r = a[id].fs;
    while(id < k && a[id].fs == a[id+1].fs) R = a[id+1].sc,id++;
    if(r==1){
      inL = L, inR = R;
      Lmn = R-1+(R-L), Rmn = R-1;
      id++;
      continue;
    }
    int cur = Lmn;
    //Lmn
    int tmp = abs(inL-distR[inL]) + abs(distR[inL]-R) + abs(R-L);//
    int tmp2 = abs(inR-distR[inR]) + abs(distR[inR]-R) + abs(R-L);
    int tmp3 = abs(inL-distL[inL]) + abs(distL[inL]-R) + abs(R-L);//
    int tmp4 = abs(inR-distL[inR]) + abs(distL[inR]-R) + abs(R-L);
    
    Lmn = min(Lmn+min(tmp,tmp3),Rmn+min(tmp2,tmp4));
    //Rmn
    tmp = abs(inL-distL[inL]) + abs(distL[inL]-L) + abs(R-L);//
    tmp2 = abs(inR-distL[inR]) + abs(distL[inR]-L) + abs(R-L);
    tmp3 = abs(inL-distR[inL]) + abs(distR[inL]-L) + abs(R-L);//
    tmp4 = abs(inR-distR[inR]) + abs(distR[inR]-L) + abs(R-L);
    Rmn = min(cur+min(tmp,tmp3),Rmn+min(tmp2,tmp4));

    inL = L, inR = R;
    id++;
    //cout << Lmn SP Rmn SP inL SP inR << endl;
  }

  cout << min(Lmn,Rmn) + a.back().fs-1 << endl;

  return 0;
}