// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=(1<<20)+5,M=1e5+5,inv2=499122177;
ll n,m,a[N],b[N],g,c[M],ans=2e7+5;
char s[21][M];

inline void XOR(ll *f,int op){
	for(re s=2,k=1;s<=n;s<<=1,k<<=1)
		for(re i=0;i<n;i+=s)
			for(re j=0;j<k;++j){
				ll x=f[i+j],y=f[i+j+k];
				f[i+j]=x+y,f[i+j+k]=x-y;
				if(op==0) f[i+j]=f[i+j]/2,f[i+j+k]=f[i+j+k]/2;
			}
}// FWT op=1 IFWT op=inv

inline void mul(ll *f,ll *g){
	for(re i=0;i<n;++i) f[i]=f[i]*g[i];
}

inline void print(int *f){
	for(re i=0;i<n;++i) wr(f[i]),putchar(' ');puts("");
}

// ---------- FWT & IFWT ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(m);
	for(re i=0;i<n;++i) scanf("%s",s[i]);
	for(re j=0;j<m;++j)
		for(re i=0;i<n;++i)
			if(s[i][j]=='1') c[j]|=(1<<i);
	for(re i=0;i<m;++i) ++a[c[i]];
	for(re i=0;i<(1<<n);++i) b[i]=b[i>>1]+(i&1);
	for(re i=0;i<(1<<n);++i) b[i]=min(b[i],n-b[i]);
	n=(1<<n);
	XOR(a,1);XOR(b,1);mul(a,b);XOR(a,0);
	for(re i=0;i<n;++i) ans=min(ans,a[i]);
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //