#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m,len;
int a[N],id[N];
bool cmp(int x,int y){ return a[x]<a[y];}
int w[N];
struct node{
	int lc,rc,mx,len;
	inline node(){}
	inline node(int len,int lc,int rc,int mx):len(len),lc(lc),rc(rc),mx(mx){}
	inline node operator +(const node &b)const{
		node ret;
		if(lc==len) ret.lc=len+b.lc;
		else ret.lc=lc;
		if(b.rc==b.len) ret.rc=b.len+rc;
		else ret.rc=b.rc;
		ret.mx=max(max(mx,b.mx),rc+b.lc);
		ret.len=len+b.len;
		return ret;
	}
};
struct sgt{
	int l,r,ls,rs;
	node w;
}s[60*N];
int rt[N],P;
inline void upd(int p){
	s[p].w=s[s[p].ls].w+s[s[p].rs].w;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(s[p].l==s[p].r){
		s[p].w=node(1,1,1,1);
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
inline int copy(int p){
	int np=++P;
	s[np]=s[p];
	return np;
}
void chg(int p,int pos){
	if(s[p].l==s[p].r){
		s[p].w=node(1,0,0,0);
		return;
	}
	int mid=(s[p].l+s[p].r)>>1;
	if(pos<=mid){
		s[p].ls=copy(s[p].ls);
		chg(s[p].ls,pos);
	}
	else{
		s[p].rs=copy(s[p].rs);
		chg(s[p].rs,pos);
	}
	upd(p);
}
node qry(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r)
		return s[p].w;
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid) return qry(s[p].rs,l,r);
	else return qry(s[p].ls,l,mid)+qry(s[p].rs,mid+1,r);
}
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i],w[i]=a[i];
	sort(w+1,w+n+1);
	len=unique(w+1,w+n+1)-(w+1);
	for(i=1;i<=n;i++) a[i]=lower_bound(w+1,w+len+1,a[i])-w;
	for(i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	rt[0]=build(1,n);
	j=1;
	for(i=1;i<=len;i++){
		rt[i]=copy(rt[i-1]);
		while(j<=n&&a[id[j]]==i)
			chg(rt[i],id[j++]);
	}
	cin>>m;
	while(m--){
		int x,y,z;cin>>x>>y>>z;
		int l=1,r=len;
		while(r>l){
			int mid=(l+r)>>1;
			node c=qry(rt[mid],x,y);
			if(c.mx>=z) l=mid+1;
			else r=mid;
		}
		cout<<w[l]<<endl;
	}
	return 0;
}