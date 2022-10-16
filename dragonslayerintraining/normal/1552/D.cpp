#include <cstdio>
#include <set>
#include <vector>

std::vector<int> as;

bool search(int i,int sum,int cnt){
  if(i==as.size()){
    return (sum==0)&&cnt!=0;
  }
  return search(i+1,sum,cnt)||
    search(i+1,sum+as[i],cnt+1)||
    search(i+1,sum-as[i],cnt);
}

void solve(){
  int N;
  std::set<int> aset;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A>0){
      aset.insert(A);
    }else if(A<0){
      aset.insert(-A);
    }
  }
  as=std::vector<int>(aset.begin(),aset.end());
  if(as.size()<N||search(0,0,0)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}