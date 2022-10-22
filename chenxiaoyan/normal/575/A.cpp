/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=50000,M=50000;
int k,mod;
int n;
int s[N];
int m;
pair<int,int> v[M+1];
vector<pair<int,pair<bool,int> > > v0;
struct matrix{
	int a[2][2];
	int *operator[](int x){return a[x];}
	matrix(int x=0,int y=0,int z=0,int xx=0){
		a[0][0]=x,a[0][1]=y,a[1][0]=z,a[1][1]=xx;
	}
	friend matrix operator*(matrix x,matrix y){
		return matrix((x[0][0]*y[0][0]+x[0][1]*y[1][0])%mod,
		              (x[0][0]*y[0][1]+x[0][1]*y[1][1])%mod,
		              (x[1][0]*y[0][0]+x[1][1]*y[1][0])%mod,
		              (x[1][0]*y[0][1]+x[1][1]*y[1][1])%mod);
	}
	void prt(){printf("%lld %lld\n%lld %lld\n",a[0][0],a[0][1],a[1][0],a[1][1]);}
};
matrix qpow(matrix x,int y){
	matrix res(1,0,0,1);
	while(y){
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
struct segtree{
	struct node{int l,r;matrix v;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define v(p) nd[p].v
	void sprup(int p){v(p)=v(p<<1)*v(p<<1|1);}
	void bld(int l=0,int r=n-1,int p=1){
		l(p)=l;r(p)=r;
		if(l==r)return v(p)=matrix(0,s[l],1,s[(l+1)%n]),void();
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
		sprup(p);
	}
	void init(){bld();}
	void chg(int x,bool y,int v,int p=1){
		if(l(p)==r(p))return v(p)[y][1]=v,void();
		int mid=l(p)+r(p)>>1;
		chg(x,y,v,p<<1|(x>mid));
		sprup(p);
	}
	matrix prod(int l=0,int r=n-1,int p=1){
		if(l>r)return matrix(1,0,0,1);
		if(l<=l(p)&&r>=r(p))return v(p);
		int mid=l(p)+r(p)>>1;
		matrix res(1,0,0,1);
		if(l<=mid)res=res*prod(l,r,p<<1);
		if(r>mid)res=res*prod(l,r,p<<1|1);
		return res;
	}
}segt;
signed main(){
	cin>>k>>mod;
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>v[i].X>>v[i].Y;
	v0.pb(mp(-n,mp(0,0)));v0.pb(mp(inf,mp(0,0)));
	for(int i=1;i<=m;i++){
		v0.pb(mp(v[i].X,mp(0,v[i].Y)));
		if(v[i].X)v0.pb(mp(v[i].X-1,mp(1,v[i].Y)));
	}
	sort(v0.begin(),v0.end());
	segt.init();
	matrix res(1,0,0,1);
	int las=0;
	for(int i=1,ie;i<v0.size();i=ie+1){
		ie=i;while(ie+1<v0.size()&&v0[ie+1].X/n==v0[i].X/n)ie++;
		if(v0[i].X/n>=k/n){las=v0[i-1].X/n;break;}
		res=res*qpow(segt.prod(),v0[i].X/n-1-v0[i-1].X/n);
		for(int j=i;j<=ie;j++)segt.chg(v0[j].X%n,v0[j].Y.X,v0[j].Y.Y);
		res=res*segt.prod();
		for(int j=i;j<=ie;j++)segt.chg(v0[j].X%n,v0[j].Y.X,v0[j].Y.X?s[(v0[j].X+1)%n]:s[v0[j].X%n]);
	}
	res=res*qpow(segt.prod(),k/n-1-las);
	for(int i=0;i<v0.size();i++)if(v0[i].X/n==k/n)segt.chg(v0[i].X%n,v0[i].Y.X,v0[i].Y.Y);
	res=res*segt.prod(0,k%n-1);
	cout<<res[1][0];
	return 0;
}
/*1
7 8
3
1 2 1
2
7 3
5 4
*/