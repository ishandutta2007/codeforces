#include <iostream>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N;
std::string str;

int main(){
  fin>>N>>str;
  int dist=0;
  
  for(int i=0;i<N;i++){
    if(str[i]=='1'){
      for(int j=i+1;j<N;j++){
	if(str[j]=='1'){
	  dist=j-i;
	  break;
	}
      }
      for(int j=i+1;j<N;j++){
	if(str[j]=='1'){
	  if(j-i!=dist){
	    fout<<"NO"<<std::endl;
	    return 0;
	  }else{
	    i=j;
	  }
	}
      }
      break;
    }
  }
  fout<<"YES"<<std::endl;
  
  return 0;
}