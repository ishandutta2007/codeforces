#include <cstdio>
#include <vector>
#include <algorithm>

const int INF=2e9;

std::vector<int> row1,row2;

struct State{
  enum Move{
    MOVE_CHANGE,
    MOVE_FIRE,
  }move;
  int r;
  int x;
  struct State* prev;
  State(enum Move move,int r,int x,struct State* prev):
    move(move),r(r),x(x),prev(prev){
  }
};

void recover(struct State* state,std::vector<int>& changes,std::vector<std::pair<int,int> >& fires){
  for(;state!=NULL;state=state->prev){
    switch(state->move){
    case State::MOVE_CHANGE:changes.push_back(state->x);break;
    case State::MOVE_FIRE:fires.emplace_back(state->x,state->r);break;
    }
  }
  std::reverse(changes.begin(),changes.end());
  std::reverse(fires.begin(),fires.end());
}

int main(){
  int N,M1,M2,T;
  scanf("%d %d %d %d",&N,&M1,&M2,&T);
  for(int i=0;i<M1;i++){
    int X;
    scanf("%d",&X);
    row1.push_back(X);
  }
  row1.push_back(N+1);
  for(int i=0;i<M2;i++){
    int X;
    scanf("%d",&X);
    row2.push_back(X);
  }
  row2.push_back(N+1);
  int X=0;
  int i1=0,i2=0;
  std::pair<int,struct State*> states[2]={{T,NULL},{INF,NULL}};
  while(true){
    if(X<std::min(row1[i1],row2[i2])){
      if(std::max(states[0].first,X)<states[1].first){
	states[1]=std::make_pair(std::max(states[0].first,X),new State(State::MOVE_CHANGE,-1,X,states[0].second));
      }
      if(std::max(states[1].first,X)<states[0].first){
	states[0]=std::make_pair(std::max(states[1].first,X),new State(State::MOVE_CHANGE,-1,X,states[1].second));
      }
    }
    X=std::min(row1[i1],row2[i2]);
    //fprintf(stderr,"X=%d\n",X);
    //fprintf(stderr,"Row 1: %d\n",states[0].first);
    //fprintf(stderr,"Row 2: %d\n",states[1].first);
    if(X>N) break;
    //fprintf(stderr,"Next 1: %d\n",row1[i1]);
    //fprintf(stderr,"Next 2: %d\n",row2[i2]);
    if(X==row1[i1]){
      if(states[0].first<X){
	states[0]=std::make_pair(states[0].first+T,new State(State::MOVE_FIRE,1,states[0].first,states[0].second));
      }else{
	states[0]=std::make_pair(INF,(struct State*)NULL);
      }
      if(X!=row2[i2]&&std::max(states[0].first,X)<states[1].first){
	states[1]=std::make_pair(std::max(states[0].first,X),new State(State::MOVE_CHANGE,-1,X,states[0].second));
      }
    }
    if(X==row2[i2]){
      if(states[1].first<X){
	states[1]=std::make_pair(states[1].first+T,new State(State::MOVE_FIRE,2,states[1].first,states[1].second));
      }else{
	states[1]=std::make_pair(INF,(struct State*)NULL);
      }
      if(X!=row1[i1]&&std::max(states[1].first,X)<states[0].first){
	states[0]=std::make_pair(std::max(states[1].first,X),new State(State::MOVE_CHANGE,-1,X,states[1].second));
      }
    }
    if(X==row1[i1]){
      i1++;
    }
    if(X==row2[i2]){
      i2++;
    }
    X++;
  }
  std::vector<int> changes;
  std::vector<std::pair<int,int> > fires;
  if(states[0].first<INF){
    recover(states[0].second,changes,fires);
  }else if(states[1].first<INF){
    recover(states[1].second,changes,fires);
  }else{
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  printf("%d\n",(int)changes.size());
  for(int i=0;i<changes.size();i++){
    if(i>0) printf(" ");
    printf("%d",changes[i]);
  }
  printf("\n");
  printf("%d\n",(int)fires.size());
  for(auto fire:fires){
    printf("%d %d\n",fire.first,fire.second);
  }
  return 0;
}