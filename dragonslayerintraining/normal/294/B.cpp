#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> thin(1),thick(1);

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int T,W;
    scanf("%d %d",&T,&W);
    if(T==1){
      thin.push_back(W);
    }else{
      thick.push_back(W);
    }
  }
  std::sort(thin.begin(),thin.end());
  std::sort(thick.begin(),thick.end());
  for(int i=1;i<thin.size();i++){
    thin[i]+=thin[i-1];
  }
  for(int i=1;i<thick.size();i++){
    thick[i]+=thick[i-1];
  }
  int best=1e9;
  for(int i=0;i<thin.size();i++){
    for(int j=0;j<thick.size();j++){
      int width=(thin.size()-i-1)+(thick.size()-j-1)*2;
      //fprintf(stderr,"%d thin (%d), %d thick (%d), %d width\n",i,thin[i],j,thick[j],width);
      if(thin[i]+thick[j]<=width){
	best=std::min(best,width);
      }
    }
  }
  printf("%d\n",best);
  return 0;
}