#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,ver[N*2],nxt[N*2],head[N],tot,d[N];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;d[y]++;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	bool flag=1;
	for(int i=1;i<=n;i++)if(d[i]==2)flag=0;
	puts(flag?"YES":"NO");
	return 0;
}