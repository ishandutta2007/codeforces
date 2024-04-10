#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=1e6+10;
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
	template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
	modint &operator++(int){return *this+=1;}
};
modint y[N];
modint *pre,*suf;modint pool[N*2];
modint fac[N],ifac[N];
int pr[N],tot;modint id[N];bool npr[N];
modint get(int n,int k){
	//\sum_{i=1}^k i^n n+1 n+2 
	id[1]=1;
	for(int i=2;i<N;i++){
		if(!npr[i])pr[++tot]=i,id[i]=modint(i)^n;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			npr[i*pr[j]]=true;id[i*pr[j]]=id[i]*id[pr[j]];
			if(i%pr[j]==0)break;
		}
	}
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
	ifac[N-1]=1/fac[N-1];for(int i=N-1;i;i--)ifac[i-1]=ifac[i]*i;
	modint sum=0;pre=&pool[10];suf=&pool[N+10];
	for(int i=0;i<=n+1;i++,sum+=id[i])y[i]=sum;
	n=n+1;pre[-1]=suf[n+1]=1;
	for(int i=0;i<=n;i++)pre[i]=pre[i-1]*(k-i);
	for(int i=n;i>=0;i--)suf[i]=suf[i+1]*(k-i);
	sum=0;
	for(int i=0;i<=n;i++)
		if((n-i)&1)sum-=y[i]*pre[i-1]*suf[i+1]*ifac[i]*ifac[n-i];
		else sum+=y[i]*pre[i-1]*suf[i+1]*ifac[i]*ifac[n-i];
	return sum;
}
int n,k;
signed main(){
	scanf("%d%d",&n,&k);
	printf("%d",get(k,n));
}