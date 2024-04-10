#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
ll a[N],b[N];
struct node{
	ll l0,l1,r0,r1,cnt;
	inline node operator +(const node &b)const{
		node res;
		ll w0=min(r0,b.l1),w1=min(r1,b.l0);
		res.cnt=cnt+b.cnt-w0-w1;
		res.l0=l0+b.l0-w1;
		res.l1=l1+b.l1-w0;
		res.r0=r0+b.r0-w0;
		res.r1=r1+b.r1-w1;
		return res;
	}
};
struct sgt{
	int l,r,ls,rs;
	node w;
}s[3*N];
int rt,P;
inline void upd(int p){
	s[p].w=s[s[p].ls].w+s[s[p].rs].w;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		if(a[l]<b[l]) s[p].w.l1=s[p].w.r1=s[p].w.cnt=b[l]-a[l];
		if(a[l]>b[l]) s[p].w.l0=s[p].w.r0=s[p].w.cnt=a[l]-b[l];
		return p;
	}
	int mid=l+r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
node qry(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r)
		return s[p].w;
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid) return qry(s[p].rs,l,r);
	else return qry(s[p].ls,l,mid)+qry(s[p].rs,mid+1,r);
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) cin>>b[i];
	rt=build(1,n);
	while(m--){
		int l,r;cin>>l>>r;
		node w=qry(rt,l,r);
		if(w.l0||w.r1) cout<<-1<<endl;
		else cout<<w.cnt<<endl;
	}
	return 0;
}