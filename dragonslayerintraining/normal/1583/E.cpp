#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> adj[300005];

int par[300005];
int depth[300005];
bool vis[300005];

int deg[300005];
int qs[300005][2];

void dfs(int x){
  for(int y:adj[x]){
    if(vis[y]) continue;
    vis[y]=true;
    par[y]=x;
    depth[y]=depth[x]+1;
    dfs(y);
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  vis[0]=true;
  par[0]=-1;
  depth[0]=0;
  dfs(0);
  /*
  for(int i=0;i<N;i++){
    printf("depth[%d]=%d\n",i,depth[i]);
  }
  */
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    scanf("%d %d",&qs[i][0],&qs[i][1]);
    qs[i][0]--,qs[i][1]--;
    deg[qs[i][0]]^=1;
    deg[qs[i][1]]^=1;
  }
  int odd=std::count(deg,deg+N,1);
  if(odd==0){
    printf("YES\n");
    for(int i=0;i<Q;i++){
      int a=qs[i][0],b=qs[i][1];
      std::vector<int> pref,suff;
      while(depth[a]>depth[b]){
	pref.push_back(a);
	a=par[a];
	//printf("a=%d\n",a);
      }
      while(depth[a]<depth[b]){
	suff.push_back(b);
	b=par[b];
	//printf("b=%d\n",b);
      }
      while(a!=b){
	pref.push_back(a);
	a=par[a];
	suff.push_back(b);
	b=par[b];
	//printf("a=%d b=%d\n",a,b);
      }
      std::reverse(suff.begin(),suff.end());
      printf("%d\n",(int)(1+pref.size()+suff.size()));
      for(int x:pref){
	printf("%d ",x+1);
      }
      printf("%d",a+1);
      for(int x:suff){
	printf(" %d",x+1);
      }
      printf("\n");
    }
  }else{
    printf("NO\n");
    printf("%d\n",odd/2);
  }
}