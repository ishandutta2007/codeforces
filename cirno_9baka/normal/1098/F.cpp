#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=262144;
char pool[256 << 20], *alloc = pool;
// minimal forward_list implementation with static memory allocation
template <class T>
struct flist {
  struct node {
    T val;
    node *nxt;
  };
  node *head;
  // no initalization at global space
  // flist() : head(nullptr) {}
  struct iterator {
    node *ptr;
    iterator() = default;
    iterator(node *p) : ptr(p) {}
    operator T*() { return &ptr->val; }
    bool operator==(const iterator &rhs) const { return ptr == rhs.ptr; }
    bool operator!=(const iterator &rhs) const { return ptr != rhs.ptr; }
    iterator operator++() { ptr = ptr->nxt; return iterator(ptr); }
  };
  iterator begin() { return iterator(head); }
  constexpr iterator end() { return iterator(nullptr); }

  void push(const T &x) {
    node *p = (node *)alloc; alloc += sizeof(node);
    p->val = x; p->nxt = head; head = p;
  }
};

struct SAM{
	int len[N*2],ch[N*2][26],pre[N*2],las=1,k=1,pos[N*2];
	void Insert(int d,int z){
		int x=las;len[++k]=len[las]+1;las=k;pos[k]=z;
		for(;!ch[x][d];x=pre[x])ch[x][d]=las;
		if(!x){pre[las]=1;return;}
		int y=ch[x][d];
		if(len[y]==len[x]+1){pre[las]=y;return;}
		int p=++k;memcpy(ch[p],ch[y],sizeof(ch[p]));
		pre[p]=pre[y];len[p]=len[x]+1;
		pre[y]=pre[las]=p;
		for(;ch[x][d]==y;x=pre[x])ch[x][d]=p;
	}
}A,B;
int tot;
vector<int> g[N*2],g2[N*2];
int n,m,top[N*2],siz[N*2],fa[N*2],son[N*2],idA[N],idB[N],l,r,f[N*2][20],dfn[N*2],lat[N*2];
long long w[N],ans[N],ssw[N];
char c[N];
void dfs(int i,int f){
	fa[i]=f;
	siz[i]=1;
	for(auto it:g[i])
		if(it!=f){
			dfs(it,i);
			siz[i]+=siz[it];
			if(siz[it]>siz[son[i]])
				son[i]=it;
		}
}
void dfs2(int i,int t){
	top[i]=t;
	if(son[i])
		dfs2(son[i],t);
	for(auto it:g[i])
		if(it!=fa[i]&&it!=son[i])
			dfs2(it,it);
}
void dfs3(int i){
	dfn[i]=++tot;
	for(auto it:g2[i])
		dfs3(it);
	lat[i]=tot;
}
struct BIT{
	long long tree[N*2];
	void modify(int i,long long x,int n){
		while(i<=n){
			tree[i]+=x;
			i+=-i&i;
		}
	}
	long long Query(int i){
		long long s=0;
		while(i){
			s+=tree[i];
			i-=-i&i;
		}
		return s;
	}
}X,Y,Z[3];
struct que{
	int l,r,x,ps;
	que(int l,int r,int x,int ps):l(l),r(r),x(x),ps(ps){}
};
vector<que> q[N*2],tq;
struct qq{
	int ps,x;
	long long k;
	qq(int ps,int x,long long k):ps(ps),x(x),k(k){}
};
flist<qq> qu[N];
int FD(int l,int le){
	int x=idA[l];
	for(int i=17;i>=0;--i)
		if(A.len[f[x][i]]>=le)
			x=f[x][i];
	x=max(x,1);
	return x;
}
void cal(int l,int m,int r,int le,int id,int u){
	if(l>n)
		return;
	int x=FD(l,le);
	r=min(r,n);
	if(l<=m){
		qu[l-1].push({x,id+(u+1)*2,1});
		qu[m].push({x,id+(u+1)*2,(long long)-1});
	}
	if(max(l,m+1)<=r){
		qu[max(l,m+1)-1].push({x,id,w[m]});
		qu[r].push({x,id,-w[m]});
	}
}
void Add(int i,int l,int r,int id){
	while(i){
		q[i].emplace_back(l,r,id,i);
		if(l+B.len[i]-1<=r-1){
			int x=FD(l+B.len[i]-1,B.len[i]);
			if(l+B.len[i]-2>0)
				qu[l+B.len[i]-2].push({x,id+m+1,(long long)-1});
			qu[r-1].push({x,id+m+1,1});
		}
		i=top[i];
		i=fa[i];
		if(i)
			cal(l+B.len[i],r,r+B.len[i],B.len[i]+1,id,m);
	}
}
vector<pair<int,int>> tmp;
void Get(int i,int l,bool fl){
	if(B.pos[i]){
		tmp.emplace_back(B.pos[i]+l-1,B.pos[i]);
		Y.modify(B.pos[i],w[B.pos[i]+l-1],n);
	}
	for(auto it:g[i])
		if(fl||it!=son[i])
			Get(it,l,true);
}
void calc(int z){
	tmp.clear();
	tq.clear();
	for(int i=z;i;i=son[i]){
		for(auto it:q[i]){
			tq.push_back(it);
			if(it.r-B.len[it.ps]>=it.l)
				ans[it.x]+=Y.Query(it.r-B.len[it.ps])-Y.Query(it.l-1);
		}
		Get(i,B.len[i],false);
	}
	sort(tmp.begin(),tmp.end());
	sort(tq.begin(),tq.end(),[](que a,que b){return a.r<b.r;});
	for(auto it:tmp){
		X.modify(it.second,1,n);
		Y.modify(it.second,-w[it.first],n);
	}
	int l=0;
	for(auto it:tq){
		while(l<tmp.size()&&tmp[l].first<it.r){
			X.modify(tmp[l].second,-1,n);
			Y.modify(tmp[l].second,w[tmp[l].first],n);
			++l;
		}
		ans[it.x]+=(X.Query(it.r)-X.Query(max(it.l-1,it.r-B.len[it.ps])))*w[it.r];
		ans[it.x]+=Y.Query(it.r)-Y.Query(max(it.l-1,it.r-B.len[it.ps]));
	}
	while(l<tmp.size()){
		X.modify(tmp[l].second,-1,n);
		Y.modify(tmp[l].second,w[tmp[l].first],n);
		++l;
	}
	for(auto it:tmp)
		Y.modify(it.second,-w[it.first],n);
	for(int i=z;i;i=son[i])
		for(auto it:g[i])
			if(it!=fa[i]&&it!=son[i])
				calc(it);
}
int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	scanf("%d",&m);
	for(int i=1;i<=n;++i){
		idA[i]=A.k+1;
		A.Insert(c[i]-'a',i);
	}
	for(int i=n;i>=1;--i){
		idB[i]=B.k+1;
		B.Insert(c[i]-'a',i);
	}
	for(int i=1;i<=n;++i){
		w[i]=1;
		w[i]+=w[i-1];
	}
	for(int i=1;i<=n;++i)
		ssw[i]=ssw[i-1]+w[i];
	for(int i=2;i<=B.k;++i)
		g[B.pre[i]].push_back(i);
	for(int i=2;i<=A.k;++i)
		g2[A.pre[i]].push_back(i);
	for(int i=1;i<=A.k;++i)
		f[i][0]=A.pre[i];
	for(int i=1;i<20;++i)
		for(int j=1;j<=A.k;++j)
			f[j][i]=f[f[j][i-1]][i-1];
	dfs(1,0);
	dfs2(1,1);
	dfs3(1);
	for(int i=1;i<=m;++i){
		scanf("%d %d",&l,&r);
		Add(idB[l],l,r,i);
		ans[i]-=ssw[r-1]-ssw[max(0,l-2)];
	}
	for(int i=1;i<=n;++i){
		Z[0].modify(dfn[idA[i]],1,A.k);
		Z[1].modify(dfn[idA[i]],w[i],A.k);
		Z[2].modify(dfn[idA[i]],w[i-1],A.k);
		for(auto it:qu[i])
			ans[it.x%(m+1)]+=(Z[it.x/(m+1)].Query(lat[it.ps])-Z[it.x/(m+1)].Query(dfn[it.ps]-1))*it.k;
	}
	calc(1);
	for(int i=1;i<=m;++i)
		printf("%lld\n",ans[i]);
}