#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
#define ll long long
using namespace std;
int n,a[100005],q;
ll l,r,ans;
struct SGT{
	int tree[300005];
	inline void pushup(register int now){
		tree[now]=max(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void tree_update(register int now,register int nowl,register int nowr,register int pos,register int val){
		if (nowl==nowr){
			tree[now]=max(tree[now],val);
			return;
		}
		register int mid=(nowl+nowr)/2;
		if (pos<=mid)tree_update(now*2,nowl,mid,pos,val);
		else tree_update(now*2+1,mid+1,nowr,pos,val);
		pushup(now);
		return;
	}
	inline void update(int pos,int val){
		tree_update(1,1,n,pos,val);
		return;
	}
	inline int tree_query(register int now,register int nowl,register int nowr,register int lt,register int rt){
		if (tree[now]==0)return 0;
		if (nowl>=lt&&nowr<=rt)return tree[now];
		register int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s=max(s,tree_query(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=max(s,tree_query(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	inline int query(register int l,register int r){
		return tree_query(1,1,n,l,r);
	}
}sgt[87];
inline bool isp(register int x){
	for (register int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
inline ll Qpow(register ll a,register int p){
	if (p==0)return 1;
	ll t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline ll inv(register ll x){
	return Qpow(x,mod-2);
}
int p[105],tot;
struct hjt{
	int l,r;
	ll val;
	hjt(){
		l=r=0;
		val=1;
		return;
	}
}tree[8000005];
int last[200005],root[200005],cnt;
inline void update(register int &now,register int nowl,register int nowr,register int pos,register ll val){
	int pre=now;
	now=++cnt;
	tree[now]=tree[pre];
	tree[now].val=tree[now].val*val%mod;
	if (nowl==nowr)return;
	register int mid=(nowl+nowr)/2;
	if (pos<=mid)update(tree[now].l,nowl,mid,pos,val);
	else update(tree[now].r,mid+1,nowr,pos,val);
	return;
}
inline ll query(register int now,register int nowl,register int nowr,register int lt,register int rt){
	if (nowl>=lt&&nowr<=rt)return tree[now].val;
	register int mid=(nowl+nowr)/2;
	register ll s=1;
	if (mid>=lt)s=s*query(tree[now].l,nowl,mid,lt,rt)%mod;
	if (mid+1<=rt)s=s*query(tree[now].r,mid+1,nowr,lt,rt)%mod;
	return s; 
}
inline ll read(){
	register ll x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x; 
} 
inline int Read(){
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x; 
} 
inline void Out(register ll x){
	if (x==0)return;
	Out(x/10);
	putchar(x%10+'0');
	return;
}
inline void out(register ll x){
	if (x==0)puts("0");
	else Out(x),puts("");
	return;
}
ll pw[105][25];
signed main(){
	for (register int i=2;i<=448;i++)
		if (isp(i))p[++tot]=i;
	for (register int i=1;i<=tot;i++){
		pw[i][0]=1;
		for (register int j=1;j<=20;j++)
			pw[i][j]=pw[i][j-1]*p[i]%mod;
	}
	cin>>n;
	for (register int i=1;i<=n;i++){
		a[i]=Read();
		for (register int j=1;j<=tot;j++){
			register int cnt=0;
			while(a[i]%p[j]==0)a[i]/=p[j],cnt++;
			if (cnt>0)sgt[j].update(i,cnt);
		}
	}
	for (int i=n;i>=1;i--){
		root[i]=root[i+1];
		if (a[i]==1)continue;
		update(root[i],1,n,i,a[i]);
		if (last[a[i]])update(root[i],1,n,last[a[i]],inv(a[i]));
		last[a[i]]=i;
	}
	cin>>q;
	while(q--){
		l=read(),r=read();
		l=(l+ans)%n+1,r=(r+ans)%n+1;
		if (l>r)swap(l,r);
		ans=1;
		for (register int i=1;i<=tot;i++){
			int cnt=sgt[i].query(l,r);
			ans=ans*pw[i][cnt]%mod;
		}
		ans=ans*query(root[l],1,n,l,r)%mod;
		out(ans);
	}
	return 0;
}