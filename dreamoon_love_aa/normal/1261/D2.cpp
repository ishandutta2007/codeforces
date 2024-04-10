/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
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
#define PB push_back
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
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
/*}}}*/
const int SIZE = 4e6+10;
const int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
LL fac[SIZE],inv[SIZE];
int N;
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void build(){
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
typedef long long ll;
const int MaxN=1<<18,mod=998244353;
ll pw(ll a,int n=mod-2){ll b=1;for(;n;n>>=1)n&1?b=b*a%mod:1,a=a*a%mod;return b;}
int wwss[1<<18];
void dft(int *a,int n,bool r=0){
    n=1<<n;
	int*w=&wwss[n/2];
	w[0]=1;w[1]=pw(3,(mod-1)/n);
	if(r)w[1]=pw(w[1]);
	for(int i=2;i<n/2;i++)w[i]=1ll*w[i-1]*w[1]%mod;
	for(int i=n/2;--i;)wwss[i]=wwss[i*2];
	w=wwss+1;
	for(int i=0,j=0,t;i<n;i++){
		if(i<j)t=a[i],a[i]=a[j],a[j]=t;
		for(t=n/2;(j^=t)<t;t/=2);
	}
	for(int i=1;i<n;w+=i,i*=2){
		for(int j=0;j<n;j+=i*2){
			for(int k=0,t;k<i;k++){
				t=a[i+j+k]*1ll*w[k]%mod;
				a[i+j+k]=(a[j+k]+mod-t)%mod;
				(a[j+k]+=t)%=mod;
			}
		}
	}
	if(r){
		ll I=pw(n);
		for(int i=0;i<n;i++)a[i]=a[i]*I%mod;
	}
}
int bb[MaxN];
void mult(int *target,int *aa,int K){
    if(target==aa){
        dft(target,K);
        REP(i,1<<K)target[i]=(LL)target[i]*target[i]%MOD;
        dft(target,K,1);
        REPP(i,N-1,1<<K)target[i]=0;
    }
    else{
        dft(target,K);
        REP(i,1<<K)bb[i]=aa[i];
        dft(bb,K);
        REP(i,1<<K)target[i]=(LL)target[i]*bb[i]%MOD;
        dft(target,K,1);
        REPP(i,N-1,1<<K)target[i]=0;
    }
}
int AA[SIZE];
int tmp[SIZE];
int main(){
    build();
    int n,k; R(n,k);
    FOR(i,1,n){
        R(AA[i]);
    }
    if(k==1){
        W(0);
        return 0;
    }
    int dif=0;
    FOR(i,1,n){
        if(AA[i]!=AA[i%n+1])dif++;
    }
    if(!dif){
        W(0);
        return 0;
    }
    tmp[0]=tmp[2]=1;
    tmp[1]=k-2;
    dft(tmp,20);
    REP(i,1<<20)tmp[i]=mypow(tmp[i],dif);
    dft(tmp,20,1);
    LL an=0;
    FOR(i,dif+1,dif*2){
        ADD(an,tmp[i]);
    }
    W(an*mypow(k,(n-dif))%MOD);
    return 0;
}