#include <iostream>
#include <algorithm>

int minonday[32],maxonday[32];

int main(){
  int N;
  int sumtime=0,minsum=0,maxsum=0;
  std::cin>>N>>sumtime;
  for(int i=0;i<N;i++){
    std::cin>>minonday[i]>>maxonday[i];
    minsum+=minonday[i];
    maxsum+=maxonday[i];
  }
  if((sumtime>=minsum)&&(sumtime<=maxsum)){
    std::cout<<"YES"<<std::endl;

    for(int i=0;i<N-1;i++){
      int minsump=minsum-minonday[i],maxsump=maxsum-maxonday[i];
      /*
      if((sumtime-minonday[i]>=minsump)&&(sumtime-minonday[i]<=maxsump)){
	std::cout<<minonday[i]<<" ";
	sumtime-=minonday[i];
      }else if((sumtime-maxonday[i]>=minsump)&&(sumtime-maxonday[i]<=maxsump)){
	std::cout<<maxonday[i]<<" ";
	sumtime-=maxonday[i];
      }
      */
      int lower=sumtime-maxsump,upper=sumtime-minsump;
      lower=std::max(lower,minonday[i]);
      upper=std::min(upper,minonday[i]);

      std::cout<<lower<<" ";
      sumtime-=lower;
      
      minsum=minsump,maxsum=maxsump;
    }
    std::cout<<sumtime<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}