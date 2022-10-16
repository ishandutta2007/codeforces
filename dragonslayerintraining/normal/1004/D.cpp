#include <cstdio>
#include <cstdlib>
#include <algorithm>

int T;
int freq[1000001];


int N,M,X,Y;

const int INF=1e7;

int ps[4]={0,1,2,3};

bool check(){
  int ds[4]={INF,INF,INF,INF};
  int dl=0;
  int slope=4;
  for(int i=0;i<T;i++){
    //printf("TRY1(%d): %d %d %d %d\n",i,ds[0],ds[1],ds[2],ds[3]);
    int diff=slope-(freq[i+1]-freq[i]);
    if(diff<0) return false;
    while(diff--){
      if(dl==4) return false;
      ds[dl++]=i;
      slope-=2;
    }
    if(i==ds[ps[0]]+ds[ps[1]]) slope++;
    if(i==ds[ps[1]]+ds[ps[2]]) slope++;
    if(i==ds[ps[2]]+ds[ps[3]]) slope++;
    if(i==ds[ps[3]]+ds[ps[0]]) slope++;
  }
  N=ds[ps[0]]+ds[ps[2]]+1;
  M=ds[ps[1]]+ds[ps[3]]+1;
  X=ds[ps[0]]+1;
  Y=ds[ps[1]]+1;
  return slope==0&&dl==4;
}

int main(){
  scanf("%d",&T);
  for(int i=0;i<T;i++){
    int A;
    scanf("%d",&A);
    freq[A]++;
  }
  if(freq[0]==1){
    freq[0]=0;
    do{
      if(check()){
	printf("%d %d\n",N,M);
	printf("%d %d\n",X,Y);
	return 0;
      }
    }while(std::next_permutation(ps,ps+4));
  }
  printf("-1\n");
  return 0;
}