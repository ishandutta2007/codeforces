#include <iostream>

struct Trie{
  struct Trie* child[2];
  int cnt;
  Trie():cnt(0){
    for(int i=0;i<2;i++){
      child[i]=NULL;
    }
  }
  struct Trie* getchild(int index){
    if(child[index]==NULL){
      child[index]=new Trie();
    }
    return child[index];
  }
}root;

void add(int val,int delta){
  struct Trie *trie=&root;
  for(int k=30;k>=0;k--){
    trie->cnt+=delta;
    trie=trie->getchild((val>>k)&1);
  }
  trie->cnt+=delta;
}

int query(int val,int L){
  int total=0;
  struct Trie *trie=&root;
  for(int k=30;k>=0;k--){
    int b=((val>>k)&1);
    int v=((L>>k)&1);
    if(v){
      total+=trie->getchild(b)->cnt;
    }
    trie=trie->getchild(v^b);
  }
  return total;
}

int main(){
  int Q;
  std::cin>>Q;
  for(int i=0;i<Q;i++){
    int T;
    std::cin>>T;
    switch(T){
    case 1:{
      int P;
      std::cin>>P;
      add(P,1);
      break;
    }
    case 2:{
      int P;
      std::cin>>P;
      add(P,-1);
      break;
    }
    case 3:{
      int P,L;
      std::cin>>P>>L;
      std::cout<<query(P,L)<<std::endl;
      break;
    }
    }
  }
  return 0;
}