#include <cstdio>
#include <bitset>

const int digits[10]={119, 36, 93, 109, 46, 107, 123, 37, 127, 111};

unsigned char can[1<<7];//(can[mask]>>k)&1: is mask a subset of pattern with k segments lit

std::bitset<2001> add[2001];

int as[2001];

char ans[2001];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    char str[10];
    scanf("%s",str);
    int mask=0;
    for(int k=0;k<7;k++){
      if(str[k]=='1'){
	mask|=1<<k;
      }
    }
    as[i]=mask;
  }
  for(int mask=0;mask<(1<<7);mask++){
    for(int d=0;d<10;d++){
      if((mask&digits[d])==mask){
	can[mask]|=1<<__builtin_popcount(digits[d]);
      }
    }
  }
  add[N].set(0);
  for(int i=N-1;i>=0;i--){
    for(int k=0;k<=7;k++){
      if((can[as[i]]>>k)&1){
	//printf("can add %d segments at %d\n",k-__builtin_popcount(as[i]),i);
	add[i]|=add[i+1]<<(k-__builtin_popcount(as[i]));
      }
    }
  }
  if(!add[0].test(K)){
    printf("-1\n");
    return 0;
  }
  for(int i=0;i<N;i++){
    for(int d=9;d>=0;d--){
      if((as[i]&digits[d])==as[i]){
	int use=__builtin_popcount(as[i]^digits[d]);
	if(K>=use&&add[i+1].test(K-use)){
	  K-=use;
	  ans[i]='0'+d;
	  break;
	}
      }
    }
  }
  ans[N]=0;
  printf("%s\n",ans);
}