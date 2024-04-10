#include <cstdio>
#include <vector>

char str[20];

std::vector<std::pair<int,int> > ans;

void check(int r,int c){
  for(int i=0;i<c;i++){
    bool good=true;
    for(int j=i;j<r*c;j+=c){
      if(str[j]!='X') good=false;
    }
    if(good){
      ans.emplace_back(r,c);
      return;
    }
  }
}

int main(){
  int T;
  scanf("%d",&T);
  for(int t=0;t<T;t++){
    ans.clear();
    scanf("%s",str);
    check(1,12);
    check(2,6);
    check(3,4);
    check(4,3);
    check(6,2);
    check(12,1);
    printf("%d",(int)ans.size());
    for(auto pair:ans){
      printf(" %dx%d",pair.first,pair.second);
    }
    printf("\n");
  }
  return 0;
}