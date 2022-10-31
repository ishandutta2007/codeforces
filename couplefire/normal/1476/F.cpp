#include<bits/stdc++.h>
typedef int LL;
typedef double dl;
#define opt operator
#define pb push_back
#define pii std::pair<LL,LL>
const LL maxn=3e5+9,mod=998244353,inf=0x3f3f3f3f;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3ll)+(x<<1ll)+c-'0'; c=getchar();
	}return x*f;
}
void Chkmin(LL &x,LL y){
	if(y<x) x=y;
}
void Chkmax(LL &x,LL y){
	if(y>x) x=y;
}
LL add(LL x,LL y){
	return x+=y,x>=mod?x-mod:x;
}
LL dec(LL x,LL y){
	return x-=y,x<0?x+mod:x;
}
LL mul(LL x,LL y){
	return 1ll*x*y%mod;
}
LL Pow(LL base,LL b){
	LL ret(1); while(b){
		if(b&1) ret=mul(ret,base); base=mul(base,base); b>>=1;
	}return ret;
}
namespace Rmq{
	LL mx[maxn][20],lg[maxn];
	LL Query(LL l,LL r){
		if(l>r) return 0;
		LL len(lg[r-l+1]-1);
		return std::max(mx[l][len],mx[r-(1<<len)+1][len]);
	}
	void Init(LL *A,LL N){
		for(LL i=1;i<=N;++i){
			mx[i][0]=A[i];
		}
		for(LL i=1;i<=N;++i) lg[i]=lg[i>>1]+1;
        for(LL i=1;i<=19;++i){
			for(LL j=1;j+(1<<i-1)<=N;++j){
				mx[j][i]=std::max(mx[j][i-1],mx[j+(1<<i-1)][i-1]);
			}
		}
	}
}
LL n;
LL a[maxn],p[maxn];
void Solve(){
	static LL dp[maxn],trans[maxn],pre[maxn];
	static char ans[maxn];
	n=Read();
	for(LL i=1;i<=n;++i){
		p[i]=Read();
	}
	for(LL i=1;i<=n;++i){
		a[i]=i+p[i];
	}
	Rmq::Init(a,n);
	for(LL i=1;i<=n;++i){
		dp[i]=dp[i-1]; trans[i]=0;
		if(dp[i-1]>=i){
			Chkmax(dp[i],i+p[i]);
		}
		LL lt(std::max(0,i-p[i]-1));
		LL l(0),r(i-1),ret(-1);
		while(l<=r){
			LL mid(l+r>>1);
			if(dp[mid]>=lt){
				ret=mid; r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(ret!=-1){
			LL tmp(std::max(i-1,Rmq::Query(ret+1,i-1)));
			if(tmp>dp[i]){
				dp[i]=tmp;
				pre[i]=ret;
				trans[i]=1;
			}
		}
	}
	if(dp[n]<n){
		puts("NO");
		return;
	}
	puts("YES");
	for(LL i=n;i>=1;){
		if(!trans[i]){
			ans[i]='R';
			--i;
		}else{
			ans[i]='L';
			LL tmp(pre[i]);
			--i;
			while(i>tmp){
				ans[i]='R';
				--i;
			}
		}
	}
	for(LL i=1;i<=n;++i) printf("%c",ans[i]); puts("");
}
int main(){
	LL T=Read();
	while(T--){
		Solve();
	}
	return 0;
}