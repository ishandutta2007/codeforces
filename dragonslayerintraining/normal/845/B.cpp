#include <iostream>
#include <cstdio>
#include <algorithm>

int ds[7]={};

int main(){
  std::string str;
  std::cin>>str;
  int ans=6;
  while(!ds[6]){
    if(ds[0]+ds[1]+ds[2]==ds[3]+ds[4]+ds[5]){
      int diff=0;
      for(int i=0;i<6;i++){
	diff+=(str[i]!=ds[i]+'0');
	//printf("%d",ds[i]);
      }
      //printf("\n");
      ans=std::min(ans,diff);
    }
    ds[0]++;
    for(int k=0;ds[k]==10;k++){
      ds[k]=0;
      ds[k+1]++;
    }
  }
  printf("%d\n",ans);
  return 0;
}