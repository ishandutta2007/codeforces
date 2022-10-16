#include <cstdio>
#include <vector>

std::vector<int> speed_limit,overtake;

int speed;
int cost=0;

void check_speed_limit(){
  while(speed>speed_limit.back()){
    //printf("IGNORE SL %d\n",speed_limit.back());
    speed_limit.pop_back();
    cost++;
  }
}

void check_overtake(){
  while(overtake.back()==0){
    //printf("IGNORE NO OVETAKE\n");
    overtake.pop_back();
    cost++;
  }
}

int main(){
  speed_limit.push_back(1e9);
  overtake.push_back(1);
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int T,S;
    scanf("%d",&T);
    if(T==1){
      scanf("%d",&S);
      speed=S;
      check_speed_limit();
    }else if(T==2){
      check_overtake();
    }else if(T==3){
      scanf("%d",&S);
      speed_limit.push_back(S);
      check_speed_limit();
    }else if(T==4){
      overtake.push_back(1);
    }else if(T==5){
      speed_limit.push_back(1e9);
      check_speed_limit();
    }else if(T==6){
      overtake.push_back(0);
    }
  }
  printf("%d\n",cost);
  return 0;
}