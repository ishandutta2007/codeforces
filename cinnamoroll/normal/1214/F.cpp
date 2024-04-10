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

const int N = 2e5+10;
vec sum(2*N,0);
int m,n;

//[l,r)
void calc(vector<P> &p,int id, int l, int r, int val){
  int lb = lower_bound(p.begin(),p.end(),P(l,-1)) - p.begin();
  int rb = lower_bound(p.begin(),p.end(),P(r,-1)) - p.begin();
  lb -= id; rb -= id;
  if(lb < 0) lb += n, rb += n;
  sum[lb] += val; sum[rb] -= val;
}

//(l,r]
void calc2(vector<P> &p,int id, int l, int r, int val){
  int lb = upper_bound(p.begin(),p.end(),P(l,INF)) - p.begin();
  int rb = upper_bound(p.begin(),p.end(),P(r,INF)) - p.begin() - 1; //
  lb = id-lb; rb = id-rb; swap(lb,rb); rb++;
  if(lb < 0) lb += n, rb += n;
  sum[lb] += val; sum[rb] -= val;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n;

  vector<P> a(n),b(n);
  REP(i,n) cin >> a[i].fs,a[i].sc = i;
  REP(i,n) cin >> b[i].fs,b[i].sc = i;
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  //m/2

  //xmimos
  REP(i,n){
    calc(b,i,a[i].fs-m,a[i].fs-(m+1)/2,-a[i].fs+m);
    calc(b,i,a[i].fs-(m+1)/2,a[i].fs,a[i].fs);
    calc(b,i,a[i].fs,a[i].fs+(m+1)/2,-a[i].fs);
    calc(b,i,a[i].fs+(m+1)/2,a[i].fs+m,a[i].fs+m);
  }

  //yimos
  REP(i,n){
    calc2(a,i,b[i].fs-m,b[i].fs-(m+1)/2,-b[i].fs);
    calc2(a,i,b[i].fs-(m+1)/2,b[i].fs,b[i].fs);
    calc2(a,i,b[i].fs,b[i].fs+(m+1)/2,-b[i].fs);
    calc2(a,i,b[i].fs+(m+1)/2,b[i].fs+m,b[i].fs);
  }

  //sum[i],sum[i+n]->0i2
  REP(i,2*n) sum[i+1] += sum[i];

  int mn = INF, id = -1;
  REP(i,n){
    if(mn > sum[i]+sum[i+n]){
      mn = sum[i]+sum[i+n];
      id = i;
    }
  }

  vec ans(n);
  REP(i,n) ans[a[i].sc] = b[(i+id)%n].sc+1;

  cout << mn << endl;
  REP(i,n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}