#include <iostream>
#include <set>

int N,K;

int a[100000];

struct ctracker{
  std::set<int> single;
  std::multiset<int> all;
  void insert(int n){
    all.insert(n);
    if(all.count(n)==1){
      single.insert(n);
    }else{
      single.erase(n);
    }
  }
  void erase(int n){
    all.erase(all.find(n));
    if(all.count(n)==1){
      single.insert(n);
    }else{
      single.erase(n);
    }
  }
  void query(){
    if(single.empty()){
      std::cout<<"Nothing"<<std::endl;
    }else{
      std::cout<<*single.rbegin()<<std::endl;
    }
  }
};

int main(){
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>a[i];
  }
  struct ctracker t;
  for(int i=0;i<K;i++){
    t.insert(a[i]);
  }
  for(int i=K;;i++){
    t.query();
    t.erase(a[i-K]);
    if(i==N){
      return 0;
    }
    t.insert(a[i]);
  }
  return 0;
}