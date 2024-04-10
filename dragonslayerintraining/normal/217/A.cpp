#include <iostream>
#include <set>

int uf[3000];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void merge(int a,int b){
  uf[find(a)]=find(b);
}

std::set<int> used;
std::set<int> components;

int main(){
  for(int i=0;i<3000;i++){
    uf[i]=i;
  }
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int X,Y;
    std::cin>>X>>Y;
    used.insert(X);
    used.insert(Y+1000);
    merge(X,Y+1000);
  }
  for(int x:used){
    components.insert(find(x));
  }
  std::cout<<components.size()-1<<std::endl;
  return 0;
}