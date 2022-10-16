#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define mod 1000000007
#define int long long
using namespace std;
int n,l[100005],r[100005],len[100005],slen=1;
vector <int>c[100005],d[100005];
int u[200005],v[200005],first[100005],nxt[200005];
int depth[100005],fa[100005],size[100005],son[100005],top[100005],id[100005],idx,tree[100005];
int val1,val2,val3,val4,ans;
inline void upd(register int &x){
	if (x>=mod)x-=mod;
	return;
}
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(register int x){
	return Qpow(x,mod-2);
}
struct SGT{
	int tree[400005],tag[400005],maxn;
	SGT(){
		maxn=100000;
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	inline void pushup(register int now){
		tree[now]=tree[now*2]+tree[now*2+1];
		upd(tree[now]);
		return;
	}
	inline void pushdown(register int now,register int nowl,register int nowr){
		register int mid=(nowl+nowr)/2;
		tree[now*2]+=tag[now]*(mid-nowl+1)%mod,tree[now*2+1]+=tag[now]*(nowr-mid)%mod;
		upd(tree[now*2]),upd(tree[now*2+1]);
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		upd(tag[now*2]),upd(tag[now*2+1]);
		tag[now]=0;
		return;
	}
	inline void update(register int now,register int nowl,register int nowr,register int lt,register int rt,register int val){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val*(nowr-nowl+1)%mod;
			tag[now]+=val;
			upd(tree[now]),upd(tag[now]);
			return;
		}
		register int mid=(nowl+nowr)/2;
		if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	inline int query(register int now,register int nowl,register int nowr,register int lt,register int rt){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		register int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s+=query(now*2,nowl,mid,lt,rt);
		if (mid+1<=rt)s+=query(now*2+1,mid+1,nowr,lt,rt);
		upd(s);
		return s;
	}
}sgt;
inline void add(register int pos,register int val){
	val=(val+mod)%mod;
	while(pos){
		sgt.update(1,1,100000,id[top[pos]],id[pos],val);
		pos=fa[top[pos]];
	}
	return;
}
inline int ask(register int pos){
	register int ans=0;
	while(pos){
		ans+=sgt.query(1,1,100000,id[top[pos]],id[pos]);
		upd(ans);
		pos=fa[top[pos]];
	}
	return ans;
}
inline void ins(register int pos){
	register int invlen=inv(len[pos]);
	val1+=depth[pos]*slen%mod*invlen%mod*val4%mod;
	val1+=val3*invlen%mod;
	val1%=mod;
	val3+=depth[pos]*slen%mod*invlen%mod;
	val3%=mod;
	val4+=invlen;
	val4%=mod;
	val2+=slen*invlen%mod*ask(pos)%mod;
	val2%=mod;
	add(pos,invlen);
	return;
}
inline void del(register int pos){
	register int invlen=inv(len[pos]);
	val3-=depth[pos]*slen%mod*invlen%mod;
	val3+=mod,val3%=mod;
	val4-=invlen;
	val4+=mod,val4%=mod;
	val1-=depth[pos]*slen%mod*invlen%mod*val4%mod;
	val1+=mod,val1%=mod;
	val1-=val3*invlen%mod;
	val1+=mod,val1%=mod;
	add(pos,-invlen);
	val2-=slen*invlen%mod*ask(pos)%mod;
	val2+=mod,val2%=mod;
	return;
}
inline void dfs1(register int now,register int f,register int d){
	fa[now]=f,depth[now]=d,size[now]=1;
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs1(v[i],now,d+1);
		size[now]+=size[v[i]];
		if (size[v[i]]>size[son[now]])son[now]=v[i];
	}
	return;
}
inline void dfs2(register int now,register int f,register int t){
	id[now]=++idx,top[now]=t;
	if (son[now]!=0)dfs2(son[now],now,t);
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f&&v[i]!=son[now])dfs2(v[i],now,v[i]);
	return;
}
signed main(){
	cin>>n;
	for (register int i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		c[l[i]].push_back(i),d[r[i]+1].push_back(i);
		len[i]=r[i]-l[i]+1;
		slen=slen*len[i]%mod;
	}
	for (register int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	for (register int i=1;i<=100000;i++){
		for (register int j=0,len=c[i].size();j<len;j++)ins(c[i][j]);
		for (register int j=0,len=d[i].size();j<len;j++)del(d[i][j]);
		ans=(ans+val1-val2*2%mod+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}