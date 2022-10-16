#include <iostream>
#include <iomanip>

int N,R;
int fs[50],ss[50],ps[50];

double dp[51][5001];

double reset;

double get(int i,int t){
  return (t<=R)?dp[i][t]:reset;
}

int main(){
  std::cin>>N>>R;
  for(int i=0;i<N;i++){
    std::cin>>fs[i]>>ss[i]>>ps[i];
  }
  double low=0,high=1e9;
  while(high-low>1e-9){
    reset=(low+high)/2;
    if(reset==low||reset==high) break;
    for(int t=0;t<=R;t++){
      dp[N][t]=0;
    }
    for(int i=N-1;i>=0;i--){
      for(int t=0;t<=R;t++){
	dp[i][t]=(ps[i]*(fs[i]+get(i+1,t+fs[i]))+
		  (100-ps[i])*(ss[i]+get(i+1,t+ss[i])))/100;
	if(i>0){
	  dp[i][t]=std::min(dp[i][t],reset);
	}
      }
    }
    if(dp[0][0]<reset){
      high=reset;
    }else{
      low=reset;
    }
  }
  std::cout<<std::fixed<<std::setprecision(10)<<reset<<std::endl;
  return 0;
}