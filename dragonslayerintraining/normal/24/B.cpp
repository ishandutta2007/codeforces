#include <iostream>
#include <algorithm>
#include <map>

struct cdriver{
  int score;
  int nth[50];
  std::string name;
  cdriver():score(0){
    for(int i=0;i<50;i++){
      nth[i]=0;
    }
  } 
}drivers[1000];

struct cgoodcmp{
  bool operator()(struct cdriver a,struct cdriver b){
    if(a.score!=b.score){
      return a.score<b.score;
    }
    for(int i=0;i<50;i++){
      if(a.nth[i]!=b.nth[i]){
	return a.nth[i]<b.nth[i];
      }
    }
    return false;
  }
}goodcmp;

struct cbadcmp{
  bool operator()(struct cdriver a,struct cdriver b){
    if(a.nth[0]!=b.nth[0]){
      return a.nth[0]<b.nth[0];
    }
    if(a.score!=b.score){
      return a.score<b.score;
    }
    for(int i=1;i<50;i++){
      if(a.nth[i]!=b.nth[i]){
	return a.nth[i]<b.nth[i];
      }
    }
    return false;
  }
}badcmp;

std::map<std::string,int> idtable;

int getid(std::string name){
  if(idtable.count(name)){
    return idtable[name];
  }
  int id=idtable.size();
  idtable[name]=id;
  drivers[id].name=name;
  return id;
}

const int scores[10]={25,18,15,12,10,8,6,4,2,1};

int main(){
  int T;
  std::cin>>T;
  for(int i=0;i<T;i++){
    int N;
    std::cin>>N;
    for(int j=0;j<N;j++){
      std::string name;
      std::cin>>name;
      if(j<10){
	drivers[getid(name)].score+=scores[j];
      }
      drivers[getid(name)].nth[j]++;
    }
  }
  std::cout<<std::max_element(drivers,drivers+idtable.size(),goodcmp)->name<<std::endl;
  std::cout<<std::max_element(drivers,drivers+idtable.size(),badcmp)->name<<std::endl;
  return 0;
}