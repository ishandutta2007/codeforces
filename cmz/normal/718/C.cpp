#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=1e5+10;
ll cnt=1,n,m;
ll a[maxn];
inline void ADD(ll &x,ll y){
	(x+=y) >= mod && (x-=mod);
}
struct Matrix{
	ll a[2][2];
	Matrix (){a[0][0]=0; a[0][1]=0; a[1][0]=0; a[1][1]=0;}
	inline ll* operator [] (ll x) {return a[x];}
    inline const ll* operator [] (ll x) const {return a[x];}
	inline friend Matrix operator * (Matrix x,Matrix y){
		Matrix ans;
		for (ll i=0;i<=cnt;++i)
			for (ll j=0;j<=cnt;++j)
				for (ll k=0;k<=cnt;++k) ADD(ans[i][j],x[i][k]*y[k][j]%mod);
		return ans;
	}
	inline friend Matrix operator + (Matrix x,Matrix y){
		Matrix ans;
		for (ll i=0;i<=cnt;++i)
			for (ll j=0;j<=cnt;++j) ADD(ans[i][j],x[i][j]),ADD(ans[i][j],y[i][j]);
		return ans;
	}
	inline friend Matrix operator ^ (Matrix x,ll b){
		Matrix ans; ans[0][0]=1; ans[0][1]=0; ans[1][0]=0; ans[1][1]=1;  
		for (;b;b>>=1,x=x*x) if (b&1) ans=ans*x;
		return ans;
	}
};
Matrix fir,bas,emp;
inline void put(Matrix x){
	printf("----------\n");
	printf("%d %d\n%d %d\n",x[0][0],x[0][1],x[1][0],x[1][1]);
	printf("----------\n");
}
inline void init(){
	bas[0][0]=1; bas[0][1]=1; bas[1][0]=1; bas[1][1]=0;
	fir[0][0]=1; fir[0][1]=1; fir[1][0]=0; fir[1][1]=0;
	emp[0][0]=0; emp[0][1]=0; emp[1][0]=0; emp[1][1]=0;
}
struct seg{
	Matrix tag,num;
}q[maxn*4];
inline void init(Matrix &a){
	a[0][0]=1; a[0][1]=0; a[1][0]=0; a[1][1]=1;  
}
inline bool judge(Matrix a){
	if (a[0][0]!=1) return 0;
	if (a[0][1]!=0) return 0;
	if (a[1][0]!=0) return 0;
	if (a[1][1]!=1) return 0;
	return 1; 
}
inline void pushup(ll now){
	q[now].num=q[now*2].num+q[now*2+1].num;
}
inline void pushdown(ll now){
	if (!judge(q[now].tag)){
		Matrix cur=q[now].tag;
		q[now*2].num=q[now*2].num*cur; q[now*2+1].num=q[now*2+1].num*cur;
		q[now*2].tag=q[now*2].tag*cur; q[now*2+1].tag=q[now*2+1].tag*cur;
		init(q[now].tag);
	}
}
void build(ll now,ll l,ll r){
	init(q[now].tag);
	if (l==r){
		init(q[now].tag); q[now].num=fir*(bas^(a[l]-1));
		return;
	}
	ll mid=(l+r)/2;
	build(now*2,l,mid); build(now*2+1,mid+1,r);
	pushup(now);
	//put(q[now].num);
}
void change(ll now,ll l,ll r,ll cl,ll cr,Matrix k){
	if (r<cl||l>cr) return;
	if (l>=cl&&r<=cr){
		q[now].num=q[now].num*k;
		q[now].tag=q[now].tag*k;
		return;
	}
	pushdown(now);
	ll mid=(l+r)/2;
	change(now*2,l,mid,cl,cr,k); change(now*2+1,mid+1,r,cl,cr,k);
	pushup(now);
}
Matrix query(ll now,ll l,ll r,ll cl,ll cr){
	if (r<cl||l>cr) return emp;
	if (l>=cl&&r<=cr) return q[now].num;
	pushdown(now);
	ll mid=(l+r)/2;
	return query(now*2,l,mid,cl,cr)+query(now*2+1,mid+1,r,cl,cr);
}
int main(){
	//freopen(".in","r",stdin);
	scanf("%lld%lld",&n,&m);
	init();
	for (ll i=1;i<=n;++i) scanf("%lld",&a[i]);
	build(1,1,n); 
	for (ll i=1,opt,l,r,x;i<=m;++i){
		scanf("%lld%lld%lld",&opt,&l,&r);
		if (opt==1){
			scanf("%lld",&x);
			change(1,1,n,l,r,bas^x);
		} else printf("%lld\n",query(1,1,n,l,r)[0][1]%mod);
	}
	return 0;
}