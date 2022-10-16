#include <cstdio>
#include <map>

struct Trie{
  std::map<int,int> children;
  int cnt;
}nodes[600005];
int nodes_max=0;

int new_node(){
  nodes[nodes_max].children.clear();
  nodes[nodes_max].cnt=0;
  return nodes_max++;
}

int getchild(int x,int c){
  if(!nodes[x].children.count(c)){
    nodes[x].children[c]=new_node();
  }
  return nodes[x].children[c];
}

int merge(int x,int y){
  if(nodes[x].children.size()<nodes[y].children.size()){
    std::swap(x,y);
  }
  for(auto it:nodes[y].children){
    if(nodes[x].children.count(it.first)){
      nodes[x].children[it.first]=merge(nodes[x].children[it.first],it.second);
    }else{
      nodes[x].children[it.first]=it.second;
    }
  }
  nodes[x].cnt+=nodes[y].cnt;
  return x;
}

void solve(){
  nodes_max=0;
  long long ans=0;
  int root=new_node();
  ans+=nodes[root].cnt;
  nodes[root].cnt++;//add empty
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    int sub=getchild(root,A);
    nodes[root].children.erase(A);
    int ext=new_node();
    nodes[ext].children[A]=root;
    root=merge(sub,ext);
    ans+=nodes[root].cnt;
    nodes[root].cnt++;//add empty
  }
  printf("%I64d\n",ans);
}

int main(){
  int Q;
  scanf("%d",&Q);
  while(Q--){
    solve();
  }
}