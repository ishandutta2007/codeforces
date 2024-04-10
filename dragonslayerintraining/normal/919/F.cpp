#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cassert>
#include <queue>

const int NUM_STATES=495;

#define CELL(i,j) ((i)*NUM_STATES+(j))

std::vector<std::array<int,8> > pos;
int index[5][5][5][5][5][5][5][5];

std::vector<int> edges[NUM_STATES*NUM_STATES];
int deg[NUM_STATES*NUM_STATES];

enum{
  LOOP=0,
  LOSE=1,
  WIN=2,
}game[NUM_STATES*NUM_STATES];

std::ostream& operator<<(std::ostream& out,std::array<int,8> as){
  out<<"[";
  for(int i=0;i<8;i++){
    out<<" "<<as[i];
  }
  return out<<" ]";
}
std::istream& operator>>(std::istream& in,std::array<int,8>& as){
  for(int i=0;i<8;i++){
    in>>as[i];
  }
  return in;
}

int main(){
  for(int a=0;a<5;a++){
    for(int b=a;b<5;b++){
      for(int c=b;c<5;c++){
	for(int d=c;d<5;d++){
	  for(int e=d;e<5;e++){
	    for(int f=e;f<5;f++){
	      for(int g=f;g<5;g++){
		for(int h=g;h<5;h++){
		  std::array<int,8> as({a,b,c,d,e,f,g,h});
		  do{
		    index[as[0]][as[1]][as[2]][as[3]][as[4]][as[5]][as[6]][as[7]]=pos.size();
		  }while(std::next_permutation(as.begin(),as.end()));
		  pos.emplace_back(as);
		}
	      }
	    }
	  }
	}
      }
    }
  }
  assert(pos.size()==NUM_STATES);
  for(int j=0;j<NUM_STATES;j++){
    //std::cout<<j<<std::endl;
    for(int b=0;b<8;b++){
      if(pos[j][b]==0) continue;
      for(int i=0;i<NUM_STATES;i++){
	for(int a=0;a<8;a++){
	  std::array<int,8> p1=pos[i];
	  if(pos[i][a]!=0){
	    //std::cout<<p1<<" "<<pos[j]<<"=>";
	    p1[a]=(p1[a]+pos[j][b])%5;
	    //std::cout<<pos[j]<<" "<<p1<<std::endl;
	    int index2=index[p1[0]][p1[1]][p1[2]][p1[3]][p1[4]][p1[5]][p1[6]][p1[7]];
	    edges[CELL(j,index2)].push_back(CELL(i,j));
	    deg[CELL(i,j)]++;
	  }
	}
      }
    }
  }
  std::queue<int> queue;
  for(int i=1;i<NUM_STATES;i++){
    game[CELL(i,0)]=LOSE;
    queue.push(CELL(i,0));
    game[CELL(0,i)]=WIN;
    queue.push(CELL(0,i));
  }
  while(!queue.empty()){
    int s=queue.front();
    queue.pop();
    if(game[s]==LOSE){
      //std::cout<<pos[s/NUM_STATES]<<" "<<pos[s%NUM_STATES]<<": LOSE"<<std::endl;
      for(int in:edges[s]){
	if(game[in]!=WIN){
	  game[in]=WIN;
	  queue.push(in);
	}
      }
    }else if(game[s]==WIN){
      //std::cout<<pos[s/NUM_STATES]<<" "<<pos[s%NUM_STATES]<<": WIN"<<std::endl;
      for(int in:edges[s]){
	if(--deg[in]==0){
	  game[in]=LOSE;
	  queue.push(in);
	}
      }
    }else{
      assert(false);
    }
  }
  int T;
  std::cin>>T;
  for(int i=0;i<T;i++){
    int F;
    std::array<int,8> p1,p2;
    std::cin>>F;
    std::cin>>p1>>p2;
    int i1=index[p1[0]][p1[1]][p1[2]][p1[3]][p1[4]][p1[5]][p1[6]][p1[7]];
    int i2=index[p2[0]][p2[1]][p2[2]][p2[3]][p2[4]][p2[5]][p2[6]][p2[7]];
    //std::cout<<p1<<" "<<p2<<": "<<game[CELL(i1,i2)]<<std::endl;
    if(F){
      std::swap(i1,i2);
    }
    switch(game[CELL(i1,i2)]){
    case LOSE:std::cout<<(F?"Alice":"Bob")<<std::endl;break;
    case WIN:std::cout<<(F?"Bob":"Alice")<<std::endl;break;
    case LOOP:std::cout<<"Deal"<<std::endl;break;
    }
  }
  return 0;
}