#include <iostream>
#include <map>

std::map<std::string,int> cps;

int uf[200005];

int find(int a){
  return a==uf[a]?a:uf[a]=find(uf[a]);
}

void merge(int a,int b){
  uf[find(a)]=find(b);
}

int main(){
  int N,M,Q;
  std::cin>>N>>M>>Q;
  for(int i=0;i<N*2;i++){
    uf[i]=i;
  }
  for(int i=0;i<N;i++){
    std::string word;
    std::cin>>word;
    cps[word]=i;
  }
  for(int i=0;i<M;i++){
    int T;
    std::string A,B;
    std::cin>>T>>A>>B;
    int x=cps[A],y=cps[B];
    if(T==1){
      if(find(x<<1)==find(y<<1|1)){
	std::cout<<"NO"<<std::endl;
      }else{
	std::cout<<"YES"<<std::endl;
	merge(x<<1,y<<1);
	merge(x<<1|1,y<<1|1);
      }
    }else{
      if(find(x<<1)==find(y<<1)){
	std::cout<<"NO"<<std::endl;
      }else{
	std::cout<<"YES"<<std::endl;
	merge(x<<1,y<<1|1);
	merge(x<<1|1,y<<1);
      }
    }
  }
  for(int i=0;i<Q;i++){
    std::string A,B;
    std::cin>>A>>B;
    int x=cps[A],y=cps[B];
    if(find(x<<1)==find(y<<1)){
      std::cout<<1<<std::endl;
    }else if(find(x<<1)==find(y<<1|1)){
      std::cout<<2<<std::endl;
    }else{
      std::cout<<3<<std::endl;
    }
  }
}