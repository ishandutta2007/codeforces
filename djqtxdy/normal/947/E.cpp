#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
namespace IO
{
    const int sz=1<<15;
    char inbuf[sz],outbuf[sz];
    char *pinbuf=inbuf+sz;
    char *poutbuf=outbuf;
    inline char _getchar()
    {
        if (pinbuf==inbuf+sz)fread(inbuf,1,sz,stdin),pinbuf=inbuf;
        return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
        if (poutbuf==outbuf+sz)fwrite(outbuf,1,sz,stdout),poutbuf=outbuf;
        *(poutbuf++)=x;
    }
    inline void flush()
    {
        if (poutbuf!=outbuf)fwrite(outbuf,1,poutbuf-outbuf,stdout),poutbuf=outbuf;
    }
}
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int mod=998244353;
const int Maxn=262144;
const int g=3;
int qp(int x,LL p){
	int ret=1;
	while (p){
		if (p&1) ret=1ll*ret*x%mod;
		p>>=1;
		x=1ll*x*x%mod; 
	}
	return ret;
}
int inv(int x){
	return qp(x,mod-2);
}
int rev[Maxn];
void NTT(int X[],int n,int f){
	for (int i=1;i<n;i++){
		rev[i]=rev[i>>1]>>1;
		if (i&1) rev[i]|=n>>1; 
	}
	for (int i=0;i<n;i++){
		if (i<rev[i]){
			swap(X[i],X[rev[i]]);
		}
	}
	for (int i=2;i<=n;i<<=1){
		int s=i>>1;
		int wn=qp(g,(mod-1)/i);
		if (f==-1) wn=inv(wn);
		for (int j=0;j<n;j+=i){
			int w=1;
			for (int k=j;k<j+s;k++){
				int u=X[k],v=1ll*X[k+s]*w%mod;
				X[k]=u+v;
				if (X[k]>=mod) X[k]-=mod;
				X[k+s]=u-v;
				if (X[k+s]<0) X[k+s]+=mod;
				w=1ll*w*wn%mod;
			}
		}
	}
	if (f==-1){
		int iv=inv(n);
		for (int i=0;i<n;i++){
			X[i]=1ll*X[i]*iv%mod;
		}
	}
} 
int n;
LL m;
int fact[Maxn],ivf[Maxn];
int P[Maxn],Q[Maxn],R[Maxn];
int main(){
	n=read();
	scanf("%lld",&m);
	fact[0]=1;
	for (int i=1;i<Maxn;i++) fact[i]=1ll*fact[i-1]*i%mod;
	for (int i=0;i<Maxn;i++) ivf[i]=inv(fact[i]);
	for (int i=0;i<=n;i++) scanf("%d",&P[i]);
	for (int i=-n;i<=0;i++){
		Q[i+n]=ivf[-i];
	}
	for (int i=0;i<=n;i++){
		P[i]=1ll*P[i]*fact[i]%mod;
	}
	NTT(P,Maxn,1);NTT(Q,Maxn,1);
	for (int i=0;i<Maxn;i++){
		P[i]=1ll*P[i]*Q[i]%mod;
	}
	NTT(P,Maxn,-1);
	
	for (int i=0;i<=n;i++){
		R[i]=1ll*P[i+n]*ivf[i]%mod;
	//	cout<<i<<" "<<R[i]<<endl;
	}
	
	memset(P,0,sizeof(P));
	for (int i=0;i<=n;i++){
		P[i]=1ll*R[i]*qp(inv(i+1),m)%mod;
	}
	
	for (int i=0;i<=n;i++){
		P[i]=1ll*P[i]*fact[i]%mod;
		if (i&1) P[i]=(mod-P[i])%mod;
	}
	
	memset(Q,0,sizeof(Q));
	for (int i=-n;i<=0;i++){
		Q[i+n]=ivf[-i];
	}
	
	NTT(P,Maxn,1);NTT(Q,Maxn,1);
	for (int i=0;i<Maxn;i++){
		P[i]=1ll*P[i]*Q[i]%mod;
	}
	NTT(P,Maxn,-1);
	
	for (int i=0;i<=n;i++){
		R[i]=1ll*P[i+n]*ivf[i]%mod;
		if (i&1) R[i]=mod-R[i];R[i]%=mod;
		printf("%d ",R[i]);
	}
	printf("\n");
	return 0;
}