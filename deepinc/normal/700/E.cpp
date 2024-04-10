#include<bits/stdc++.h>
using namespace std;
const int S=4e5+5,T=1e7;
char s[S]; int f[S],c[26][S],rt[S],len[S],lst=1,pc=1,F[19][S],tp,n,lc[T],rc[T],ans,lp[S],dp[S];
vector<int>E[S];
#define md (L+R>>1)
void insert(int&p,int x,int L=1,int R=n){
	p=++tp; if(L==R)return;
	if(x<=md)insert(lc[p],x,L,md);else insert(rc[p],x,md+1,R);
}
void extend(int C){
	int p=lst,np=lst=++pc,q,nq; len[np]=len[p]+1;
	insert(rt[np],len[np]); lp[np]=len[np];
	for(;p&&!c[C][p];p=f[p])c[C][p]=np;
	if(!p){f[np]=1;return;}
	if(len[q=c[C][p]]==len[p]+1){f[np]=q;return;}
	len[nq=++pc]=len[p]+1; f[nq]=f[q]; f[np]=f[q]=nq; lp[nq]=lp[q];
	for(int i=0;i<26;++i)c[i][nq]=c[i][q];
	for(;c[C][p]==q;p=f[p])c[C][p]=nq;
}
int merge(int a,int b){
	if(!a||!b)return a|b; int o=++tp;
	lc[o]=merge(lc[a],lc[b]); rc[o]=merge(rc[a],rc[b]); return o;
}
bool ask(int p,int l,int r,int L=1,int R=n){
	if(!p)return 0;if(l<=L&&R<=r)return 1;
	if(l<=md&&ask(lc[p],l,r,L,md))return 1;
	return r>md&&ask(rc[p],l,r,md+1,R);
}
void dfs(int p){
	F[0][p]=f[p]; for(int i=1;i<19;++i)F[i][p]=F[i-1][F[i-1][p]];
	for(auto x:E[p])dfs(x),rt[p]=merge(rt[p],rt[x]);
}
void DFS(int p){
	if(p!=1)for(int i=18,r=p;~i;--i)if(!F[i][r]||ask(rt[F[i][r]],lp[p]-len[p]+len[F[i][r]],lp[p]-1))dp[p]=dp[F[i][r]]+1;else r=F[i][r];
	for(auto x:E[p])DFS(x); ans=max(ans,dp[p]); 
}
int main(){
	scanf("%*d%s",s); n=strlen(s); for(int i=0;s[i];++i)extend(s[i]-97);
	for(int i=2;i<=pc;++i)E[f[i]].push_back(i);
	dfs(1);DFS(1);printf("%d",ans);
}