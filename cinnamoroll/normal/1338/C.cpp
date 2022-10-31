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

int memo[1<<8][1<<8];
int nimproduct(int a, int b){
	if(a==0 || b==0) return 0;
	if(a==1) return b;
	else if(b==1) return a;
	if(a<(1<<8) && b<(1<<8) && memo[a][b]) return memo[a][b];
	int a0, a1, b0, b1, c=max(a, b);
	int k;
	if(c<(1<<2)) k=2;
	else if(c<(1<<4)) k=4;
	else if(c<(1<<8)) k=8;
	else if(c<(1<<16)) k=16;
	else if(c<(1ull<<32)) k=32;
	else k=64;
	a0=a&((1ull<<(k>>1))-1), a1=a>>(k>>1);
	b0=b&((1ull<<(k>>1))-1), b1=b>>(k>>1);
	int c00=nimproduct(a0, b0), c01=nimproduct(a0, b1), c10=nimproduct(a1, b0), c11=nimproduct(a1, b1);
	int ans=((c11^c01^c10)<<(k>>1))^(nimproduct(c11, 1ull<<((k>>1)-1)))^c00;
	if(c<(1<<8)) memo[a][b]=ans;
	return ans;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n;
    cin >> n;
    //int n = i*3+3;

    int x = (n-1)/3;
    int v = 0;
    while(x){
      if(x-(1LL<<v)<0) break;
      x -= (1LL<<v);
      v += 2;
    }
    int a = (1LL<<v) + x;
    int b = nimproduct(2,x)+(1LL<<v)*2;
    int c = a^b;
    if(n%3==1) cout << a << "\n";
    else if(n%3==2) cout << b << "\n";
    else cout << c << "\n";
    //cout << a SP b SP c << endl;
  }

  return 0;
}