#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1<<20|5,MOD=998244353;
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
namespace POLY{
	int w[23][MAX_N],inv[MAX_N];
	struct Init{
		Init(){
			inv[1]=1; 
			for(int l=1;l<=20;++l){
				inv[1<<l]=1ll*inv[1<<l-1]*(MOD+1>>1)%MOD;
				w[l][0]=1; int wn=fpow(3,MOD-1>>l);
				for(int i=1;i<1<<l-1;++i)
					w[l][i]=1ll*w[l][i-1]*wn%MOD;
			}
		}
	}Initer__;
	inline void NTT(int a[],int n,int t){
		for(int i=0,pos=0;i<n;++i){
			if(i<pos) swap(a[i],a[pos]);
			for(int p=n>>1;(pos^=p)<p;p>>=1);
		}
		for(int s=1,sx=2,p=1;s<n;sx=(s=sx)<<1,++p)
			for(int i=0;i<n;i+=sx)
				for(int j=i,*wn=w[p];j<i+s;++j){
					int x=a[j],y=1ll*a[j+s]*(*wn++)%MOD;
					a[j]=x+y>=MOD?x+y-MOD:x+y;
					a[j+s]=x-y<0?x-y+MOD:x-y;
				}
		if(t==-1){
			reverse(a+1,a+n);
			for(int i=0;i<n;++i) a[i]=1ll*a[i]*inv[n]%MOD;
		}
	}
	inline void mul(int a[],int b[],int n){
		NTT(a,n,1); NTT(b,n,1);
		for(int i=0;i<n;++i) a[i]=1ll*a[i]*b[i]%MOD;
		NTT(a,n,-1);
	}
}
int num(char x){
	if(x=='A') return 0;
	if(x=='G') return 1;
	if(x=='T') return 2;
	return 3;
}
const int N=5+4e5;
bitset<N> a[4],ans;
char s[N],t[N];
int f[4][N];
int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s,t);
	for(int i=0;i<n;++i){
		f[num(s[i])][max(0,i-k)]++;
		f[num(s[i])][i+k+1]--;
	}
	for(int t=0;t<4;++t){
		for(int i=0;i<=n+n;++i){
			f[t][i]+=f[t][i-1];
			a[t][i]=f[t][i]>0;
		}
//		for(int i=0;i<n;++i) printf("<%d>",(int)a[t][i]); puts("");
	}
	for(int i=0;i<=n+n;++i) ans[i]=1;
	for(int i=0;i<m;++i)
		ans&=(a[num(t[i])]>>i);
	int ret=0;
	for(int i=0;i<n-m+1;++i)
		if(ans[i]) ++ret;
	printf("%d\n",ret);
	return 0;
}