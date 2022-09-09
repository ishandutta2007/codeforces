#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
int get_bit(LL x, int v){return (x>>v)&1;}
LL a[SIZE];
int n,m,p;
LL an;
int ma;
int dp[1<<15];
void test(LL x){
    if(!x)return;
	VI d;
	REP(i,m){
		if(get_bit(x,i)){
				d.PB(i);
		}
	}
	MS0(dp);
	REP(i,n){
		  int me=0;
			REP(j,SZ(d)){
				if(!get_bit(a[i],d[j])){
					me|=1<<j;
				}
			}
			dp[me]++;
	}
	int sz=1<<SZ(d);
	REP(i,SZ(d)){
		REP(j,sz){
			if(get_bit(j,i))dp[j]+=dp[j^(1<<i)];
		}
	}
	REP(i,sz){
		if(dp[i] >= (n+1)/2){
			if(SZ(d)-__builtin_popcount(i)>ma){
				ma=SZ(d)-__builtin_popcount(i);
				an=0;
				REP(j,SZ(d)){
					if(!get_bit(i,j)){
					   an|=1LL<<d[j];
			        }
				}
			}
		}
	}
}
mt19937 rng(0x5EED);
int randint(int lb, int ub) {
    return uniform_int_distribution<int>(lb, ub)(rng);
}
void solve() {
	  mt19937 rng(time(NULL));
	  
	REP(tt,5){
	  for(int i = 1; i < n; i++) {
	  	int id=randint(0,i);
	  	if(id != i) {
	  		swap(a[id], a[i]);
	  	}
	  }
      REP(i,min(20,n)){
    	test(a[i]);
      }
	}
    REP(i,m){
    	_W(get_bit(an,i));
    }
    W("");
}
void input() {
	  ma=0;
	  an=0;
		R(n,m,p);
		REP(i,n){
			char s[66];
			RS(s);
			LL me=0;
			REP(j,m){
				if(s[j]=='1')me|=1LL<<j;
				a[i]=me;
			}
		}
}
int main(){
        input();
        solve();
    return 0;
}