#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int nedge,nxt[500010],n,C,siz[500010],x,y,c[500010],hed[500010],too[500010],w[500010];
bool O[500010],K[500010];
void ae(int x,int y){
	nxt[++nedge]=hed[x];
	hed[x]=nedge;
	too[nedge]=y;
}
void dfs(int x,int l){
	w[x]=(c[x]==C);
	siz[x]=1;
	O[x]=1;
	K[x]=1;
	int t=0;
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		if (!t) t=c[y];
		dfs(y,x);
		siz[x]+=siz[y];
		O[x]&=(O[y]&(c[x]==c[y]));
		K[x]&=O[y];
		w[x]+=w[y];
	}
}
int main(){
	scanf("%d",&n);
	FOR(i,2,n) getint(x),getint(y),ae(x,y),ae(y,x);
	FOR(i,1,n) getint(c[i]);
	C=c[1];
	dfs(1,0);
	FOR(i,1,n)
		if (K[i] && w[1]-w[i]==n-siz[i]){
			printf("YES\n%d\n",i);
			return 0;
		}
	puts("NO");
	return 0;
}