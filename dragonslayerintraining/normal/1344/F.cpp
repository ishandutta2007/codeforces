#include <iostream>
#include <map>
#include <bitset>
#include <vector>

int val[1000][2];

std::vector<std::bitset<2001> > mat;

std::map<char,int> code{{'R',1},{'Y',2},{'B',3},{'.',0},{'W',0}};
char decode[]=".RYB";

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    val[i][0]=1;
    val[i][1]=2;
  }
  for(int i=0;i<K;i++){
    std::string type;
    int cnt;
    std::cin>>type>>cnt;
    std::vector<int> indices;
    while(cnt--){
      int X;
      std::cin>>X;
      X--;
      indices.push_back(X);
    }
    if(type=="mix"){
      char color;
      std::cin>>color;
      for(int b=0;b<2;b++){
	std::bitset<2001> row;
	for(int i:indices){
	  row.set(i*2,(val[i][b]>>0)&1);
	  row.set(i*2+1,(val[i][b]>>1)&1);
	}
	row.set(2000,(code[color]>>b)&1);
	mat.push_back(row);
      }
    }else if(type=="RY"){
      for(int i:indices){
	std::swap(val[i][0],val[i][1]);
      }
    }else if(type=="RB"){
      for(int i:indices){
	val[i][1]^=val[i][0];
      }
    }else if(type=="YB"){
      for(int i:indices){
	val[i][0]^=val[i][1];
      }
    }
  }
  for(int i=0;i<N*2;i++){
    for(int j=i;;j++){
      if(j==mat.size()){
	std::bitset<2001> row;
	row.set(i);
	mat.push_back(row);
      }
      if(mat[j].test(i)){
	std::swap(mat[i],mat[j]);
	break;
      }
    }
    for(int j=i+1;j<mat.size();j++){
      if(mat[j].test(i)){
	mat[j]^=mat[i];
      }
    }
  }
  for(int i=N*2;i<mat.size();i++){
    if(mat[i].test(2000)){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  for(int i=N*2-1;i>=0;i--){
    for(int j=i-1;j>=0;j--){
      if(mat[j].test(i)){
	mat[j]^=mat[i];
      }
    }
  }
  std::cout<<"YES"<<std::endl;
  for(int i=0;i<N;i++){
    std::cout<<decode[mat[i*2+1].test(2000)<<1|mat[i*2].test(2000)];
  }
  std::cout<<std::endl;
}