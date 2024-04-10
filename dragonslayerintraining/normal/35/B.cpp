#include <iostream>
#include <fstream>
#include <map>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::map<std::string,int> shelf;

bool shelves[900];
int N,M;

void add(int x,int y,std::string id){
  for(int i=x*M+y;i<M*N;i++){
    if(!shelves[i]){
      shelves[i]=true;
      shelf[id]=i;
      return;
    }
  }
}

void remove(std::string id){
  if(shelf.count(id)){
    int index=shelf[id];
    shelf.erase(id);
    shelves[index]=false;
    fout<<(index/M)+1<<" "<<(index%M)+1<<std::endl;
  }else{
    fout<<"-1 -1"<<std::endl;
  }
}

int main(){
  int K;
  fin>>N>>M>>K;
  for(int i=0;i<K;i++){
    int type;
    int x,y;
    std::string id;
    fin>>type;
    switch(type){
    case 1:
      fin>>x>>y>>id;
      add(x-1,y-1,id);
      break;
    case -1:
      fin>>id;
      remove(id);
    }
  }
  return 0;
}