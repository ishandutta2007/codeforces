#include <iostream>
#include <set>
#include <algorithm>

int as[100];
int bs[100];

int main(){
  int N,M;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  std::cin>>M;
  for(int i=0;i<M;i++){
    std::cin>>bs[i];
  }
  std::sort(bs,bs+M);
  std::multiset<int> aprev,bprev;
  int i=0,j=0;
  int total=0;
  while((i<N)||(j<M)){
    if((j==M)||((i<N)&&(as[i]<bs[j]))){
      if(bprev.count(as[i]-1)){
	bprev.erase(bprev.find(as[i]-1));
	total++;
      }else if(bprev.count(as[i])){
	bprev.erase(bprev.find(as[i]));
	total++;
      }else{
	aprev.insert(as[i]);
      }
      i++;
    }else{
      if(aprev.count(bs[j]-1)){
	aprev.erase(aprev.find(bs[j]-1));
	total++;
      }else if(aprev.count(bs[j])){
	aprev.erase(aprev.find(bs[j]));
	total++;
      }else{
	bprev.insert(bs[j]);
      }
      j++;
    }
  }
  std::cout<<total<<std::endl;
  return 0;
}