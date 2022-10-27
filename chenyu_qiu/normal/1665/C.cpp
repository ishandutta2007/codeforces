#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 200020
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
struct edge{int v,ne;}e[maxn];
int tot,lst[maxn],cnt,tmp[maxn];
void add(int u,int v){
	e[tot].v=v,e[tot].ne=lst[u],lst[u]=tot++;
}
void dfs(int u){
	int s=0;
	for(int i=lst[u];~i;i=e[i].ne){
		int v=e[i].v;
		dfs(v);++s;
	}
	if(s)tmp[++cnt]=s;
}
priority_queue<int>q;
int main(){
	int t=getint();
	while(t--){
		int n=getint();
		tot=0;for(int i=1;i<=n;++i)lst[i]=-1;
		for(int i=2;i<=n;++i)add(getint(),i);
		tmp[cnt=1]=1;
		dfs(1);
		sort(tmp+1,tmp+cnt+1);
		while(!q.empty())q.pop();
		for(int i=1;i<=cnt;++i)
		q.push(tmp[cnt-i+1]-1+i);
		int ans=cnt;
		while(1){
			int x=q.top();q.pop();
			if(x<=ans)break;
			++ans;
			q.push(--x);
		}
		printf("%d\n",ans);
	}
	return 0;
}