#include<bits/stdc++.h>
using namespace std;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=(o%mod+mod)%mod;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    modint<mod> &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint<mod> &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint<mod> &operator *=(int o){return x=1ll*x*o%mod,*this;}
    template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
};
typedef modint<1000000007>mint;
const int N=1e5+10;
int n,m,a[N];
mint c[6][6],s[6][N];
void pre(){
	c[0][0]=1;
	for(int i=1;i<=5;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(int i=1;i<=n;i++)s[0][i]=1;
	for(int j=1;j<=5;j++)
		for(int i=1;i<=n;i++)
			s[j][i]=s[j-1][i]*i;
	for(int j=0;j<=5;j++)
		for(int i=1;i<=n;i++)
			s[j][i]+=s[j][i-1];
}
#define sum(k,l,r) (s[k][r]-s[k][l-1])
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int l[N<<2],r[N<<2],tag[N<<2];
mint val[6][N<<2];
void down(int x){
	if(tag[x]!=-1){
		tag[lc]=tag[x];
		for(int i=0;i<=5;i++)
			val[i][lc]=sum(i,l[lc],r[lc])*tag[x];
			
		tag[rc]=tag[x];
		for(int i=0;i<=5;i++)
			val[i][rc]=sum(i,l[rc],r[rc])*tag[x];
		
		tag[x]=-1;
	}
}
void up(int x){
	for(int i=0;i<=5;i++) 
		val[i][x]=val[i][lc]+val[i][rc];
}
void build(int x,int l,int r){
	::l[x]=l,::r[x]=r,::tag[x]=-1;
	if(l==r){
		for(int i=0;i<=5;i++)
			val[i][x]=mint(a[l])*sum(i,l,l);
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(x);
}
#define l l[x]
#define r r[x]
void upd(int x,int ql,int qr,int v){
	if(ql<=l&&r<=qr){
		tag[x]=v;
		for(int i=0;i<=5;i++)
			val[i][x]=sum(i,l,r)*v;
		return;
	}
	down(x);
	if(ql<=mid)upd(lc,ql,qr,v);
	if(mid<qr)upd(rc,ql,qr,v);
	up(x);
}
mint qry(int x,int ql,int qr,int k){
	if(ql<=l&&r<=qr)return val[k][x];
	if(r<ql||l>qr)return 0;
	down(x);
	return qry(lc,ql,qr,k)+qry(rc,ql,qr,k);
}
#undef l
#undef r
signed main(){
	scanf("%d%d",&n,&m);
	pre();
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while(m--){
		char op=getchar();
		while(op!='?'&&op!='=')
			op=getchar();
		if(op=='='){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			upd(1,l,r,x);
		}else{
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			mint a=(1-l),ans=0,kk=1;
			for(int i=0;i<=k;i++)
				ans+=c[k][i]*qry(1,l,r,k-i)*kk,kk*=a;
			printf("%d\n",ans);
		}
	}
}