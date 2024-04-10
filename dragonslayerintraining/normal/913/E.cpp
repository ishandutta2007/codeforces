#include <iostream>

std::string best[3][1<<(1<<3)];
//0: F
//1: T
//2: E

bool cmp(std::string a,std::string b){
  if(a.empty()) return false;
  if(b.empty()) return true;
  if(a.length()!=b.length()) return a.length()<b.length();
  return a<b;
}

void relax(std::string& a,std::string b){
  a=std::min(a,b,cmp);
}

int main(){
  for(int i=0;i<3;i++){
    int mask=0;
    for(int k=0;k<(1<<3);k++){
      if(k&(1<<i)){
	mask|=(1<<k);
      }
    }
    best[0][mask]=std::string(1,'z'-i);
  }
  for(int rep=0;rep<15;rep++){
    for(int i=0;i<(1<<8);i++){
      if(!best[0][i].empty()){
	relax(best[1][i],best[0][i]);
	relax(best[0][(1<<8)-1-i],std::string("!")+best[0][i]);
      }
      if(!best[1][i].empty()){
	relax(best[2][i],best[1][i]);
      }
      if(!best[2][i].empty()){
	relax(best[0][i],std::string("(")+best[2][i]+std::string(")"));
      }
    }
    for(int i=0;i<(1<<8);i++){
      if(best[1][i].empty()) continue;
      for(int j=0;j<(1<<8);j++){
	if(best[0][j].empty()) continue;
	relax(best[1][i&j],best[1][i]+"&"+best[0][j]);
      }
    }
    for(int i=0;i<(1<<8);i++){
      if(best[2][i].empty()) continue;
      for(int j=0;j<(1<<8);j++){
	if(best[1][j].empty()) continue;
	relax(best[2][i|j],best[2][i]+"|"+best[1][j]);
      }
    }
  }
  /*
  for(int i=0;i<(1<<8);i++){
    for(int k=0;k<8;k++){
      printf("%d",(i>>k)&1);
    }
    printf(": %s\n",best[2][i].c_str());
  }
  */
  int N;
  std::cin>>N;
  while(N--){
    std::string str;
    std::cin>>str;
    int mask=0;
    for(int i=0;i<8;i++){
      mask|=(str[i]=='1')<<i;
    }
    std::cout<<best[2][mask]<<std::endl;
  }
  return 0;
}