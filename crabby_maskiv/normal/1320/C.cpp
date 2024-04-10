#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=200005;
const int M=1000005;
int n,m,k;
int ubx[M],uby[M];
pair<int,ll> a[N],b[N];
struct monster{
	int x,y;ll z;
	bool operator <(const monster &b)const{
		if(ubx[x]==ubx[b.x]) return uby[y]<uby[b.y];
		return ubx[x]<ubx[b.x];
	}
}c[N];
struct sgt{
	int ls,rs,l,r;
	ll mx,tag;
}s[N<<1];
int rt,P;
inline ll get(int p){
	return s[p].mx+s[p].tag;
}
inline void upd(int p){
	s[p].mx=max(get(s[p].ls),get(s[p].rs));
}
inline void pushd(int p){
	s[s[p].ls].tag+=s[p].tag;
	s[s[p].rs].tag+=s[p].tag;
	s[p].mx=get(p);
	s[p].tag=0;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		s[p].mx=-b[l].second;
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void change(int p,int l,int r,ll x){
	if(l>r) return;
	if(s[p].l==l&&s[p].r==r){
		s[p].tag+=x;
		return;
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) change(s[p].ls,l,r,x);
	else if(l>mid) change(s[p].rs,l,r,x);
	else{
		change(s[p].ls,l,mid,x);
		change(s[p].rs,mid+1,r,x);
	}
	upd(p);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	for(i=1;i<=m;i++) cin>>b[i].first>>b[i].second;
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(i=1;i<=k;i++) cin>>c[i].x>>c[i].y>>c[i].z;
	for(i=1;i<=n;i++)
		for(j=a[i-1].first;j<a[i].first;j++)
			ubx[j]=i;
	for(i=1;i<=m;i++)
		for(j=b[i-1].first;j<b[i].first;j++)
			uby[j]=i;
	for(i=a[n].first;i<M;i++) ubx[i]=n+1;
	for(i=b[m].first;i<M;i++) uby[i]=m+1;
	sort(c+1,c+k+1);
	int p=1;
	rt=build(1,m);
	ll ans=-1e18;
	for(i=1;i<=n;i++){
		while(p<=k&&ubx[c[p].x]==i){
			change(rt,uby[c[p].y],m,c[p].z);
			p++;
		}
		ans=max(ans,-a[i].second+get(rt));
	}
	cout<<ans;
	return 0;
}