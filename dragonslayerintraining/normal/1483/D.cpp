#include <cstdio>
#include <algorithm>
#include <cassert>

using ll = long long;

const ll INF=1e15+7;

ll ws[605][605];
ll dist[605][605];
ll triple[605][605];

ll need[605][605];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      ws[i][j]=INF;
      dist[i][j]=INF;
    }
  }
  for(int i=0;i<M;i++){
    int U,V,W;
    scanf("%d %d %d",&U,&V,&W);
    U--,V--;
    ws[U][V]=ws[V][U]=W;
    dist[U][V]=dist[V][U]=std::min<ll>(dist[U][V],W);
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  /*
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("dist[%d][%d]=%lld\n",i,j,dist[i][j]);
    }
  }
  */
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int U,V,L;
    scanf("%d %d %d",&U,&V,&L);
    U--,V--;
    triple[U][V]=triple[V][U]=L;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
	triple[i][j]=std::max(triple[i][j],triple[i][k]-dist[j][k]);
      }
    }
  }
  for(int j=0;j<N;j++){
    for(int i=0;i<N;i++){
      for(int k=0;k<N;k++){
	triple[i][j]=std::max(triple[i][j],triple[k][j]-dist[k][i]);
      }
    }
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      assert(triple[i][j]==triple[j][i]);
      //printf("%d-%d: %lld <> %lld\n",i,j,ws[i][j],triple[i][j]);
      if(ws[i][j]<=triple[i][j]){
	cnt++;
      }
    }
  }
  printf("%d\n",cnt);
}