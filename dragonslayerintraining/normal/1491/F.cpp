#include <cstdio>
#include <vector>

int query_range(int l1,int l2,int r1,int r2){
  printf("? %d %d\n",l2-l1,r2-r1);
  for(int i=l1;i<l2;i++){
    if(i>l1) printf(" ");
    printf("%d",i+1);
  }
  printf("\n");
  for(int i=r1;i<r2;i++){
    if(i>r1) printf(" ");
    printf("%d",i+1);
  }
  printf("\n");
  fflush(stdout);
  int F;
  scanf("%d",&F);
  return F;
}

int query(int l1,int l2,int r){
  return query_range(l1,l2,r,r+1);
}

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<int> bad;
  for(int i=1;i<N;i++){
    if(query(0,i,i)){
      //i is good
      //exactly one of 0...i-1 is good
      //binary search to find it
      int l=0,r=i;
      while(r-l>1){
	int m=(l+r)/2;
	if(query(l,m,i)){
	  r=m;
	}else{
	  l=m;
	}
      }
      for(int j=0;j<i;j++){
	if(j!=l){
	  bad.push_back(j);
	}
      }	
      for(int j=i+1;j<N;j++){
	if(!query(j,j+1,i)){
	  bad.push_back(j);
	}
      }
      break;
    }
  }
  printf("! %d",(int)bad.size());
  for(int x:bad){
    printf(" %d",x+1);
  }
  printf("\n");
  fflush(stdout);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}