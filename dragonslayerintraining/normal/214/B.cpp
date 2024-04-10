#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int digit[10]={};
  for(int i=0;i<N;i++){
    int D;
    std::cin>>D;
    digit[D]++;
  }
  if(digit[0]==0){
    std::cout<<-1<<std::endl;
    return 0;
  }else{
    //Add on the end later to make divisible by 2 and 5
    digit[0]--;
  }
  int sum=0;
  for(int i=0;i<10;i++){
    sum+=i*digit[i];
  }
  if(sum%3!=0){
    //remove one digit
    for(int i=sum%3;i<10;i+=3){
      if(digit[i]>0){
	digit[i]--;
	sum-=i;
	break;
      }
    }
  }
  if(sum%3!=0){
    //remove two digits
    for(int i=(3-sum%3)%3;i<10;i+=3){
      while(digit[i]>0){
	digit[i]--;
	sum-=i;
	if(sum%3==0){
	  break;
	}
      }
      if(sum%3==0){
	break;
      }
    }
  }
  if(sum%3!=0){
    std::cout<<-1<<std::endl;
    return 0;
  }
  if(sum>0){
    for(int i=9;i>=0;i--){
      for(int k=0;k<digit[i];k++){
	std::cout<<i;
      }
    }
  }
  std::cout<<0<<std::endl;
  return 0;
}