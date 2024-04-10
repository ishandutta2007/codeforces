#include <iostream>
#include <map>
#include <algorithm>

struct cqueen{
  int x,y;
  int attacks;
  int id;
}queens[100000];

struct cdircmp{
  int xdir,ydir;
  cdircmp(int xdir,int ydir):xdir(xdir),ydir(ydir){
  }
  int rank(struct cqueen q){
    return q.x*xdir+q.y*ydir;
  }
  bool operator()(struct cqueen q1,struct cqueen q2){
    return rank(q1)<rank(q2);
  }
};

struct cidcmp{
  cidcmp(){
  }
  bool operator()(struct cqueen q1,struct cqueen q2){
    return q1.id<q2.id;
  }
}idcmp;

int N,M;

int byattack[9];

int main(){
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int X,Y;
    std::cin>>X>>Y;
    X--,Y--;
    queens[i].x=X;
    queens[i].y=Y;
    queens[i].attacks=0;
    queens[i].id=i;
  }
  for(int dx=-1;dx<=1;dx++){
    for(int dy=-1;dy<=1;dy++){
      if((dx!=0)||(dy!=0)){
	//std::cout<<"DX="<<dx<<"\t"<<"DY="<<dy<<std::endl;
	struct cdircmp dircmp(dx,dy);
	struct cdircmp dircmp2(dy,-dx);
	std::sort(queens,queens+M,dircmp);
	std::map<int,int> occupied;
	for(int i=0;i<M;i++){
	  struct cqueen& q=queens[i];
	  //std::cout<<"Queen "<<q.id+1<<" encountered"<<std::endl;
	  if(occupied[dircmp2.rank(q)]){
	    //std::cout<<q.id+1<<" attacks"<<std::endl;
	    q.attacks++;
	  }
	  occupied[dircmp2.rank(q)]++;
	}
      }
    }
  }
  std::sort(queens,queens+M,idcmp);
  
  for(int i=0;i<M;i++){
    byattack[queens[i].attacks]++;
  }
  for(int i=0;i<=8;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<byattack[i];
  }
  std::cout<<std::endl;
  return 0;
}