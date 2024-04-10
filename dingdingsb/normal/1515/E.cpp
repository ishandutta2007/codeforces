#include<bits/stdc++.h>
using namespace std;
int mod;
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
int n;
const int N=420;
struct poly{
	modint a[N];
	modint&operator[](int x){return a[x];}
	void init(){memset(a,0,sizeof a);}
	void cpy(poly&b){memcpy(a,b.a,sizeof a);}
}tmp,tmp1,tmp2;
void mul(poly&c,poly&a,poly&b){
	c.init();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(i+j<=n)c[i+j]+=a[i]*b[j];
}
void pow(poly&res,poly a,int b){
	static poly tmp;
	res.init();res[0]=1;
	while(b){
		if(b&1)mul(tmp,res,a),res.cpy(tmp);
		mul(tmp,a,a),a.cpy(tmp);b>>=1;
	}
}
modint fac[N];
signed main(){
	scanf("%d%d",&n,&mod);
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
	modint ans=0;
	tmp1.init();
	for(int i=1;i<=n;i++)tmp1[i]=(modint(2)^i-1)/fac[i];
	for(int i=1;i<=(n+1)/2;i++){
		pow(tmp2,tmp1,i);
		ans+=tmp2[n-i+1]*fac[n-i+1];
		//printf("%d %d\n",i,ans);
	}
	printf("%d",ans);
}