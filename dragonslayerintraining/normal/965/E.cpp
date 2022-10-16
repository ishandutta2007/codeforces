#include <cstdio>
#include <vector>
#include <set>
#include <cassert>

char str[1000001];

struct Node{
  int has;
  int child[26];
  Node():has(0){
    std::fill(child,child+26,0);
  }
};
std::vector<struct Node> trie;

int getchild(int root,int c){
  if(!trie[root].child[c]){
    trie[root].child[c]=trie.size();
    trie.emplace_back();
  }
  return trie[root].child[c];
}

void add(const char *str,int root=0){
  if(*str=='\0'){
    trie[root].has++;
  }else{
    add(str+1,getchild(root,*str-'a'));
  }
}

std::multiset<int>* dfs(int node,int depth){
  std::multiset<int>* s=new std::multiset<int>();
  for(int c=0;c<26;c++){
    if(!trie[node].child[c]) continue;
    std::multiset<int> *child=dfs(trie[node].child[c],depth+1);
    if(child->size()>s->size()){
      std::swap(s,child);
    }
    s->insert(child->begin(),child->end());
    delete child;
  }
  if(node){
    if(!trie[node].has){
      assert(s->size());
      s->erase(s->find(*s->rbegin()));
    }
    s->insert(depth);
  }
  return s;
}

int main(){
  trie.emplace_back();
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    add(str);
  }
  std::multiset<int>* res=dfs(0,0);
  int sum=0;
  for(int d:*res){
    sum+=d;
  }
  printf("%d\n",sum);
  return 0;
}