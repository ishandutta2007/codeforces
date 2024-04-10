#include<bits/stdc++.h>
#define pb push_back
#define N 100005
using namespace std;
const int block=350;
vector<int>vec[N],Q[N],a[N],G[N];
int L[N],R[N],O[N],dfn[N];
int all[N],self[N],st[N],ed[N],be[N],T,number;
int son[N][26],fail[N],q[N],root=1,tot=1;
int n,m,i,p,Case,k,id;string s[N];
long long sum[N],ans[N];
void Insert(string s,int id){
	int p=1;
	for (int i=0;i<s.length();i++){
		int &v=son[p][s[i]-'a'];
		if (!v) v=++tot;p=v;
  }vec[p].pb(id);
}
void ACbuild(){
	int h=0,t=0;
	for (int i=0;i<26;i++)
		if (!son[1][i]) son[1][i]=1;else fail[q[++t]=son[1][i]]=1;
	while (h<t){
		int k=q[++h];
		for (int i=0;i<26;i++)
			if (!son[k][i]) son[k][i]=son[fail[k]][i];
			else fail[q[++t]=son[k][i]]=son[fail[k]][i];
	}for (int i=2;i<=tot;i++) a[fail[i]].pb(i);
}
int DFS(int x){
	int size=(dfn[x]==Case);
	for (int i=0;i<a[x].size();i++)
		size+=DFS(a[x][i]);
	for (int i=0;i<vec[x].size();i++)
		sum[vec[x][i]]+=size;
	return size;
}
void Insert(int x,int sign){
	for (int i=x;i<=ed[be[x]];i++)
		self[i]+=sign;
	for (int i=be[x]+1;i<=T;i++)
		all[i]+=sign;
}
inline int Query(int x){return all[be[x]]+self[x];}
void CALC(int x){
	for (int i=0;i<vec[x].size();i++)
		Insert(vec[x][i],1);
	for (int i=0;i<G[x].size();i++){
		id=G[x][i];
		ans[id]+=Query(R[id])-Query(L[id]-1);
  }
	for (int i=0;i<a[x].size();i++)
		CALC(a[x][i]);
	for (int i=0;i<vec[x].size();i++)
		Insert(vec[x][i],-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		cin>>s[i],Insert(s[i],i);
	ACbuild();
	for (i=1;i<=m;i++){
		scanf("%d%d%d",&L[i],&R[i],&O[i]);id=O[i];
		if (s[id].length()>block) Q[id].pb(i);
		else 
			for (p=root,k=0;k<s[id].length();k++)
				p=son[p][s[id][k]-'a'],G[p].pb(i);
	}
	//bigger than block
	for (i=1;i<=n;i++)
		if (!Q[i].empty()){
			++Case;for (k=1;k<=n;k++) sum[k]=0;
			for (p=root,k=0;k<s[i].length();k++)
				p=son[p][s[i][k]-'a'],dfn[p]=Case;
			DFS(1);
			for (k=1;k<=n;k++) sum[k]+=sum[k-1];
			for (k=0;k<Q[i].size();k++)
				id=Q[i][k],ans[id]=sum[R[id]]-sum[L[id]-1];
		}
	//smaller than block
	number=sqrt(n);
	for (i=1;i<=n;i+=number){
		st[++T]=i;
		ed[T]=min(n,i+number-1);
		for (k=st[T];k<=ed[T];k++)
			be[k]=T;
	}
	CALC(1);
	for (i=1;i<=m;i++)
		printf("%I64d\n",ans[i]);
}