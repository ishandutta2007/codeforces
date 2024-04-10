#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define inf 1234567890987654321
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct BIT{
	int tree[262144],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=262143;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
	int find(int x){
		int pos=0;
		for (int i=17;i>=0;i--)
			if (x>=tree[pos+(1<<i)])x-=tree[pos+(1<<i)],pos+=(1<<i);
		pos++;
		return pos;
	}
}f[20],g[20];
struct SGT{
	int tree[1048576],tag[1048576];
	SGT(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	void pushup(int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	void pushdown(int now){
		if (tag[now]==0)return;
		tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	void upd(int now,int nowl,int nowr,int lt,int rt,int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)upd(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)upd(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	int find(int now,int nowl,int nowr,int lt,int rt,int val){
		if (nowl!=nowr)pushdown(now);
		if (tree[now]>val)return 262143;
		if (nowl==nowr)return nowl;
		int mid=(nowl+nowr)/2;
		if (nowl>=lt&&nowr<=rt){
			if (tree[now*2]<=val)return find(now*2,nowl,mid,lt,rt,val);
			return find(now*2+1,mid+1,nowr,lt,rt,val);
		}
		int ans=262143;
		if (mid>=lt)ans=find(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt&&ans==262143)ans=find(now*2+1,mid+1,nowr,lt,rt,val);
		return ans;
	}
}h[20];
int n,q,opt,x,y;
struct node{
	int a,b,c,id;
	bool operator <(const node &x)const{
		if (b!=x.b)return b>x.b;
		return a<x.a;
	}
}qwq[200005];
int pos[200005],a[200005],v[200005],c[200005];
signed main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)qwq[i].c=read(),qwq[i].a=read(),qwq[i].b=read(),qwq[i].id=i;
	sort(qwq+1,qwq+1+n);
	for (int i=1;i<=n;i++){
		pos[qwq[i].id]=i;
		a[i]=qwq[i].a,v[i]=qwq[i].b,c[i]=qwq[i].c;
	}
	n++;
	a[n]=1,v[n]=0,c[n]=inf;
	for (int w=0;w<20;w++){
		int sum=0;
		for (int i=1;i<=n;i++){
			if (a[i]<(1<<w))sum+=a[i]*c[i],f[w].add(i,a[i]*c[i]),g[w].add(i,v[i]*c[i]),h[w].upd(1,1,n,i,i,inf);
			else{
				h[w].upd(1,1,n,i,i,a[i]+sum);
				if (c[i]==0)h[w].upd(1,1,n,i,i,inf);
			}
		}
	}
	while(q--){
		opt=read();
		if (opt==1){
			y=read(),x=read();
			x=pos[x];
			for (int w=0;w<20;w++){
				if (a[x]<(1<<w))f[w].add(x,a[x]*y),g[w].add(x,v[x]*y),h[w].upd(1,1,n,x,n,a[x]*y);
				else if (c[x]==0)h[w].upd(1,1,n,x,x,-inf);
			}
			c[x]+=y;
		}
		if (opt==2){
			y=read(),x=read();
			x=pos[x];
			c[x]-=y;
			for (int w=0;w<20;w++){
				if (a[x]<(1<<w))f[w].add(x,-a[x]*y),g[w].add(x,-v[x]*y),h[w].upd(1,1,n,x,n,-a[x]*y);
				else if (c[x]==0)h[w].upd(1,1,n,x,x,inf);
			}
		}
		if (opt==3){
			x=read();
			int p=0,ans=0;
			for (int w=19;w>=0&&x>0;w--){
				int p1=h[w].find(1,1,n,p+1,n,x+f[w].ask(p)),p2=f[w].find(x+f[w].ask(p));
				if (p1<p2){
					x-=f[w].ask(p1-1)-f[w].ask(p);
					ans+=g[w].ask(p1-1)-g[w].ask(p);
					int t=min(c[p1],x/a[p1]);
					ans+=t*v[p1];
					x-=t*a[p1];
					p=p1;
				}
				else{
					x-=f[w].ask(p2-1)-f[w].ask(p);
					ans+=g[w].ask(p2-1)-g[w].ask(p);
					int t=min(c[p2],x/a[p2]);
					ans+=t*v[p2];
					x-=t*a[p2];
					p=p2;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}