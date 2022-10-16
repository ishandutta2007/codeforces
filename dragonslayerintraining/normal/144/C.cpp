#include <iostream>

std::string S,P;

int pcnt[256];
int scnt[256];
int over=0;
int cnt=0;

int main(){
  std::cin>>S>>P;
  if(S.size()<P.size()){
    std::cout<<0<<std::endl;
    return 0;
  }
  for(int i=0;i<P.size();i++){
    pcnt[P[i]]++;
  }
  pcnt['?']=1e9;
  for(int i=0;i<P.size();i++){
    if(scnt[S[i]]==pcnt[S[i]]){
      over++;
    }
    scnt[S[i]]++;
  }
  cnt+=(over==0);
  for(int i=P.size();i<S.size();i++){
    if(scnt[S[i]]==pcnt[S[i]]){
      over++;
    }
    scnt[S[i]]++;
    scnt[S[i-P.size()]]--;
    if(scnt[S[i-P.size()]]==pcnt[S[i-P.size()]]){
      over--;
    }
    cnt+=(over==0);
  }
  std::cout<<cnt<<std::endl;
  return 0;
}