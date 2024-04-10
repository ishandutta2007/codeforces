#include <cstdio>
#include <set>

std::multiset<int> sets[4];
int ps[150000][4];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int d=0;d<4;d++){
      scanf("%d",&ps[i][d]);
      sets[d].insert(ps[i][d]);
    }
  }
  for(int i=0;i<N;i++){
    for(int d=0;d<4;d++){
      sets[d].erase(sets[d].find(ps[i][d]));
    }
    if((*sets[0].rbegin()<=*sets[2].begin())&&
       (*sets[1].rbegin()<=*sets[3].begin())){
      printf("%d %d\n",*sets[0].rbegin(),*sets[1].rbegin());
      return 0;
    }
    for(int d=0;d<4;d++){
      sets[d].insert(ps[i][d]);
    }
  }
  return 0;
}