#include <iostream>
#include <algorithm>
#include <vector>

int test(int limit){
  //std::cout<<"TEST("<<limit<<")"<<std::endl;
  std::vector<int> digits;
  for(;limit>0;limit/=10){
    digits.push_back(limit%10);
  }
  std::reverse(digits.begin(),digits.end());
  int cnt[11]={};
  int tmp[11];
  int match=0;
  for(int i=0;i<digits.size();i++){
    std::fill(tmp,tmp+11,0);
    for(int s=0;s<=10;s++){
      for(int a=0;a<10;a++){
	if(s+a<=10){
	  tmp[s+a]+=cnt[s];
	}
      }
    }
    for(int a=0;a<digits[i];a++){
      if(match+a<=10){
	tmp[match+a]++;
      }
    }
    match+=digits[i];
    std::copy(tmp,tmp+11,cnt);
    /*
    std::cout<<"DIGIT["<<i<<"]="<<digits[i]<<std::endl;
    for(int i=0;i<=10;i++){
      std::cout<<"SUM="<<i<<": "<<cnt[i]<<std::endl;
    }
    */
  }
  return cnt[10];
}

int main(){
  int K;
  std::cin>>K;
  int low=0,high=1e9;
  while(high-low>1){
    int mid=(low+high)/2;
    if(test(mid)>=K){
      high=mid;
    }else{
      low=mid;
    }
  }
  std::cout<<low<<std::endl;
  return 0;
}