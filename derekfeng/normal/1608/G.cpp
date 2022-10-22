#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,q;
int A[400005],N,Aid[400005],pos1[100005],pos2[100005];
vector<pii>tr[600005];
char c[100005];
int sa[400005],rk[400005],lcp[400005];
int st[20][400005],lg[400005];
int hson[100005],dfn[100005],nxt[100005];
int fa[100005],sz[100005],tot;
int ans[100005],L[100005],R[100005];
vector<pii>qry[400005];
vector<pii>v1,v2;
int bit[100005];
struct SuffixArray{
	int m,num[400005],nsa[400005];
	int get(int p,int x){
		return p+x>N?0:rk[p+x];
	}
	void qsort(int x,int *a,int *b,int m){
		memset(num,0,(m+2)<<2);
		for(int i=1;i<=N;i++)num[get(i,x)]++;
		for(int i=1;i<=m;i++)num[i]+=num[i-1];
		for(int i=N;i;i--)b[num[get(a[i],x)]--]=a[i];
	}
	bool cmp(int a,int b,int x){
		if(rk[a]!=rk[b])return rk[a]<rk[b];
		return get(a,x)<get(b,x);
	}
	void solve(){
		int m=27;
		for(int i=1;i<=N;i++)rk[i]=A[i],nsa[i]=i;
		qsort(0,nsa,sa,m);
		num[sa[1]]=m=1;
		for(int i=2;i<=N;i++)m+=cmp(sa[i-1],sa[i],0),num[sa[i]]=m;
		for(int i=1;i<=N;i++)rk[i]=num[i];
		for(int k=1;m<N;k<<=1){
			qsort(k,sa,nsa,m),qsort(0,nsa,sa,m);
			num[sa[1]]=m=1;
			for(int i=2;i<=N;i++)m+=cmp(sa[i-1],sa[i],k),num[sa[i]]=m;
			memcpy(rk+1,num+1,(N+2)<<2);
		}
		for(int i=1;i<=N;i++){
			if(i>1)lg[i]=lg[i>>1]+1;
			if(rk[i]>1){
				lcp[rk[i]]=max(lcp[rk[i-1]],1);
				while(max(i,sa[rk[i]-1])+lcp[rk[i]]-1<=N&&A[i+lcp[rk[i]]-1]==A[sa[rk[i]-1]+lcp[rk[i]]-1])
					lcp[rk[i]]++;
				lcp[rk[i]]--;
			}
		}
		for(int i=1;i<=N;i++)st[0][i]=lcp[i];
		for(int i=1;i<=lg[N];i++)
			for(int j=1;j+(1<<i)-1<=N;j++)
				st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	int qry(int l,int r){
		if(l==r)return N-sa[l]+1;
		if(r<l)swap(l,r);
		int Lg=lg[r-l];
		return min(st[Lg][l+1],st[Lg][r-(1<<Lg)+1]);
	}
}saSolver;
struct Hld{
	void dfs1(int u){
		sz[u]=1;
		for(auto [v,w]:tr[u])if(v!=fa[u]){
			fa[v]=u,dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[hson[u]])hson[u]=v;
		}
	}
	void dfs2(int u){
		dfn[u]=++tot;
		if(hson[u])nxt[hson[u]]=nxt[u],dfs2(hson[u]);
		for(auto [v,w]:tr[u])if(v!=fa[u]&&v!=hson[u])
			nxt[v]=v,dfs2(v);
	}
	void DFS1(int u){
		int W;
		for(auto [v,w]:tr[u]){
			if(v!=fa[u]&&v!=hson[u]){
				DFS1(v);
				A[++N]=w,pos1[dfn[v]]=N;
			}
			if(v==hson[u])W=w;
		}
		if(hson[u]){
			DFS1(hson[u]);
			A[++N]=W,pos1[dfn[hson[u]]]=N;
		}
	}
	void DFS2(int u){
		int W;
		for(auto [v,w]:tr[u])
			if(v==hson[u])W=w;
		if(hson[u]){
			A[++N]=W,pos2[dfn[hson[u]]]=N;
			DFS2(hson[u]);
		}
		for(auto [v,w]:tr[u])
			if(v!=fa[u]&&v!=hson[u]){
				A[++N]=w,pos2[dfn[v]]=N;
				DFS2(v);
			}
	}
	void solve(){
		dfs1(1);
		dfs2(1);
		DFS1(1);
		DFS2(1);
	}
	bool cmp(int l,int r,int a){
		return dfn[l]<=dfn[a]&&dfn[a]<=dfn[r];
	}
	int qry(int u,int v){
		for(;;){
			if(dfn[u]>dfn[v])swap(u,v);
			if(cmp(nxt[v],v,u))return u;
			v=fa[nxt[v]];
		}
	}
	void calc(int u,int t,vector<pii>&v){
		for(;;){
			if(u==t)return;
			if(cmp(nxt[u],u,t)){
				v.push_back({dfn[t]+1,dfn[u]});
				return;
			}
			v.push_back({dfn[nxt[u]],dfn[u]}),u=fa[nxt[u]];;
		}
	}
}hldSolver;
struct BIT{
	void upd(int i){
		for(;i<=m;i+=i&-i)bit[i]++;
	}
	int ask(int i){
		int res=0;
		for(;i;i-=i&-i)res+=bit[i];
		return res;
	}
	int qry(int l,int r){
		return ask(r)-ask(l-1);
	}
}bitSolver;
bool check1(int p,int L,int l,int r,int ld,int rd){
	if(p>rd)return 1;
	if(sa[p]+L>N)return 0;
	p=sa[p]+L;
	int tmp=saSolver.qry(rk[p],rk[l]);
	if(tmp>=r-l+1)return 1;
	return A[p+tmp]>A[l+tmp];
}
bool check2(int p,int L,int l,int r,int ld,int rd){
	if(sa[p]+L>N||p<ld)return 1;
	p=sa[p]+L;
	int tmp=saSolver.qry(rk[p],rk[l]);
	if(tmp>=r-l+1)return 1;
	return A[p+tmp]<A[l+tmp];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++){
		int u,v;char buf[3];
		scanf("%d%d%s",&u,&v,buf);
		buf[0]=buf[0]-'a'+1;
		tr[u].push_back({v,*buf});
		tr[v].push_back({u,*buf});
	}
	for(int i=1;i<=m;i++){
		scanf("%s",c+1);int len=strlen(c+1);
		for(int j=1;j<=len;j++)A[++N]=c[j]-'a'+1,Aid[N]=i;
		A[++N]=27;
	}
	hldSolver.solve();
	saSolver.solve();
	for(int i=1;i<=q;i++){
		int u,v;scanf("%d%d%d%d",&u,&v,&L[i],&R[i]);
		int Lca=hldSolver.qry(u,v);
		v1.clear(),v2.clear();
		hldSolver.calc(u,Lca,v1);
		hldSolver.calc(v,Lca,v2),reverse(v2.begin(),v2.end());
		int L=1,R=N,Len=0,ld,rd;
		for(auto [x,y]:v1){
			int l=pos1[y],r=pos1[y]+(y-x);
			ld=L-1,rd=N+1;
			while(rd>ld+1){
				int md=(ld+rd)>>1;
				if(check1(md,Len,l,r,L,R))rd=md;
				else ld=md;
			}
			int LL=rd;
			ld=0,rd=R+1;
			while(rd>ld+1){
				int md=(ld+rd)>>1;
				if(check2(md,Len,l,r,L,R))ld=md;
				else rd=md;
			}
			int RR=ld;
			L=LL,R=RR;
			if(L>R)break;
			Len+=r-l+1;
		}
		for(auto [x,y]:v2){
			int l=pos2[x],r=pos2[x]+(y-x);
			ld=L-1,rd=N+1;
			while(rd>ld+1){
				int md=(ld+rd)>>1;
				if(check1(md,Len,l,r,L,R))rd=md;
				else ld=md;
			}
			int LL=rd;
			ld=0,rd=R+1;
			while(rd>ld+1){
				int md=(ld+rd)>>1;
				if(check2(md,Len,l,r,L,R))ld=md;
				else rd=md;
			}
			int RR=ld;
			L=LL,R=RR;
			if(L>R)break;
			Len+=r-l+1;
		}
		if(L<=R){
			qry[L-1].push_back({i,-1});
			qry[R].push_back({i,1});
		}
	}
	for(int i=1;i<=N;i++){
		if(Aid[sa[i]])bitSolver.upd(Aid[sa[i]]);
		for(auto [x,c]:qry[i])ans[x]+=c*bitSolver.qry(L[x],R[x]);
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}