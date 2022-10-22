#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct tree{
	ll t[N<<3];
	#define mid (l+r>>1)
	#define lc (x<<1)
	#define rc (x<<1|1)
	void init(int x,int l,int r){
		t[x]=inf;
		if(l==r)return;
		init(lc,l,mid);
		init(rc,mid+1,r);
	}
	void upd(int x,int l,int r,int pos,ll val){
		t[x]=min(t[x],val);
		if(l==r)return;
		if(pos<=mid)upd(lc,l,mid,pos,val);
		else upd(rc,mid+1,r,pos,val);
	}
	ll qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[x];
		if(qr<=mid)return qry(lc,l,mid,ql,qr);
		else if(mid<ql)return qry(rc,mid+1,r,ql,qr);
		else return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}t1,t2;
int n,a[N],b[N],x[N];
int aa[N],bb[N];
vector<int>num;
ll sum=0;
vector<int>add[N<<1],qry[N<<1];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),x[i]=abs(a[i]-b[i]),num.push_back(a[i]),num.push_back(b[i]),sum+=x[i];
	num.push_back(-998244353);sort(num.begin(),num.end());num.resize(unique(num.begin(),num.end())-num.begin());int tot=num.size()-1;
	//()
	// a,b  MHDDis(a,b)-val[a]-val[b]
	// 
	for(int i=1;i<=n;i++){
		aa[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin();
		bb[i]=lower_bound(num.begin(),num.end(),b[i])-num.begin();
		add[aa[i]].pb(i);qry[bb[i]].pb(i);
	}
	t1.init(1,1,tot);t2.init(1,1,tot);
	//t1t2 
	long long mn=inf;
	for(int i=1;i<=tot;i++){
		for(auto j:add[i]){
			t1.upd(1,1,tot,bb[j],-a[j]-b[j]-x[j]);
			t2.upd(1,1,tot,bb[j],-a[j]+b[j]-x[j]);
		} 
		for(auto j:qry[i]){
			mn=min(mn,b[j]+a[j]+t1.qry(1,1,tot,1,aa[j])-x[j]);
			mn=min(mn,b[j]-a[j]+t2.qry(1,1,tot,aa[j],tot)-x[j]);
		}
	}
	t1.init(1,1,tot);t2.init(1,1,tot);
	for(int i=tot;i>=1;i--){
		for(auto j:add[i]){
			t1.upd(1,1,tot,bb[j],a[j]-b[j]-x[j]);
			t2.upd(1,1,tot,bb[j],a[j]+b[j]-x[j]);
		} 
		for(auto j:qry[i]){
			mn=min(mn,-b[j]+a[j]+t1.qry(1,1,tot,1,aa[j])-x[j]);
			mn=min(mn,-b[j]-a[j]+t2.qry(1,1,tot,aa[j],tot)-x[j]);
		}
	}
	printf("%lld",sum+mn);
}