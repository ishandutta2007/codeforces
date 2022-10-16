#include <cstdio>
#include <set>
#include <algorithm>

std::pair<int,int> vs[200005];
int bs[200005];

std::multiset<int> diffs;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int B;
    scanf("%d",&B);
    vs[i]=std::pair<int,int>(B,i);
  }
  if(N==2){
    printf("1\n");
    return 0;
  }
  std::sort(vs,vs+N);
  for(int i=0;i<N;i++){
    bs[i]=vs[i].first;
  }
  for(int i=1;i<N;i++){
    diffs.insert(bs[i]-bs[i-1]);
  }
  for(int i=0;i<N;i++){
    if(i>0) diffs.erase(diffs.find(bs[i]-bs[i-1]));
    if(i<N-1) diffs.erase(diffs.find(bs[i+1]-bs[i]));
    if(i>0&&i<N-1) diffs.insert(bs[i+1]-bs[i-1]);
    if(*diffs.begin()==*diffs.rbegin()){
      printf("%d\n",vs[i].second+1);
      return 0;
    }
    if(i>0&&i<N-1) diffs.erase(diffs.find(bs[i+1]-bs[i-1]));
    if(i>0) diffs.insert(bs[i]-bs[i-1]);
    if(i<N-1) diffs.insert(bs[i+1]-bs[i]);
  }
  printf("-1\n");
  return 0;
}