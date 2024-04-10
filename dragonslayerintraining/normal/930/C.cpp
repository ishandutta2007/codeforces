#include <iostream>

int as[100001];
int lis[100001];
int lds[100001];

int bit[100002];
int N,M;

void update(int i,int x){
  for(i++;i<=M;i+=(i&-i)){
    bit[i]=std::max(bit[i],x);
  }
}

int query(int i){
  int ac=0;
  for(i++;i>0;i-=(i&-i)){
    ac=std::max(ac,bit[i]);
  }
  return ac;
}

int main(){
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    int L,R;
    std::cin>>L>>R;
    as[L-1]++;
    as[R]--;
  }
  for(int i=1;i<M;i++){
    as[i]+=as[i-1];
  }
  for(int i=0;i<M;i++){
    int l=query(as[i]);
    update(as[i],l+1);
    lis[i]=l+1;
  }
  std::fill(bit,bit+M+1,0);
  for(int i=M-1;i>=0;i--){
    int l=query(as[i]);
    update(as[i],l+1);
    lds[i]=l+1;
  }
  int best=0;
  for(int i=1;i<M;i++){
    best=std::max(best,lis[i-1]+lds[i]);
  }
  std::cout<<best<<std::endl;
  return 0;
}