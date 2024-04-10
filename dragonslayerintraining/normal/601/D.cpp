#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

typedef struct Trie{
  Trie* next[26];
  int cnt;
  int size;
  Trie(int cnt):cnt(cnt),size(cnt){
    for(int c=0;c<26;c++){
      next[c]=NULL;
    }
  }
  Trie(int c,Trie* child):Trie(0){
    next[c-'a']=child;
    size=child->size;
  }
  static int getsize(struct Trie* trie){
    return trie?trie->size:0;
  }
  //destructive
  static struct Trie* merge(struct Trie* trie,struct Trie* other){
    if(trie==NULL){
      return other;
    }
    if(other==NULL){
      return trie;
    }
    if(getsize(trie)<getsize(other)){
      return merge(other,trie);
    }
    trie->cnt|=other->cnt;
    trie->size=trie->cnt;
    for(int c=0;c<26;c++){
      trie->next[c]=merge(trie->next[c],other->next[c]);
      trie->size+=getsize(trie->next[c]);
    }
    return trie;
  }
}Trie;

int cs[300000];
std::string chars;
int size[300000];
int score[300000];

std::vector<int> edges[300000];


void dfs1(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if(child!=parent){
      dfs1(child,node);
      size[node]+=size[child];
    }
  }
}

struct Trie* dfs2(int node,int parent){
  Trie* trie=new Trie(1);
  for(int child:edges[node]){
    if(child!=parent){
      trie=Trie::merge(trie,dfs2(child,node));
    }
  }
  score[node]=Trie::getsize(trie)+cs[node];
  Trie* up=new Trie(chars[node],trie);
  return up;
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>cs[i];
  }
  std::cin>>chars;
  for(int i=1;i<N;i++){
    int U,V;
    std::cin>>U>>V;
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs1(0,0);
  dfs2(0,0);
  int max=*std::max_element(score,score+N);
  std::cout<<max<<std::endl;
  std::cout<<std::count(score,score+N,max)<<std::endl;
  return 0;
}