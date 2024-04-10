#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>

const int MOD=1e9+7;

int uf[500005];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

//true if successful (not already linked)
bool link(int a,int b){
  a=find(a),b=find(b);
  if(a==b){
    return false;
  }else{
    uf[a]=b;
    return true;
  }
}

int cnt=0;
int pow2_cnt=1;
std::vector<int> S;

void add(int i,int x,int y){
  if(link(x,y)){
    cnt++;
    pow2_cnt=pow2_cnt*2LL%MOD;
    S.push_back(i+1);
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+M+1,0);
  for(int i=0;i<N;i++){
    int K;
    scanf("%d",&K);
    if(K==2){
      int X,Y;
      scanf("%d %d",&X,&Y);
      add(i,X,Y);
    }else{
      int X;
      scanf("%d",&X);
      add(i,X,0);
    }
  }
  printf("%d %d\n",pow2_cnt,cnt);
  for(int i=0;i<S.size();i++){
    if(i) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
}