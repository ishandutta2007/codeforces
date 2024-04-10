#include <iostream>
#include <sstream>

const int INF=1e9+7;

int main(){
  std::string S;
  int K;
  std::cin>>K;
  std::getline(std::cin,S);//newline
  std::getline(std::cin,S);
  int low=0,high=1e6;
  while(high-low>1){
    int mid=(low+high)/2;
    int col=0;
    int word=0;
    int lines=0;
    for(int i=0;i<=S.size();i++){
      if(S[i]==' '||S[i]=='-'||S[i]=='\0'){
	int extra=(S[i]!='\0');
	if(col+word+extra>mid){
	  lines++;
	  col=0;
	}
	col+=word+extra;
	if(col>mid){
	  lines=INF;
	  break;
	}
	word=0;
      }else{
	word++;
      }
    }
    if(col) lines++;
    //std::cout<<"mid= "<<mid<<"lines="<<lines<<" col="<<col<<std::endl;
    if(lines<=K){
      high=mid;
    }else{
      low=mid;
    }
  }
  std::cout<<high<<std::endl;
  return 0;
}