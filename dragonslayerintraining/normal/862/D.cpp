#include <iostream>

int N;
int vs[1001];

void query(int x){
  std::cout<<"? "<<std::string(x,'1')<<std::string(N-x,'0')<<std::endl;
  std::cin>>vs[x];
}

int zero=-1,one=-1;

bool zerorun(int low,int high){
  return (high-low)==(vs[high]-vs[low]);
}
bool onerun(int low,int high){
  return (low-high)==(vs[high]-vs[low]);
}
bool hasrun(int low,int high){
  return zerorun(low,high)||onerun(low,high);
}

int main(){
  std::cin>>N;
  int low=0,high=N;
  query(0);
  vs[high]=N-vs[low];
  while(true){
    int mid=(low+high)/2;
    query(mid);
    if(zerorun(low,mid)){
      zero=low;
    }else if(onerun(low,mid)){
      one=low;
    }
    if(zerorun(mid,high)){
      zero=mid;
    }else if(onerun(mid,high)){
      one=mid;
    }
    if(!hasrun(low,mid)){
      high=mid;
    }else if(!hasrun(mid,high)){
      low=mid;
    }else{
      break;
    }
  }
  std::cout<<"! "<<zero+1<<" "<<one+1<<std::endl;
  return 0;
}