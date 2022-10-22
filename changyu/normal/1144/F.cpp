#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int Maxn=200000;
vector<int>g[Maxn+1];int n,m;
int color[Maxn+1],x[Maxn],y[Maxn];
void ing()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
	  int u,v;scanf("%d%d",&u,&v);
	  x[i]=u,y[i]=v;
	  g[u].push_back(v);g[v].push_back(u);
	}
}
bool paintg(int t,int c){
	color[t]=c;
	for(int i=0;i<g[t].size();i++)
	  if(color[g[t][i]]==c||!color[g[t][i]]&&!paintg(g[t][i],-c))
		return 0;
	return 1;
}
int main(){
	ing();
	memset(color,0,sizeof(color));
	for(int i=0;i<n;i++)
	  if(!color[i]&&!paintg(i,1))
		{puts("NO");return 0;}
	puts("YES");
	for(int i=0;i<m;i++)printf("%d",color[x[i]]==1);
	return 0;
}