#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define SZ(x) ((int)x.size())
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 202000;
char s[N];
int ch[N][26],n,k,lst=1,cnt=1,Max[N],fa[N],link[N];
set<int>Set[N];
Vi e[N],pos[N];
inline void ins(int c, int v){
	int p=lst,np=++cnt;lst=np;Max[np]=Max[p]+1;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=ch[p][c];
		if(Max[q]==Max[p]+1)fa[np]=q;
		else{
			int nq=++cnt;Max[nq]=Max[p]+1;
			memcpy(ch[nq],ch[q],104);
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
		}
	}
	Set[np].insert(v); //cerr << v << ' ' << np << endl;
}
inline void dfs(int u){
	int mx=0;
	per(i,SZ(e[u])-1,0){
		dfs(e[u][i]);
		if (!mx||SZ(Set[e[u][i]])>SZ(Set[mx])) mx=e[u][i];
	}
	if(!mx){link[u]=SZ(Set[u])>=k;return;}
	set<int>t=Set[u];Set[u]=Set[mx];Set[mx].clear();while(!t.empty()){
		Set[u].insert(*t.begin());t.erase(t.begin());
	}
	per(i,SZ(e[u])-1,0)if(e[u][i]!=mx)while(!Set[e[u][i]].empty()){
		Set[u].insert(*Set[e[u][i]].begin());Set[e[u][i]].erase(Set[e[u][i]].begin());
	}
	link[u]=SZ(Set[u])>=k; //printf("%d:%d %d\n",u,SZ(Set[u]),link[u]);
}
inline void DFS(int u){
	link[u]=link[u]?u:link[fa[u]]; //printf("%d:%d\n",u,Max[link[u]]);
	per(i,SZ(e[u])-1,0)DFS(e[u][i]);
}
int main() { //freopen("1.in","r",stdin);
	read(n);read(k);
	rep(i,1,n){
		scanf("%s",s+1);int l=strlen(s+1);pos[i].push_back(0);
		lst=1;rep(j,1,l)ins(s[j]-'a',i),pos[i].push_back(lst);
	}
	rep(i,2,cnt)e[fa[i]].push_back(i);
	dfs(1); DFS(1);
	rep(i,1,n){
		int l=SZ(pos[i])-1;ll res=0;
		rep(j,1,l)res+=Max[link[pos[i][j]]];
		printf("%lld ",res);
	}
	
	/*for (int i=1; i<=cnt; i++) {
    	printf("%d : %d %d\n",i,fa[i],Max[i]);
    	for (int j=0; j<=25; j++) if(ch[i][j])
    		printf("ch[%d][%c]=%d\n",i,'a'+j,ch[i][j]);
    }*/
	return 0;
}