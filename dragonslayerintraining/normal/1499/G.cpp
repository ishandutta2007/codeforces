#include <cstdio>
#include <vector>
#include <cassert>

const int MOD=998244353;

int next[400005];//xor-linked list of edges

std::vector<int> extra;//extra red edges (in cycles)

int match[400005];//other endpoint of path
//inc,flip,color only defined when match is nonzero
int inc[400005];//incident edge
int flip[400005];//increase to hash if colors on path reversed
int color[400005];//0 if red, 1 if blue
int hash;

int edge_id=1;
int edge_hash=2;

int N1,N2;

//x is endpoint of path
//fix color of incident edge to 0 (red)
void fix(int x){
  int y=match[x];
  assert(y);
  assert(match[y]==x);
  if(color[x]){
    hash=(hash+flip[x])%MOD;
    flip[y]=flip[x]=(MOD-flip[x])%MOD;
    color[x]^=1;
    color[y]^=1;
  }
}

//join edges
void join(int e,int f){
  next[e]^=f,next[f]^=e;
}

void link(int x,int y){
  if(match[x]==y){
    fix(x);
    int blue=0;
    for(int p=0,e=inc[x];e!=0;p^=next[e],std::swap(e,p)){
      if(!blue){
	extra.push_back(e);
      }
      blue^=1;
    }
    match[x]=match[y]=0;
  }else if(!match[x]&&!match[y]){
    match[x]=y;
    match[y]=x;
    inc[x]=inc[y]=edge_id;
    flip[x]=flip[y]=edge_hash;
    color[x]=color[y]=1;
  }else if(!match[x]&&match[y]){
    fix(y);
    join(edge_id,inc[y]);
    int z=match[y];
    match[x]=z;
    match[y]=0;
    match[z]=x;
    inc[x]=edge_id;
    flip[x]=flip[z]=(flip[y]+edge_hash)%MOD;
    color[x]=1;
  }else if(match[x]&&!match[y]){
    return link(y,x);
  }else{
    fix(x),fix(y);
    join(edge_id,inc[x]);
    join(edge_id,inc[y]);
    int w=match[x],z=match[y];
    match[x]=match[y]=0;
    match[w]=z,match[z]=w;
    flip[w]=flip[z]=((flip[x]+flip[y])%MOD+edge_hash)%MOD;
  }
  edge_id++;
  edge_hash=edge_hash*2%MOD;
}

void show(){
  std::vector<int> red=extra;
  for(int x=1;x<=N1+N2;x++){
    //smaller endpoint of path
    if(match[x]>x){
      int blue=color[x];
      for(int p=0,e=inc[x];e!=0;p^=next[e],std::swap(e,p)){
	if(!blue){
	  red.push_back(e);
	}
	blue^=1;
      }
    }
  }
  printf("%d",(int)red.size());
  for(int e:red){
    printf(" %d",e);
  }
  printf("\n");
  fflush(stdout);
}

int main(){
  int M;
  scanf("%d %d %d",&N1,&N2,&M);
  while(M--){
    int X,Y;
    scanf("%d %d",&X,&Y);
    link(X,Y+N1);
  }
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int T;
    scanf("%d",&T);
    if(T==1){
      int V1,V2;
      scanf("%d %d",&V1,&V2);
      link(V1,V2+N1);
      printf("%d\n",hash);
      fflush(stdout);
    }else{
      show();
    }
  }
}