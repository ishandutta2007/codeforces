#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=3e5+50;
int n,ver[N],nxt[N],head[N],tot,a[N],num,x;
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
int dfs(int x){
	int ret;bool flag=0;
	if(a[x])ret=1e9;else ret=0;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];flag=1;
		if(a[x])ret=min(ret,dfs(y));
		else ret+=dfs(y);
	}
	if(!flag)num++,ret=1;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)scanf("%d",&x),add(x,i);
	x=dfs(1);
	printf("%d",num-x+1);
	return 0;
}