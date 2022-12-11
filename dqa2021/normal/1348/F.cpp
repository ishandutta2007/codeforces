#pragma GCC optimize(2,3,"Ofast")
#pragma GCC optimize("-unroll-loops")

#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
#include<queue>
#include<vector>
#include<cstdlib>
#define forall(x,i) for (int i=0;i<x.size();i++)
#define pb push_back
#define st first
#define nd second
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n; int L[200010],R[200010]; int p[200010],q[200010];
typedef pair<int,int> P;
vector<P> e[200010];
priority_queue<P,vector<P>,greater<P> > que;
set<int> S,T;  //vis  //exst
typedef set<int>::iterator It;
int f[200010];
void dfs(int x,int fa){
	int y=q[x]; f[x]=fa;
	S.erase(x);
	It u=T.lower_bound(L[y]);
	if (u!=T.end()&&*u<=R[y]){
		int v=*u;
		puts("NO");
		for (int i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
		static int r[200010],top;
		for (int j=x;j^v;j=f[j]) r[++top]=j; r[++top]=v;
		for (int i=2;i<=top;i++) p[q[r[i]]]=r[i-1]; p[q[r[1]]]=r[top];
		for (int i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
		exit(0);
	}
	T.insert(x);  //T::erase
	for (u=S.lower_bound(L[y]);u!=S.end()&&*u<=R[y];u=S.lower_bound(L[y])){
		int v=*u; dfs(v,x);
	}
	T.erase(x);
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) L[i]=read(),R[i]=read(),e[L[i]].pb((P){R[i],i});
	for (int i=1;i<=n;i++){
		forall(e[i],j) que.push(e[i][j]);
		P t=que.top(); que.pop();
		p[t.nd]=i; q[i]=t.nd;
	}
	vector<int> tp(n); for (int i=1;i<=n;i++) tp[i-1]=i;
	set<int>(tp.begin(),tp.end()).swap(S);
	while (!S.empty()){
		int u=*S.begin(); dfs(u,0);
	}
	puts("YES");
	for (int i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	return 0;
}