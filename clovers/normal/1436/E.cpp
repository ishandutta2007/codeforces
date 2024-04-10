#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=200010;
int first[N],nxt[N],pre[N];

int n,a[N],vis[N];
int mx[N<<2],tag[N<<2];
struct Segment_Tree{
	void pushup(int x){
		mx[x]=max(mx[x<<1],mx[x<<1|1]);
	}
	void pushdown(int x){
		if(tag[x]==-1) return;
		mx[x<<1]=min(tag[x],mx[x<<1]); 
		if(tag[x<<1]!=-1) tag[x<<1]=min(tag[x<<1],tag[x]); else tag[x<<1]=tag[x];
		mx[x<<1|1]=min(tag[x],mx[x<<1|1]); 
		if(tag[x<<1|1]!=-1) tag[x<<1|1]=min(tag[x<<1|1],tag[x]); 
		else tag[x<<1|1]=tag[x];
		tag[x]=-1;
	} 
	void update(int x,int l,int r,int L,int R,int val){
		if(L<=l&&r<=R){
			mx[x]=min(mx[x],val);
			if(tag[x]==-1) tag[x]=val;
			else tag[x]=min(tag[x],val);
			return;
		}
		int mid=(l+r)>>1; pushdown(x);
		if(mid>=L) update(x<<1,l,mid,L,R,val);
		if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
		pushup(x);
	}
	int query(int x,int l,int r,int L,int R){
		if(L>R) return 0;
		if(L<=l&&r<=R) return mx[x];
		int mid=(l+r)>>1,ret=0; pushdown(x);
		if(mid>=L) ret=max(query(x<<1,l,mid,L,R),ret);
		if(mid<R) ret=max(query(x<<1|1,mid+1,r,L,R),ret);
		return ret;
	}
}tree;

void print(){
	for(int i=1;i<=n;i++) cout<<tree.query(1,1,n,i,i)<<" ";
	cout<<endl;
}

int main()
{
	int mxx=0;
	memset(mx,0x3f,sizeof(mx));
	memset(tag,-1,sizeof(tag));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mxx=max(mxx,a[i]);
	for(int i=1;i<=n;i++) first[a[i]]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=first[a[i]]; pre[nxt[i]]=i;
		first[a[i]]=i;
	}
	if(mxx==1){
		puts("1");
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++) tree.update(1,1,n,i,i,i);
	for(int val=1;val<=n+1;val++){
		if(first[val]==0){
			ans++;
			break;
		}
		int flag=0;
		if(first[val]!=1){
			int tmp=tree.query(1,1,n,1,first[val]-1);
			if(tmp>0) flag=1;
			tree.update(1,1,n,1,first[val]-1,0);
		}
		for(int i=first[val];i!=n+1;i=nxt[i]){
			int tmp=tree.query(1,1,n,i+1,nxt[i]-1);
			tree.update(1,1,n,i,nxt[i]-1,i);
			if(tmp>i) flag=1;
		}
		if(!flag) break;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}