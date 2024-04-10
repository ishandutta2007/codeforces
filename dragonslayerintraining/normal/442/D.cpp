#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int ps[1000005];
int top[1000005][3];
int colors[1000005];

void update(int node){
  //printf("update(%d)\n",node);
  if(ps[node]==0) return;
  if(colors[node]<colors[top[ps[node]][1]]) return;
  //printf("update'(%d)\n",node);
  int* p=std::find(top[ps[node]],top[ps[node]]+2,node);
  while(p!=top[ps[node]]&&colors[p[-1]]<colors[node]){
    p[0]=p[-1];
    p--;
  }
  //printf("Insert %d into top[%d][%d]\n",node,ps[node],(int)(p-top[ps[node]]));
  *p=node;
  int to=std::max(colors[top[ps[node]][0]],colors[top[ps[node]][1]]+1);
  if(colors[ps[node]]!=to){
    colors[ps[node]]=to;
    update(ps[node]);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  colors[0]=0;
  for(int i=2;i<=N+1;i++){
    scanf("%d",&ps[i]);
    colors[i]=1;
    update(i);
    /*
    for(int j=0;j<=i;j++){
      printf("%d: %d (%d,%d)\n",j,colors[j],top[j][0],top[j][1]);
    }
    */
    printf("%d\n",colors[top[1][0]]);
  }
  return 0;
}