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
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<int> divisor(const int n){
  vector<int> ret;
  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      ret.push_back(i);
      if(i*i!= n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
}

typedef complex<double> C;
int fft_n;
vector<C> omega;
const double PI=3.14159265358979323846;

void init_fft(int n) {
  fft_n = n;
  omega.resize(n);
  double angle = 2 * PI / n;
  REP(i,n) {
    omega[i] = C(cos(i * angle), sin(i * angle));
  }
}

void fft(vector<C> & a) {
  int n = a.size();
  if (n == 1) return;
  int half = n >> 1;
  vector<C> even(half), odd(half);
  for (int i = 0, j = 0; i < n; i += 2, ++j) {
    even[j] = a[i];
    odd[j] = a[i+1];
  }
  fft(even); fft(odd);
  for (int i = 0, fact = fft_n / n; i < half; ++i) {
    C twiddle = odd[i] * omega[i * fact];
    a[i] = even[i] + twiddle;
    a[i + half] = even[i] - twiddle;
  }
}

vector<int> mul_fft(const vector<int> &a, const vector<int> &b) {
  vector<int> res;
  vector<C> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < 2 * max (a.size(), b.size())) n <<= 1;
  fa.resize(n); fb.resize(n);
  init_fft(n);
  fft(fa); fft(fb);
  REP(i,n) fa[i] = conj(fa[i] * fb[i]);
  fft(fa);
  res.resize (n);
  REP(i,n) {
    res[i] = (int) (fa[i].real() / n + 0.5);
  }
  return res;
}
// vec hoge = mul_fft(a,b)
// hoge[i]a[k]*b[i-k]
// a,b1-indexed(00)

vec f(1010101,0);
void solve(){
  int N,X,Y;
  cin >> N >> X >> Y;

  int base = 200000;
  vector<int> a(base+1,0), b(base+1,0);
  REP(i,N+1){
    int x; cin >> x;
    a[x]++;
    b[base-x]++;
  }
  
  auto c = mul_fft(a,b);

  FOR(i,base+1,c.size()) if(c[i]) f[i-base+Y]++;

  int Q; cin >> Q;
  REP(_,Q){
    int L; cin >> L;
    vec d = divisor(L/2);
    int ans = -1;
    if(L%2==0) for(int x:d) if(f[x]) chmax(ans,x*2);
    cout << ans << " ";
  }
  cout << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}