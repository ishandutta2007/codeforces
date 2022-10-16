#include <iostream>

int N,K;

bool isvowel(char c){
  return (c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u');
}

int rhyme_dist(std::string s1){
  int vcnt=0;
  for(int i=s1.length()-1;i>=0;i--){
    if(isvowel(s1[i])){
      vcnt++;
      if(vcnt==K){
	return i;
      }
    }
  }
  return -1;
}

bool rhymes(std::string s1,std::string s2){
  int i1=rhyme_dist(s1);
  int i2=rhyme_dist(s2);
  if((i1==-1)||(i2==-1)){
    return false;
  }
  return !s1.compare(i1,std::string::npos,s2,i2,std::string::npos);
}

const int CLERIHEW=9;
const int ALTERNATING=10;
const int ENCLOSED=12;
int scheme=15;

int main(){
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::string s1,s2,s3,s4;
    int quatrain=0;
    std::cin>>s1>>s2>>s3>>s4;
    if(rhymes(s1,s2)&&rhymes(s3,s4)){
      quatrain|=CLERIHEW;
    }
    if(rhymes(s1,s3)&&rhymes(s2,s4)){
      quatrain|=ALTERNATING;
    }
    if(rhymes(s1,s4)&&rhymes(s2,s3)){
      quatrain|=ENCLOSED;
    }
    scheme&=quatrain;
  }
  switch(scheme){
  case CLERIHEW:
    std::cout<<"aabb"<<std::endl;
    break;
  case ALTERNATING:
    std::cout<<"abab"<<std::endl;
    break;
  case ENCLOSED:
    std::cout<<"abba"<<std::endl;
    break;
  case 15:
    std::cout<<"aaaa"<<std::endl;
    break;
  default:
    std::cout<<"NO"<<std::endl;
    break;
  }
  return 0;
}