#include <cstdio>
#include <algorithm>
#include <array>
#include <cstring>

int as[1000][1000];
int bs[1000][1000];

char str[100005];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&as[i][j]);
      as[i][j]--;
    }
  }
  int trans[4][4]={{1,0,0,0},
		   {0,1,0,0},
		   {0,0,1,0},
		   {0,0,0,1}};
  const char ops_s[]="RLDUIC";
  int ops[6][4][4]={{{1,0,0,0},
		     {0,1,0,1},
		     {0,0,1,0},
		     {0,0,0,1}},
		    {{1,0,0,0},
		     {0,1,0,-1},
		     {0,0,1,0},
		     {0,0,0,1}},
		    {{1,0,0,1},
		     {0,1,0,0},
		     {0,0,1,0},
		     {0,0,0,1}},
		    {{1,0,0,-1},
		     {0,1,0,0},
		     {0,0,1,0},
		     {0,0,0,1}},
		    {{1,0,0,0},
		     {0,0,1,0},
		     {0,1,0,0},
		     {0,0,0,1}},
		    {{0,0,1,0},
		     {0,1,0,0},
		     {1,0,0,0},
		     {0,0,0,1}}};
  scanf("%s",str);
  for(int l=0;str[l];l++){
    int tmp[4][4]={};
    auto op=ops[std::find(ops_s,ops_s+6,str[l])-ops_s];
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
	for(int k=0;k<4;k++){
	  tmp[i][k]=(tmp[i][k]+(op[i][j]+N)*trans[j][k])%N;
	}
      }
    }
    memcpy(trans,tmp,sizeof tmp);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int in[4]={i,j,as[i][j],1};
      int out[4]={};
      for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	  out[i]=(out[i]+trans[i][j]*in[j])%N;
	}
      }
      bs[out[0]][out[1]]=out[2];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("%d ",bs[i][j]+1);
    }
    printf("\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}