#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
enum{N=200000+100,K=17};
int n,k;char s[N];
int sum[N][30],f[1<<K];
int nxt[N][30];
bool chk(int x){
	for(int j=0;j<k;j++)nxt[n+1][j]=n+1;
	for(int i=n;i;i--){
		memcpy(nxt[i],nxt[i+1],sizeof nxt[i]);
		if(i+x-1>n)continue;
		for(int j=0;j<k;j++)
			if(sum[i+x-1][j]-sum[i-1][j]+sum[i+x-1][26]-sum[i-1][26]==x)
				nxt[i][j]=i+x-1;
	}
	for(int i=0;i<(1<<k);i++)
		f[i]=n+1;
	f[0]=0;
	for(int S=1;S<(1<<k);S++){
		for(int i=0;i<k;i++)if(S>>i&1)if(f[S^(1<<i)]!=n+1)
			chkmn(f[S],nxt[f[S^(1<<i)]+1][i]);
	}
	return f[(1<<k)-1]<=n;
}
signed main(){
	read(n,k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		memcpy(sum[i],sum[i-1],sizeof sum[i]);
		if('a'<=s[i]&&s[i]<='z')sum[i][s[i]-'a']++;
		else sum[i][26]++;
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	write(ans);
}