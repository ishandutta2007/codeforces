#include <cstdio>
#include <set>

struct Score{
  std::multiset<int> low,high;
  int score;
  Score():score(0){
  }
  void insert(int a){
    if(!low.empty()&&a<=*low.rbegin()){
      low.insert(a);
    }else{
      high.insert(a);
      score+=a;
    }
    int target=(low.size()+high.size())/4;
    while(low.size()<target){
      int x=*high.begin();
      low.insert(x);
      high.erase(high.find(x));
      score-=x;
    }
    while(low.size()>target){
      int x=*low.rbegin();
      high.insert(x);
      low.erase(low.find(x));
      score+=x;
    }
  }
};

void solve(){
  struct Score you,other;
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    you.insert(A);
  }
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    other.insert(A);
  }
  int cnt=0;
  //printf("%d rounds: %d vs %d\n",cnt,you.score,other.score);
  while(you.score<other.score){
    you.insert(100);
    other.insert(0);
    cnt++;
    //printf("%d rounds: %d vs %d\n",cnt,you.score,other.score);
  }
  printf("%d\n",cnt);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}