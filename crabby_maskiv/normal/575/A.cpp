#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,mod;
ll k;
struct mat{
	int x[2][2];
	inline mat(){memset(x,0,sizeof(x));}
	inline mat(int a,int b){x[0][0]=a%mod;x[1][0]=b%mod;x[0][1]=1%mod;x[1][1]=0;}
	inline mat operator *(const mat &b)const{
		mat res;
		res.x[0][0]=(1ll*x[0][0]*b.x[0][0]+1ll*x[0][1]*b.x[1][0])%mod;
		res.x[0][1]=(1ll*x[0][0]*b.x[0][1]+1ll*x[0][1]*b.x[1][1])%mod;
		res.x[1][0]=(1ll*x[1][0]*b.x[0][0]+1ll*x[1][1]*b.x[1][0])%mod;
		res.x[1][1]=(1ll*x[1][0]*b.x[0][1]+1ll*x[1][1]*b.x[1][1])%mod;
		return res;
	}
};
inline mat vec(int a,int b){
	mat res;res.x[0][0]=a%mod;res.x[0][1]=b%mod;
	return res;
}
struct sgt{
	int l,r,ls,rs;
	mat w;
}s[N*3];
int rt,P;
int S[N];
inline void upd(int p){
	s[p].w=s[s[p].ls].w*s[s[p].rs].w;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		s[p].w=mat(S[(l-1+n)%n],S[(l-2+n)%n]);
		return p;
	}
	int mid=(s[p].l+s[p].r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
mat qry(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r){
		return s[p].w;
	}
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid)  return qry(s[p].rs,l,r);
	else return qry(s[p].ls,l,mid)*qry(s[p].rs,mid+1,r);
}
map<ll,int> mp;
inline ll getS(ll x){
	if(mp.find(x)!=mp.end()) return mp[x];
	else return S[x%n];
}
int f[N];
inline mat po(mat x,ll k){
	mat res;res.x[0][0]=res.x[1][1]=1%mod;
	while(k){
		if(k&1) res=res*x;
		x=x*x;
		k>>=1;
	}
	return res;
}
int main(){
	int i,j;
	scanf("%lld%d",&k,&mod);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",S+i);
		S[i]%=mod;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		ll x;int v;scanf("%lld%d",&x,&v);v%=mod;
		if(x<k) mp[x]=v;
	}
	mp[k]=0;
	f[0]=0;f[1]=1%mod;
	for(i=2;i<=n;i++) f[i]=(1ll*S[i-1]*f[i-1]+1ll*S[i-2]*f[i-2])%mod;
	if(k<=n){
		printf("%d",f[k]);
		return 0;
	}
	rt=build(0,n-1);
	mat B=s[rt].w;
	ll l=n;mat A=vec(f[n],f[n-1]);
	for(map<ll,int>::iterator it=mp.begin();it!=mp.end();it++){
		ll r=(it->first);
		if(r-l<3){
			for(ll x=l+1;x<=r;x++)
				A=A*mat(getS(x-1),getS(x-2));
		}
		else{
			l++;A=A*mat(getS(l-1),getS(l-2));
			l++;A=A*mat(getS(l-1),getS(l-2));
			if((l+1)/n==r/n){
				A=A*qry(rt,(l+1)%n,r%n);
			}
			else{
				A=A*qry(rt,(l+1)%n,n-1);
				A=A*po(B,r/n-(l+1)/n-1);
				A=A*qry(rt,0,r%n);
			}
		}
		l=r;
	}
	printf("%d",A.x[0][0]);
	return 0;
}