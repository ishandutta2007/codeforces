#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,q;
ll a[N];
int c[N];
char lz[1<<21];
char mx[1<<21];
int mc[1<<21];
inline void push(int id){
	mx[id*2]^=lz[id];
	lz[id*2]^=lz[id];
	mx[id*2+1]^=lz[id];
	lz[id*2+1]^=lz[id];
	lz[id]=0;
}
inline void upd(int id,int l,int r,int ql,int qr,int v){
	//if(id==1) cout << "upd " << ql << ' ' << qr << ' ' << v << endl;
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		lz[id]^=v;mx[id]^=v;return;
	}
	push(id);
	int mid=(l+r)/2;
	upd(id*2,l,mid,ql,qr,v);
	upd(id*2+1,mid+1,r,ql,qr,v);
	mx[id]=max(mx[id*2],mx[id*2+1]);
	mc[id]=(mx[id*2]==mx[id]?mc[id*2]:0)+(mx[id*2+1]==mx[id]?mc[id*2+1]:0);
}
inline void build(int id,int l,int r){
	if(l==r){
		lz[id]=mx[id]=0;
		mc[id]=1;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	lz[id]=0;
	mx[id]=max(mx[id*2],mx[id*2+1]);
	mc[id]=(mx[id*2]==mx[id]?mc[id*2]:0)+(mx[id*2+1]==mx[id]?mc[id*2+1]:0);
	
}
int s[N],b[N];
int sz,bz;
void in(ll& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
mt19937 rng(228);
vector<pair<pair<int,int>,pair<int,int> > >f[61];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	in(n);
	for(int i=1; i<=n ;i++){
		in(a[i]);
		//a[i]=uniform_int_distribution<ll>(0, 1e18)(rng);
		c[i]=__builtin_popcountll(a[i]);
	}
	a[n+1]=-1;
	a[n+2]=2e18;
	c[n+1]=c[n+2]=-1;
	ll ans=0;
	build(1,1,n);
	for(int i=1; i<=n+2 ;i++){
		//cout << "where" << endl;
		while(sz!=0 && a[s[sz]]>a[i]){
			int r=c[s[sz--]];
			if(r>=0 && r<=60) f[r].push_back({{i,1},{s[sz]+1,s[sz+1]}});;
		}
		if(0<=c[i] && c[i]<=60){
			int r=c[i];
			f[r].push_back({{i,1},{s[sz]+1,i}});
		}
		while(bz!=0 && a[b[bz]]<a[i]){
			int r=c[b[bz--]];
			if(r>=0 && r<=60) f[r].push_back({{i,2},{b[bz]+1,b[bz+1]}});;
		}
		if(0<=c[i] && c[i]<=60){
			int r=c[i];
			f[r].push_back({{i,2},{b[bz]+1,i}});
		}
		s[++sz]=i;b[++bz]=i;
	}
	for(int r=0; r<=60 ;r++){
		//build(1,1,n);
		//cout << "doing " << r << endl;
		for(int i=0; i<f[r].size() ;i++){
			auto c=f[r][i];
			upd(1,1,n,c.se.fi,c.se.se,c.fi.se);
			if(mx[1]==3) ans+=1LL*mc[1]*(f[r][i+1].fi.fi-c.fi.fi);
		}
	}
	cout << ans << '\n';
}