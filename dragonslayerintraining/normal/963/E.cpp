#include <cstdio>
#include <cassert>
#include <array>

const int MOD=1e9+7;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int id[101][101];
std::array<int,2> where[7854];
int mat[7854][7854];
int cs[7854];
int vars=0;

int modexp(int base,int exp){
  int ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int inverse(int x){
  return modexp(x,MOD-2);
}

void dump(){
  for(int i=0;i<vars;i++){
    for(int k=0;k<vars;k++){
      printf("%d ",mat[i][k]);
    }
    printf("| %d\n",cs[i]);
  }
}

int main(){
  int R,as[4],asum,ps[4];
  scanf("%d %d %d %d %d",&R,&as[0],&as[1],&as[2],&as[3]);
  asum=(0LL+as[0]+as[1]+as[2]+as[3])%MOD;
  for(int d=0;d<4;d++){
    ps[d]=1LL*as[d]*inverse(asum)%MOD;
  }
  for(int x=-R;x<=R;x++){
    for(int y=-R;y<=R;y++){
      if(x*x+y*y<=R*R){
	where[vars]={x,y};
	id[x+50][y+50]=vars++;
      }
    }
  }
  for(int id1=0;id1<vars;id1++){
    mat[id1][id1]=1;
    cs[id1]=1;
    for(int d=0;d<4;d++){
      int x2=where[id1][0]+dx[d];
      int y2=where[id1][1]+dy[d];
      if(x2*x2+y2*y2>R*R) continue;
      int id2=id[x2+50][y2+50];
      mat[id1][id2]=-ps[d];
    }
  }
  for(int i=0;i<vars;i++){
    assert(mat[i][i]);
    int inv=inverse(mat[i][i]);
    for(int j=i+1;j<std::min(vars,i+R*2+1);j++){
      if(mat[j][i]){
	int scale=-1LL*mat[j][i]*inv%MOD;
	for(int k=std::max(0,i-R*2);k<std::min(vars,i+R*2+1);k++){
	  mat[j][k]=(mat[j][k]+1LL*scale*mat[i][k])%MOD;
	}
	cs[j]=(cs[j]+1LL*scale*cs[i])%MOD;
	assert(mat[j][i]==0);
      }
    }
  }
  for(int i=vars-1;i>=0;i--){
    int inv=inverse(mat[i][i]);
    for(int k=std::max(0,i-R*2);k<std::min(vars,i+R*2+1);k++){
      mat[i][k]=1LL*mat[i][k]*inv%MOD;
    }
    cs[i]=1LL*cs[i]*inv%MOD;
    assert(mat[i][i]==1);
    for(int j=i-1;j>=std::max(0,i-R*2-1);j--){
      if(mat[j][i]){
	int scale=-1LL*mat[j][i];
	for(int k=std::max(0,i-R*2);k<std::min(vars,i+R*2+1);k++){
	  mat[j][k]=(mat[j][k]+1LL*scale*mat[i][k])%MOD;
	}
	cs[j]=(cs[j]+1LL*scale*cs[i])%MOD;
      }
    }
  }
  printf("%d\n",(cs[id[50][50]]+MOD)%MOD);
  return 0;
}