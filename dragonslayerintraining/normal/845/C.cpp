#include <cstdio>
#include <map>
#include <vector>

std::map<int,int> delta;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    delta[L]++;
    delta[R+1]--;
  }
  std::vector<std::pair<int,int> > diffs(delta.begin(),delta.end());
  int ac=0;
  for(int i=0;i<diffs.size();i++){
    ac+=diffs[i].second;
    if(ac>2){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}