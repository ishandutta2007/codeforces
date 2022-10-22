#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1010;
struct edge{
	int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
	e[++len]={head[x],y};
	head[x]=len;
}
int is[maxn],s[maxn];
void dfs(int now,int fa){
	int w=0;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		dfs(u,now);w++;
		s[now]+=is[u];
	}
	if(!w)is[now]=1;
}
int i,j,k,n,m,T;
int main(){
	cin>>n;
	for(i=1;i<n;i++){
		int x=read();
		add(x,i+1);
		add(i+1,x);
	}dfs(1,0);
	for(i=1;i<=n;i++){
		if(!is[i] && s[i]<3){
			puts("NO");
			return 0;
		}
	}puts("YES");
	return 0;
}