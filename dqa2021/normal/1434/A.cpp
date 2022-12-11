#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int a[10];
int n,b[100010];
struct R{
	int i,j,v;
};
bool operator<(R x,R y){return x.v>y.v;}
R c[600010]; int m;
int ans=2e9;

int id[100010];

priority_queue<int> A,B;

int main()
{
	for (int i=1;i<=6;i++) a[i]=read();
	n=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=6;j++)
			c[++m]=(R){i,j,b[i]-a[j]};
	}
	sort(c+1,c+m+1);
	for (int i=1;i<=m;i++){
		int u=c[i].i,v=c[i].j,w=c[i].v;
		if (id[u]) B.push(b[u]-a[id[u]]);
		id[u]=v;
		A.push(b[u]-a[id[u]]);
		if (A.size()-B.size()<n) continue;
		while (!B.empty()&&A.top()==B.top()) A.pop(),B.pop();
		ans=min(ans,A.top()-w);
	}
	printf("%d\n",ans);
	return 0;
}