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

const int N=2e5+5,mod=1e9+7,B=137;
int n,m,sum[N],pw[N]={1},s[N][2];
char a[N];

inline int calc(int l,int r,int op){return (1ll*s[r][op]-1ll*s[l-1][op]*pw[sum[r]-sum[l-1]]%mod+mod)%mod;}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);scanf("%s",a+1);rd(m);
	for(re i=1;i<=n;++i) pw[i]=1ll*pw[i-1]*B%mod;
	for(re i=1;i<=n;++i){
		if(a[i]=='0') s[i][0]=(1ll*s[i-1][0]*B%mod+(i&1)+1)%mod,s[i][1]=(1ll*s[i-1][1]*B%mod+((i&1)^1)+1)%mod,sum[i]=sum[i-1]+1;
		else s[i][0]=s[i-1][0],s[i][1]=s[i-1][1],sum[i]=sum[i-1];
	}
	while(m--){
		int l1,l2,len;rd(l1);rd(l2);rd(len);
//		cout<<sum[l1+len-1]-sum[l1-1]<<' '<<sum[l2+len-1]-sum[l2-1]<<' '<<calc(l1,l1+len-1,l1&1)<<' '<<calc(l2,l2+len-1,l2&1)<<endl;
		if(sum[l1+len-1]-sum[l1-1]!=sum[l2+len-1]-sum[l2-1]||calc(l1,l1+len-1,l1&1)!=calc(l2,l2+len-1,l2&1)) puts("No");
		else puts("Yes");
	}
	return 0;
}

// ---------- Main ---------- //