#include <iostream>
#include <vector>
#include <algorithm>

//has a then b
bool has(std::vector<int>& v,int a,int b){
  int state=0;
  for(int x:v){
    if(x==a&&state==0) state=1;
    if(x==b&&state==1) state=2;
  }
  return state==2;
}

bool f(std::string str,char plus,char minus,int& diff){
  int x=0;
  std::vector<int> seq({0});
  for(char c:str){
    if(c==plus){
      x++;
      seq.push_back(x);
    }else if(c==minus){
      x--;
      seq.push_back(x);
    }
  }
  /*
  for(int x:seq){
    printf("x=%d\n",x);
  }
  printf("\n");
  */
  int min=*std::min_element(seq.begin(),seq.end());
  int max=*std::max_element(seq.begin(),seq.end());
  diff=max-min+1;
  return !(has(seq,min,max)&&has(seq,max,min))&&diff>2;
}

long long solve(){
  std::string str;
  std::cin>>str;
  int dx,dy;
  bool qx=f(str,'W','S',dx);
  bool qy=f(str,'A','D',dy);
  long long area=1LL*dx*dy;
  //printf("%d %d %d %d\n",dx,dy,qx,qy);
  if(qx) area=std::min(area,1LL*(dx-1)*dy);
  if(qy) area=std::min(area,1LL*dx*(dy-1));
  return area;
}

int main(){
  int T;
  std::cin>>T;
  while(T--){
    std::cout<<solve()<<std::endl;
  }
  return 0;
}