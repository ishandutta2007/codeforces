#include<cstdio>
#include<algorithm>
#include<cctype>
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
typedef long long ll;

int n,p[1000010];
int A[500010],Atot;
int B[500010],Btot;
int lk[1000010],id[500010];
bool vis[1000010];
void dfs(int x,int c){
	vis[x]=1;
	if (!c) A[++Atot]=x;
	else B[++Btot]=x;
	int v=lk[x];
	if (!vis[v]) dfs(v,c^1);
	v=x>n?x-n:x+n;
	if (!vis[v]) dfs(v,c^1);
}
int main()
{
	n=read();
	if (n&1){
		puts("Second");
		fflush(stdout);
		for (int i=1;i<=n+n;i++){
			p[i]=read();
			if (id[p[i]]){
				lk[id[p[i]]]=i,lk[i]=id[p[i]];
			}
			else{
				id[p[i]]=i;
			}
		}
		for (int i=1;i<=n+n;i++) if (!vis[i]) dfs(i,0);
		ll S=0;
		for (int i=1;i<=n;i++) S+=A[i];
		if (S%(n+n)){
			for (int i=1;i<=n;i++) printf("%d ",B[i]);
		}
		else{
			for (int i=1;i<=n;i++) printf("%d ",A[i]);
		}
		puts("");
		fflush(stdout);
		read();
	}
	else{
		puts("First");
		fflush(stdout);
		for (int i=1;i<=n+n;i++) printf("%d ",(i-1)%n+1);
		puts("");
		fflush(stdout);
		read();
	}
	return 0;
}