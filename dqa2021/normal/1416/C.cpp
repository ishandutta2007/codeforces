#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
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
typedef long long ll;

int n,a[300010];
struct Node{
	int ch[2];
}node[34*300000];
int idtot=1;
vector<int> e[34*300000];
void ins(int x,int pos){
	int cur=1;
	for (int i=29;~i;i--){
		int id=x>>i&1;
		if (!node[cur].ch[id]) node[cur].ch[id]=++idtot;
		cur=node[cur].ch[id];
	}
	e[cur].pb(pos);
}
ll A[35],B[35];
void dfs(int x,int dep){
	if (!dep) return;
	dep--;
	if (node[x].ch[0]) dfs(node[x].ch[0],dep);
	if (node[x].ch[1]) dfs(node[x].ch[1],dep);
	int L=node[x].ch[0],R=node[x].ch[1];
	e[x].resize(e[L].size()+e[R].size());
	merge(e[L].begin(),e[L].end(),e[R].begin(),e[R].end(),e[x].begin());
	if (!node[x].ch[0]||!node[x].ch[1]) return;
	int pos=0;
	for (int i=0;i<e[L].size();i++){
		while (pos<e[R].size()&&e[R][pos]<e[L][i]) pos++;
		A[dep]+=pos; B[dep]+=e[R].size()-pos;
	}
//	vector<int>().swap(e[L]);
//	vector<int>().swap(e[R]);
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),ins(a[i],i);
	dfs(1,30);
	int X=0; ll res=0;
	for (int i=29;~i;i--){
		if (B[i]<A[i]) X|=1<<i,res+=B[i];
		else res+=A[i];
	}
	printf("%I64d %d\n",res,X);
	return 0;
}