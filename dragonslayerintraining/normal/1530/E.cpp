#include <iostream>
#include <map>
#include <cassert>
#include <algorithm>

std::string str,out;
int N;

std::map<char,int> freq;//only nonzero frequencies

bool check(int i){
  if(i==N) return true;
  if(out[0]==out[1]){
    if(out[i-1]==out[0]){
      return freq[out[0]]<=(N-i)/2;
    }else{
      return freq[out[0]]<=(N-i+1)/2;
    }
  }else{
    if(out[i-1]==out[0]){
      //if it has a out[1], must have something other than out[0] and out[1]
      if(!freq.count(out[1])) return true;
      for(auto it:freq){
	if(it.first!=out[0]&&it.first!=out[1]){
	  return true;
	}
      }
      return false;
    }else{
      return true;
    }
  }
}

void gen(int i){
  if(i==N) return;
  for(char x='a';x<='z';x++){
    if(out[i-1]==out[0]&&x==out[1]) continue;
    if(freq.count(x)&&freq[x]>0){
      if(--freq[x]==0){
	freq.erase(x);
      }
      out[i]=x;
      if(check(i+1)){
	return gen(i+1);
      }
      freq[x]++;
    }
  }
  out.resize(i);
  std::cerr<<"Failed: "<<out<<std::endl;
  for(auto it:freq){
    std::cout<<it.first<<": "<<it.second<<std::endl;
  }
  assert(0);
}

void solve(){
  std::cin>>str;
  N=str.length();
  out.resize(N);
  
  freq.clear();
  for(int i=0;i<N;i++){
    freq[str[i]]++;
  }
  if(freq.size()==1){
    std::cout<<str<<std::endl;
    return;
  }
  for(auto it:freq){
    if(it.second==1){
      std::swap(str[0],*std::find(str.begin(),str.end(),it.first));
      std::sort(str.begin()+1,str.end());
      std::cout<<str<<std::endl;
      return;
    }
  }
  for(char x='a';x<='z';x++){
    if(freq.count(x)&&freq[x]>0){
      if(--freq[x]==0){
	freq.erase(x);
      }
      out[0]=x;
      for(char y='a';y<='z';y++){
	if(freq.count(y)&&freq[y]>0){
	  if(--freq[y]==0){
	    freq.erase(y);
	  }
	  out[1]=y;
	  if(check(2)){
	    gen(2);
	    std::cout<<out<<std::endl;
	    return;
	  }
	  freq[y]++;
	}
      }
      freq[x]++;
    }
  }
}
    

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}