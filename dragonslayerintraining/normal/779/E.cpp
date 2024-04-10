#include <iostream>
#include <map>

std::map<std::string,int> indices;

struct cvar{
  enum etype{
    TYPE_AND,
    TYPE_OR,
    TYPE_XOR,
    TYPE_VAR,
  }type;
  int idx1,idx2;
  std::string val;
}vars[5005];

int dp[5005][2];

int main(){
  int N,M;
  std::cin>>N>>M;
  indices["?"]=0;
  for(int i=1;i<=N;i++){
    std::string name;
    std::string equals;
    std::cin>>name>>equals;
    indices[name]=i;
    std::string val1;
    std::cin>>val1;
    if(!std::isdigit(val1[0])){
      std::string op,val2;
      std::cin>>op>>val2;
      if(op=="AND"){
	vars[i].type=cvar::TYPE_AND;
      }else if(op=="OR"){
	vars[i].type=cvar::TYPE_OR;
      }else if(op=="XOR"){
	vars[i].type=cvar::TYPE_XOR;
      }
      vars[i].idx1=indices[val1];
      vars[i].idx2=indices[val2];
    }else{
      vars[i].type=cvar::TYPE_VAR;
      vars[i].val=val1;
    }
  }
  /*
  for(int i=0;i<=N;i++){
    std::cout<<"v"<<i<<"=";
    switch(vars[i].type){
    case cvar::TYPE_AND:std::cout<<"AND(v"<<vars[i].idx1<<",v"<<vars[i].idx2<<")"<<std::endl;break;
    case cvar::TYPE_OR:std::cout<<"OR(v"<<vars[i].idx1<<",v"<<vars[i].idx2<<")"<<std::endl;break;
    case cvar::TYPE_XOR:std::cout<<"XOR(v"<<vars[i].idx1<<",v"<<vars[i].idx2<<")"<<std::endl;break;
    case cvar::TYPE_VAR:std::cout<<"VAR("<<vars[i].val<<")"<<std::endl;break;
    }
  }
  */
  std::string min(M,'-');
  std::string max(M,'-');
  for(int k=0;k<M;k++){
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1;i<=N;i++){
      for(int j=0;j<=1;j++){
	switch(vars[i].type){
	case cvar::TYPE_AND:
	  dp[i][j]=dp[vars[i].idx1][j]&dp[vars[i].idx2][j];
	  break;
	case cvar::TYPE_OR:
	  dp[i][j]=dp[vars[i].idx1][j]|dp[vars[i].idx2][j];
	  break;
	case cvar::TYPE_XOR:
	  dp[i][j]=dp[vars[i].idx1][j]^dp[vars[i].idx2][j];
	  break;
	case cvar::TYPE_VAR:
	  dp[i][j]=(vars[i].val[k]-'0');
	  break;
	}
      }
    }
    int sum[2]={0,0};
    for(int i=1;i<=N;i++){
      for(int j=0;j<=1;j++){
	sum[j]+=dp[i][j];
      }
    }
    if(sum[0]<=sum[1]){
      min[k]='0';
    }else{
      min[k]='1';
    }
    if(sum[0]>=sum[1]){
      max[k]='0';
    }else{
      max[k]='1';
    }
  }
  std::cout<<min<<std::endl;
  std::cout<<max<<std::endl;
  return 0;
}