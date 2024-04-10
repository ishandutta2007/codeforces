#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+4e5;
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){ memset(head,-1,sizeof(head)); top=-1; }
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
int dfn[MAX_N],e[MAX_N],ti=0;
vector<int> pos[MAX_N];
void dfs(int x){

	dfn[x]=++ti;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		dfs(y);
	}
	e[x]=ti;
}
struct BIT{
	int c[MAX_N],top;
	void init(int n){ top=n; }
	void add(int x,int key){
		for(;x<=top;x+=x&-x) c[x]+=key;
	}
	int query(int x){
		int ret=0;
		for(;x;x-=x&-x) ret+=c[x];
		return ret;
	}
}bit;
struct SAM{	
	struct Node{
		int son[26],fail,max;
	}tree[MAX_N];
	int top;
	SAM(){ top=1; memset(tree[1].son,0,sizeof(int)*26); }
	int insert(int p,int c){
		if(tree[p].son[c]==0){
			int x=++top; memset(tree[x].son,0,sizeof(int)*26); 
			tree[x].max=tree[p].max+1;
			for(;tree[p].son[c]==0&&p>0;p=tree[p].fail)
				tree[p].son[c]=x;
			if(p==0) tree[x].fail=1;
			else{
				int t=tree[p].son[c];
				if(tree[t].max==tree[p].max+1) tree[x].fail=t;
				else{
					int q=++top;
					memcpy(tree[q].son,tree[t].son,sizeof(int)*26);
					tree[q].fail=tree[t].fail; tree[t].fail=q;
					tree[x].fail=q; tree[q].max=tree[p].max+1;
					for(;tree[p].son[c]==t&&p>0;p=tree[p].fail)
						tree[p].son[c]=q;
				}
			}
			return x;
		}else{
			int t=tree[p].son[c];
			if(tree[t].max==tree[p].max+1) return t;
			else{
				int q=++top;
				memcpy(tree[q].son,tree[t].son,sizeof(int)*26);
				tree[q].fail=tree[t].fail; tree[t].fail=q;
				tree[q].max=tree[p].max+1;
				for(;tree[p].son[c]==t&&p>0;p=tree[p].fail)
					tree[p].son[c]=q;
				return q;
			}
		}
	}
	void build(){
		for(int i=2;i<=top;++i){
//			printf("(%d %d)",tree[i].fail,i);
			G.add(tree[i].fail,i);
		}
	}
}sam;
struct Key{ int k,id,t; };
vector<Key> q[MAX_N];
vector<int> ans;
int main(){
	char s[MAX_N];
	int n,m,last=1; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		last=1;
		scanf("%s",s);
		int m=strlen(s);
		pos[i].resize(m);
		for(int j=0;j<m;++j){
			pos[i][j]=sam.insert(last,s[j]-'a');
			last=pos[i][j];
//			printf("(%d)",pos[i][j]);
		}
//		puts("");
	}
	sam.build();
//	exit(0);
	dfs(1);
	for(int i=0;i<m;++i){
		int l,r,k; scanf("%d%d%d",&l,&r,&k);
		q[l-1].push_back((Key){pos[k].back(),i,-1});
		q[r].push_back((Key){pos[k].back(),i,1});
	}
	ans.resize(m); bit.init(sam.top);
	for(int i=0;i<=n;++i){
		for(int j=0;j<pos[i].size();++j)
			bit.add(dfn[pos[i][j]],1);
		for(int j=0;j<q[i].size();++j)
			ans[q[i][j].id]+=q[i][j].t
				*(bit.query(e[q[i][j].k])-bit.query(dfn[q[i][j].k]-1));
	}
	for(int i=0;i<m;++i) printf("%d\n",ans[i]);
	return 0;
}