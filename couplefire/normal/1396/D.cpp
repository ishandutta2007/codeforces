#include<bits/stdc++.h>
#define lson now<<1
#define rson now<<1|1
using namespace std;
const int maxn=2009;
const int P=1000000007;

int f[maxn];
int b1[maxn],n1;
int b2[maxn],n2;

struct SegmentTree{
	int l,r;
	long long sum,tag,mn;
}tree[maxn<<2];
void pushup(int now){
	tree[now].sum=tree[lson].sum+tree[rson].sum;
	tree[now].mn=min(tree[lson].mn,tree[rson].mn);
}
void puttag(int now,long long tag){
	tree[now].sum=tag*(b1[tree[now].r]-b1[tree[now].l-1]);
	tree[now].tag=tag;
	tree[now].mn=tag;
}
void pushdown(int now){
	if(tree[now].tag==-1)return;
	puttag(lson,tree[now].tag);
	puttag(rson,tree[now].tag);
	tree[now].tag=-1;
}
void build(int now,int l,int r){
	tree[now].l=l;tree[now].r=r;tree[now].tag=-1;
	if(l==r){
		tree[now].mn=f[l];
		tree[now].sum=1LL*(b1[l]-b1[l-1])*f[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(now);
}
void update(int now,int ll,int rr,int x){
	if(ll>rr)return;
	if(tree[now].mn>=x)return;
	if(tree[now].l>=ll&&tree[now].r<=rr){
		if(tree[now].l==tree[now].r){
			puttag(now,x);return;
		}
		pushdown(now);
		if(tree[rson].mn>=x){
			update(lson,ll,rr,x);
		}else{
			update(rson,ll,rr,x);
			puttag(lson,x);
		}
		pushup(now);
		return;
	}
	pushdown(now);
	int mid=(tree[now].l+tree[now].r)>>1;
	if(ll<=mid)update(lson,ll,rr,x);
	if(rr>mid)update(rson,ll,rr,x);
	pushup(now);
}

int n,K,L;
struct Point{
	int x,y,c;
	void input(){
		cin>>x>>y>>c;
	}
}a[maxn];
int cmpx(Point a,Point b){
	return a.x<b.x;
}

int pre[maxn],nex[maxn];
set<int>S[maxn];
vector<int>G[maxn];

int tong[maxn],cntc;
void insert(int c){
	if(++tong[c]==1)++cntc;
}
void del(int c){
	if(--tong[c]==0)--cntc;
}

Point q[maxn];int nn;

long long ans;
int main(){
	cin>>n>>K>>L;
	for(int i=1;i<=n;++i){
		a[i].input();
		b1[i]=a[i].x;
		b2[i]=a[i].y;
	}
	
	sort(b1+1,b1+1+n);
	n1=unique(b1+1,b1+1+n)-b1-1;
	for(int i=1;i<=n;++i)a[i].x=lower_bound(b1+1,b1+1+n1,a[i].x)-b1;
	
	sort(b2+1,b2+1+n);
	n2=unique(b2+1,b2+1+n)-b2-1;
	for(int i=1;i<=n;++i)a[i].y=lower_bound(b2+1,b2+1+n2,a[i].y)-b2;
	
	b1[0]=b2[0]=-1;b1[n1+1]=L;b2[n2+1]=L;
	for(int i=1;i<=n;++i)G[a[i].y].push_back(i);
	for(int yh=n2;yh>=1;--yh){
		//pre_work
		for(int i=1;i<=K;++i)S[i].clear();
		nn=0;
		for(int t=yh;t>=1;--t){
			for(int i=0;i<G[t].size();++i){
				int id=G[t][i];
				int c=a[id].c;
				auto it=S[c].lower_bound(a[id].x);
				if(it!=S[c].end())nex[id]=*it;
				else nex[id]=n1+1;
				if(*it==a[id].x){
					pre[id]=*it;
				}else if(it!=S[c].begin()){
					pre[id]=*(--it);
				}else{
					pre[id]=0;
				}
			}
			for(int i=0;i<G[t].size();++i){
				int id=G[t][i];
				int c=a[id].c;
				S[c].insert(a[id].x);
				q[++nn]=a[id];
			}
		}
		
		sort(q+1,q+1+nn,cmpx);
		for(int i=1;i<=n1;++i)f[i]=L+1;
		int h=1,t=0;cntc=0;memset(tong,0,sizeof(tong));
		for(int i=1;i<=n1;++i){
			while(q[h].x<i)del(q[h++].c);
			while(cntc<K&&t<=nn)insert(q[++t].c);
			if(t<=nn)f[i]=min(f[i],b1[q[t].x]+1);
		}
		
		
		build(1,1,n1);
		
		int mx=b1[q[nn].x];
		long long tmp=0;
		for(int t=1;t<=yh;++t){
			tmp+=(1LL*(b1[n1]+1)*(L+1)-tree[1].sum)%P*(b2[t]-b2[t-1])%P;
			tmp=tmp%P;
			for(int i=0;i<G[t].size();++i){
				int id=G[t][i];
				update(1,pre[id]+1,a[id].x,b1[nex[id]]+1);
			}
		}
		ans=(ans+tmp*(b2[yh+1]-b2[yh]))%P;
	}
	printf("%lld\n",ans);
	return 0;
}