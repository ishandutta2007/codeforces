#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 233333;
char s[N];
int n,fa[N],q[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x, int y) {
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
void gg() {puts("-1"); exit(0);}
Vi ans[N];
int main() {
	scanf("%s",s+1); n=strlen(s+1);
	rep(i,1,n)fa[i]=i;
	int f=0,r=0;
	rep(i,1,n)
		if (s[i]=='0') q[r++]=i;
		else {if (f==r)gg(); merge(i,q[f++]);}
	f=0;r=0;
	per(i,n,1)
		if (s[i]=='0') q[r++]=i;
		else {if (f==r)gg(); merge(i,q[f++]);}
	rep(i,1,n) ans[find(i)].push_back(i);
	int cnt=0; rep(i,1,n) if (ans[i].size()) cnt++; printf("%d\n",cnt);
	rep(i,1,n) if (ans[i].size()) {
		printf("%d ",ans[i].size()); int len=ans[i].size(); 
		rep(j,0,len-1) printf("%d ",ans[i][j]); puts("");
	}
	return 0;
}