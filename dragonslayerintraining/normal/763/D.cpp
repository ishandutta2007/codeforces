#include <iostream>
#include <vector>
#include <map>

struct csegtree{
  int size;
  int left,right;
  csegtree(int size,int left,int right):size(size),left(left),right(right){
  }
  bool operator<(struct csegtree other)const{
    if(size!=other.size){
      return size<other.size;
    }
    if(left!=other.left){
      return left<other.left;
    }
    return right<other.right;
  }
};

std::vector<struct csegtree> segtree_v;
std::map<struct csegtree,int> segtree_m;

int construct(struct csegtree segtree){
  if(!segtree_m.count(segtree)){
    int id=segtree_v.size();
    segtree_m[segtree]=id;
    segtree_v.push_back(segtree);
  }
  return segtree_m[segtree];
}

int construct(int size,int left,int right){
  return construct(csegtree(size,left,right));
}

int constructsingle(int val){
  return construct(1,-1,val);
}

int constructempty(int size){
  int st=constructsingle(0);
  for(int size2=1;size2<size;size2*=2){
    st=construct(size2*2,st,st);
  }
  return st;
}

int add(int st,int index,int val){
  struct csegtree segtree=segtree_v[st];
  if((index<0)||(index>=segtree.size)){
    std::cerr<<"WARNING: segment tree index OOB"<<std::endl;
    return st;
  }
  if(segtree.size==1){
    return constructsingle(segtree.right+val);
  }
  if(index<segtree.size/2){
    return construct(segtree.size,add(segtree.left,index,val),segtree.right);
  }else{
    return construct(segtree.size,segtree.left,add(segtree.right,index-segtree.size/2,val));
  }
}

void dump(int st){
  struct csegtree segtree=segtree_v[st];
  if(segtree.size==1){
    std::cout<<segtree.right<<" ";
  }else{
    dump(segtree.left);
    dump(segtree.right);
  }
}

std::map<int,int> isotree_m;
std::vector<int> isotree_v;

int constructisotree(int val){
  if(!isotree_m.count(val)){
    int id=isotree_v.size();
    isotree_m[val]=id;
    isotree_v.push_back(val);
  }
  return isotree_m[val];
}

int N;
std::vector<int> edges[100000];

int subtree_id[100000];
int fulltree_id[100000];

std::map<int,int> isos;

void isos_insert(int id){
  isos[id]++;
}

void isos_erase(int id){
  if(--isos[id]==0){
    isos.erase(id);
  }
}

int isos_getsize(){
  return isos.size();
}

void dfs1(int node,int parent){
  int st=constructempty(N*3);
  for(int child:edges[node]){
    if(child!=parent){
      dfs1(child,node);
      st=add(st,subtree_id[child],1);
    }
  }
  subtree_id[node]=constructisotree(st);
  isos_insert(subtree_id[node]);
}
void dfs2(int node,int parent){
  if(parent==-1){
    fulltree_id[node]=subtree_id[node];
  }else{
    int parenttree=constructisotree(add(isotree_v[fulltree_id[parent]],subtree_id[node],-1));
    fulltree_id[node]=constructisotree(add(isotree_v[subtree_id[node]],parenttree,1));
  }
  for(int child:edges[node]){
    if(child!=parent){
      dfs2(child,node);
    }
  }
}

std::pair<int,int> best(-1,-1);

void dfs3(int node,int parent){
  isos_erase(subtree_id[node]);
  best=std::max(best,std::make_pair(isos_getsize(),node));
  for(int child:edges[node]){
    if(child!=parent){
      int tmptree=constructisotree(add(isotree_v[fulltree_id[node]],subtree_id[child],-1));
      isos_insert(tmptree);
      dfs3(child,node);
      isos_erase(tmptree);
    }
  }
  isos_insert(subtree_id[node]);
}

int main(){
  std::cin>>N;
  for(int i=0;i<N-1;i++){
    int U,V;
    std::cin>>U>>V;
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs1(0,-1);
  dfs2(0,-1);
  /*
  for(int i=0;i<N;i++){
    std::cout<<i+1<<": "<<subtree_id[i]<<"\t"<<fulltree_id[i]<<std::endl;
  }
  */
  dfs3(0,-1);
  std::cout<<best.second+1<<std::endl;
  return 0;
}