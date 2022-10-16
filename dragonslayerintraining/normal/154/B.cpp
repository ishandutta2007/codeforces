#include <iostream>
#include <set>

int minfactor[100001];

bool on[100001];

std::set<int> conflict[100001];

void activate(int id){
  if(on[id]){
    std::cout<<"Already on"<<std::endl;
    return;
  }else{
    for(int num=id;num>1;num/=minfactor[num]){
      if(conflict[minfactor[num]].size()>0){
	std::cout<<"Conflict with "<<*(conflict[minfactor[num]].begin())<<std::endl;
	return;
      }
    }
    for(int num=id;num>1;num/=minfactor[num]){
      conflict[minfactor[num]].insert(id);
    }
    on[id]=true;
    std::cout<<"Success"<<std::endl;
  }
}

void deactivate(int id){
  if(!on[id]){
    std::cout<<"Already off"<<std::endl;
    return;
  }else{
    for(int num=id;num>1;num/=minfactor[num]){
      conflict[minfactor[num]].erase(id);
    }
    on[id]=false;
    std::cout<<"Success"<<std::endl;
  }
}

int main(){
  for(int i=2;i<=100000;i++){
    if(minfactor[i]==0){
      for(int k=i;k<=100000;k+=i){
	minfactor[k]=i;
      }
    }
  }
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    std::string op;
    int id;
    std::cin>>op>>id;
    if(op=="+"){
      activate(id);
    }else{
      deactivate(id);
    }
  }
}