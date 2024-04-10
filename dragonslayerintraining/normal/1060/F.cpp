#include <cstdio>
#include <vector>

std::vector<int> edges[64];
int size[64];
double f[64][64];
double g[64][64];

double factorial[101]={1};

double combo(int a,int b){
  return 1.0*factorial[a+b]/factorial[a]/factorial[b];
}

void dfs(int node,int parent){
  size[node]=0;
  f[node][0]=1;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
    for(int a=0;a<=size[node];a++){
      for(int b=0;b<=size[child];b++){
	g[node][a+b]+=combo(a,b)*combo(size[node]-a,size[child]-b)*f[node][a]*g[child][b];
      }
    }
    size[node]+=size[child];
    for(int a=0;a<=size[node];a++){
      f[node][a]=g[node][a];
      g[node][a]=0;
    }
  }
  size[node]++;
  for(int level=0;level<=size[node];level++){
    for(int e=0;e<size[node];e++){
      if(e<level){
	g[node][level]+=f[node][level-1];
      }else{
	g[node][level]+=0.5*f[node][e];
      }
    }
  }
  /*
  for(int level=0;level<=size[node];level++){
    printf("f[%d][%d]=%.10f\n",node,level,f[node][level]);
  }
  for(int level=0;level<=size[node];level++){
    printf("g[%d][%d]=%.10f\n",node,level,g[node][level]);
  }
  */
}

int main(){
  for(int i=1;i<=100;i++){
    factorial[i]=factorial[i-1]*i;
  }
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<=N+5;j++){
      for(int k=0;k<=N+5;k++){
	f[j][k]=g[j][k]=0;
      }
    }
    dfs(i,i);
    printf("%.10lf\n",f[i][0]/factorial[N-1]);
  }
  return 0;
}