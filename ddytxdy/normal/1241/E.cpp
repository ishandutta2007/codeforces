#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+50;
int t,n,k,ver[N*2],edge[N*2],nxt[N*2],head[N],tot,tp;LL f[N][2];
struct node{
	LL f0,f1,d;
	bool friend operator <(node a,node b){return a.d>b.d;}
}st[N];
void add(int x,int y,int z){ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x,int ff){
	int tt=tp;f[x][0]=f[x][1]=0;
	for(int i=head[x],y;i;i=nxt[i]){
		if((y=ver[i])==ff)continue;
		dfs(y,x);LL f0=max(f[y][1],f[y][0]),f1=f[y][0]+edge[i];
		st[++tp]=(node){f0,f1,f1-f0};
	}
	sort(st+tt+1,st+tp+1);
	int i=tt+1;
	for(;i<=min(tp,tt+k-1);i++){
		if(st[i].d<=0)break;
		f[x][0]+=st[i].f1,f[x][1]+=st[i].f1;
	}
	if(i<=tp){
		f[x][0]+=st[i].f0,f[x][1]+=st[i].f1;i++;
		for(;i<=tp;i++)f[x][0]+=st[i].f0,f[x][1]+=st[i].f0;
	}
	tp=tt;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	dfs(1,0);cout<<max(f[1][0],f[1][1])<<endl;
	for(int i=1;i<=n;i++)head[i]=0;tot=0;
}
int main(){
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}