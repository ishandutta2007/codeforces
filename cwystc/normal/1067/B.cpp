#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
bool gg;
int son[500010],dep[500010],fa[500010],t,x,y,k,n,d[500010],hed[500010],nxt[500010],nedge,too[500010],rt,RT;
void ae(int x,int y){
	nxt[++nedge]=hed[x];
	hed[x]=nedge;
	too[nedge]=y;
}
void dfs(int x,int l){
	dep[x]=dep[l]+1;
	fa[x]=l;
	if (dep[x]==k*2) t=x;
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		dfs(y,x);
	}
}
void DFS(int x,int l){
	son[x]=0;
	dep[x]=dep[l]+1;
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		++son[x];
		DFS(y,x);
	}
	if (son[x]){
		if (son[x]<3) gg=1;
	}
	else{
		if (dep[x]!=k) gg=1;
	}
}
int main(){
	cin>>n>>k;
	FOR(i,1,n-1){
		getint(x),getint(y);
		ae(x,y),ae(y,x);
		++d[x],++d[y];
	}
	FOR(i,1,n) if (d[i]==1) rt=i;
	dep[0]=-1;
	dfs(rt,0);
	if (!t) return puts("No"),0;
	FOR(i,1,k) t=fa[t];
	RT=t;
	dep[RT]=0;
	DFS(RT,0);
	if (gg) puts("No");
	else puts("Yes");
	return 0;
}