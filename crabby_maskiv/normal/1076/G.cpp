#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int M=32;
int n,m,q;
int U;
ll a[N];
struct node{
	int a[M];
	inline node(){
		memset(a,0,sizeof(a));
	}
	inline node operator +(const node &b)const{
		node res;
		for(int i=0;i<(1<<m);i++)
			res.a[i]=a[b.a[i]];
		return res;
	}
};
struct sgt{
	int l,r,ls,rs,tag;
	node w0,w1;
}s[3*N];
int rt,P;
inline void upd(int p){
	s[p].w0=s[s[p].ls].w0+s[s[p].rs].w0;
	s[p].w1=s[s[p].ls].w1+s[s[p].rs].w1;
}
inline void pushd(int p){
	if(!s[p].tag) return;
	swap(s[p].w0,s[p].w1);
	if(s[p].ls) s[s[p].ls].tag^=1;
	if(s[p].rs) s[s[p].rs].tag^=1;
	s[p].tag=0;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		for(int i=0;i<(1<<m)-1;i++) s[p].w0.a[i]=s[p].w1.a[i]=(i<<1&U)|1;
		s[p].w0.a[(1<<m)-1]=U;
		s[p].w1.a[(1<<m)-1]=U^1;
		if(a[l]&1) swap(s[p].w0,s[p].w1);
		return p;
	}
	int mid=l+r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void chg(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r){
		s[p].tag^=1;
		pushd(p);
		return;
	}
	pushd(p);
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid){
		chg(s[p].ls,l,r);
		pushd(s[p].rs);
	}
	else if(l>mid){
		chg(s[p].rs,l,r);
		pushd(s[p].ls);
	}
	else{
		chg(s[p].ls,l,mid);
		chg(s[p].rs,mid+1,r);
	}
	upd(p);
}
node qry(int p,int l,int r){
	pushd(p);
	if(s[p].l==l&&s[p].r==r)
		return s[p].w0;
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid) return qry(s[p].rs,l,r);
	else return qry(s[p].ls,l,mid)+qry(s[p].rs,mid+1,r);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	U=(1<<m)-1;
	rt=build(1,n);
	while(q--){
		int op,l,r;ll d;cin>>op>>l>>r;
		if(op==1){
			cin>>d;
			if(d&1) chg(rt,l,r);
		}
		else{
			node ans=qry(rt,l,r);
			cout<<((ans.a[U]&1)?1:2)<<endl;
		}
	}
	return 0;
}