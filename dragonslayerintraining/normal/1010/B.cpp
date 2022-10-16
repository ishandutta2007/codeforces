#include <cstdio>
#include <cstdlib>

int query(int y){
  printf("%d\n",y);
  fflush(stdout);
  int ans;
  scanf("%d",&ans);
  if(ans==0||ans==-2) exit(0);
  return ans;
}

int ps[30];

int main(){
  int N,M;
  scanf("%d %d",&M,&N);
  for(int i=0;i<N;i++){
    ps[i]=query(1);
  }
  int low=2,high=M;
  for(int i=0;low<=high;i=(i+1)%N){
    int mid=(low+high)/2;
    int q=ps[i]*query(mid);
    if(q<0){
      high=mid-1;
    }else{
      low=mid+1;
    }
  }
  return 0;
}