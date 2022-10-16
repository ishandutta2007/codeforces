#include <cstdio>
#include <vector>
#include <algorithm>

char str[100005];

std::vector<int> bits[2];

const char player[3][32]={"tokitsukaze","quailty","once again"};

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    bits[str[i]-'0'].push_back(i);
  }
  for(int b=0;b<2;b++){
    if(bits[b].empty()||bits[b].back()-bits[b].front()+1<=K){
      puts(player[0]);
      return 0;
    }
  }
  for(int b=0;b<2;b++){
    for(int i=0;i+K<=N;i++){
      auto it1=std::lower_bound(bits[b].begin(),bits[b].end(),i);
      auto it2=std::lower_bound(bits[b].begin(),bits[b].end(),i+K);
      //before it1 or after it2
      std::vector<int> v;
      if(it1!=bits[b].begin()){
	v.push_back(bits[b].front());
	v.push_back(*(it1-1));
      }
      if(it2!=bits[b].end()){
	v.push_back(*it2);
	v.push_back(bits[b].back());
      }
      if(v.back()-v.front()+1>K){
	puts(player[2]);
	return 0;
      }
    }
  }
  puts(player[1]);
}