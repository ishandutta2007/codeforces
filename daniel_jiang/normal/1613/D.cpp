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
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=5e5+5,mod=998244353;
ll T,n,a[N],f[N][2],ans;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(T);
	while(T--){
		rd(n);ans=0;
		for(re i=1;i<=n;++i) rd(a[i]);
		for(re i=0;i<=n+2;++i)f[i][0]=f[i][1]=0;f[0][0]=1;
		for(re i=1;i<=n;++i){
			ans=((ans+f[a[i]][0]+f[a[i]+1][0]+f[a[i]+1][1])%mod+mod)%mod;
			if(a[i]) ans=((ans+f[a[i]-1][0]+f[a[i]-1][1])%mod+mod)%mod;
			f[a[i]+1][0]=((f[a[i]+1][0]+f[a[i]][0]+f[a[i]+1][0])%mod+mod)%mod;
			f[a[i]+1][1]=((f[a[i]+1][1]+f[a[i]+1][1])%mod+mod)%mod;
			if(a[i]) f[a[i]-1][1]=((f[a[i]-1][1]+f[a[i]-1][0]+f[a[i]-1][1])%mod+mod)%mod;
		}
		wr(ans);puts("");
	}
	return 0;
}

// ---------- Main ---------- //