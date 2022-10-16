#include <iostream>
#include <set>

int uf[100000];
int size[100000];
std::set<int> forbid;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void unite(int a,int b){
  a=find(a),b=find(b);
  if(a==b){
    return;
  }
  if(size[a]<size[b]){
    size[b]+=size[a];
    uf[a]=b;
  }else{
    size[a]+=size[b];
    uf[b]=a;
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    uf[i]=i;
    size[i]=1;
  }
  int K;
  std::cin>>K;
  for(int i=0;i<K;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    unite(A,B);
  }
  int M;
  std::cin>>M;
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    if(find(A)==find(B)){
      forbid.insert(find(A));
    }
  }
  int best=0;
  for(int i=0;i<N;i++){
    if(forbid.count(find(i))){
      continue;
    }
    best=std::max(best,size[i]);
  }
  std::cout<<best<<std::endl;
  return 0;
}