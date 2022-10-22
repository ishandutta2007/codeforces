#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,V,res[200004];
ll a[200004],t[200004];
struct info{
	int x,y,id;
};
info v[200004];
bool cmp(info a,info b){
	if(a.x!=b.x)return a.x<b.x;
	if(a.y!=b.y)return a.y<b.y;
	return a.id<b.id;
}
int bit[200004];
void upd(int i,int x){
	for(;i<=n+1;i+=i&-i)bit[i]=max(bit[i],x);
}
int qry(int i){
	int ret=-1e9;
	for(;i;i-=i&-i)ret=max(ret,bit[i]);
	return ret;
}
void clr(int i){
	for(;i<=n+1;i+=i&-i)bit[i]=-1e9;
}
void cdq(int l,int r){
	if(l==r)return;
	int md=(l+r)>>1;
	cdq(l,md);
	vector<info>all;
	for(int i=l;i<=r;i++)all.push_back(v[i]);
	sort(all.begin(),all.end(),cmp);
	for(auto x:all){
		if(x.id<=md)upd(x.y,res[x.id]+1);
		else res[x.id]=max(res[x.id],qry(x.y));
	}
	for(auto x:all)if(x.id<=md)clr(x.y);
	cdq(md+1,r);
}
int main(){
	scanf("%d%d",&n,&V);
	vector<ll>allx,ally;
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<=n;i++){
		t[i]*=V;
		allx.push_back(t[i]+a[i]);
		ally.push_back(t[i]-a[i]);
	}
	sort(allx.begin(),allx.end());
	allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end());
	ally.erase(unique(ally.begin(),ally.end()),ally.end());
	for(int i=0;i<=n;i++){
		ll x=t[i]+a[i],y=t[i]-a[i];
		v[i].id=i,res[i]=-1e9;
		v[i].x=lower_bound(allx.begin(),allx.end(),x)-allx.begin()+1;
		v[i].y=lower_bound(ally.begin(),ally.end(),y)-ally.begin()+1;
	}
	for(int i=1;i<=n+1;i++)bit[i]=-1e9;
	res[0]=0,cdq(0,n);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,res[i]);
	printf("%d",ans);
}