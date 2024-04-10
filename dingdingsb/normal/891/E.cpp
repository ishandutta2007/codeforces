#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
	modint operator - () {return x?mod-x:0;}
};
const int N=5010;
int n,k;modint a[N];
modint poly[N];
signed main(){
	scanf("%d%d",&n,&k);
	modint tmp=1,res=1,inv=modint(1)/n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),res*=a[i];
	poly[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=n;j;j--)
			poly[j]=-poly[j-1]+a[i]*poly[j];
		poly[0]*=a[i];
	}
	for(int i=k;i>=k-n;i--){
		if(k-i<0)continue;
		res-=tmp*poly[k-i];
		tmp*=i;tmp*=inv;
	}
	printf("%d",res);
}