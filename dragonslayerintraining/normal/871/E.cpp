#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int N,K;
int dist[200][30000];
int know[200];

int root[30000];
int depth[30000];
int atdepth[30001];

std::vector<int> edges[30000];

int height[30000];
std::vector<int> rep[30000];

void fail(){
  printf("-1\n");
  exit(0);
}

int vis[30000];

void verify(int node,int parent,int k,int d){
  if(vis[node]>=k){
    //printf("FAIL: REVISIT\n");
    fail();
  }
  vis[node]=k;
  //printf("VISIT(%d,%d,%d,%d)\n",node,parent,k,d);
  if(dist[k][node]!=d){
    //printf("FAIL: DIST_%d(%d)=%d, not %d\n",k,node,dist[k][node],d);
    fail();
  }
  for(int child:edges[node]){
    if(child!=parent){
      verify(child,node,k,d+1);
    }
  }
}

void add_edge(int x,int y){
  edges[x].push_back(y);
  edges[y].push_back(x);
}

int main(){
  scanf("%d %d",&N,&K);
  for(int k=0;k<K;k++){
    for(int i=0;i<N;i++){
      scanf("%d",&dist[k][i]);
      if(dist[k][i]==0){
	know[k]=i;
      }
    }
  }
  for(int i=0;i<N;i++){
    root[i]=know[0];
    depth[i]=dist[0][i];
  }
  for(int k=1;k<K;k++){
    /*
    printf("\n After %d\n",k);
    for(int i=0;i<N;i++){
      printf("%d\troot=%d\tdepth=%d\n",i,root[i],depth[i]);
    }
    */
    int y=know[k];
    int x=root[y];
    if(x==y){
      continue;
    }
    for(int z=0;z<N;z++){
      if(root[z]==x){
	if(depth[z]+dist[k][z]==depth[y]){
	  if(depth[z]>N){
	    fail();
	  }
	  atdepth[depth[z]]=z;
	}
      }
    }
    for(int i=0;i<depth[y];i++){
      add_edge(atdepth[i],atdepth[i+1]);
    }
    for(int z=0;z<N;z++){
      if(root[z]==x){
	if((depth[z]+dist[k][x]-dist[k][z])/2>N){
	  fail();
	}
	root[z]=atdepth[(depth[z]+dist[k][x]-dist[k][z])/2];
	depth[z]=(depth[z]+dist[k][z]-dist[k][x])/2;
      }
    }
  }
  /*
  printf("\n END\n");
  for(int i=0;i<N;i++){
    printf("%d\troot=%d\tdepth=%d\n",i,root[i],depth[i]);
  }
  */
  for(int i=0;i<N;i++){
    height[root[i]]=std::max(height[root[i]],depth[i]);
  }
  for(int i=0;i<N;i++){
    rep[i].resize(height[i]+1);
  }
  for(int i=0;i<N;i++){
    rep[root[i]][depth[i]]=i;
  }
  for(int i=0;i<N;i++){
    if(depth[i]>0){
      add_edge(i,rep[root[i]][depth[i]-1]);
    }
  }
  /*
  for(int i=0;i<N;i++){
    for(int e:edges[i]){
      printf("%d <=> %d\n",i,e);
    }
  }
  */
  std::fill(vis,vis+N,-1);
  for(int k=0;k<K;k++){
    verify(know[k],know[k],k,0);
  }
  if(*std::min_element(vis,vis+N)<K-1){
    //printf("FAIL: UNVISITED: %ld\n",std::min_element(vis,vis+N)-vis);
    fail();
  }
  for(int i=0;i<N;i++){
    for(int e:edges[i]){
      if(i<e){
	printf("%d %d\n",i+1,e+1);
      }
    }
  }
  
  return 0;
}