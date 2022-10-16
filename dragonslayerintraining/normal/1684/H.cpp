#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void solve(){
  std::string S;
  std::cin>>S;
  int ones=std::count(S.begin(),S.end(),'1');
  if(ones==0){
    std::cout<<-1<<"\n";
  }else if(ones==5){
    //find pattern 10X
    for(int i=0;i+2<S.length();i++){
      if(S[i]=='1'&&S[i+1]=='0'){
	std::cout<<S.length()-2<<"\n";
	for(int j=0;j<i;j++){
	  std::cout<<j+1<<" "<<j+1<<"\n";
	}
	std::cout<<i+1<<" "<<i+3<<"\n";
	for(int j=i+3;j<S.length();j++){
	  std::cout<<j+1<<" "<<j+1<<"\n";
	}
	return;
      }
    }
    //all 1s contiguous
    for(int i=0;i<S.length();i++){
      if(S[i]=='1'){
	std::cout<<S.length()-3<<"\n";
	for(int j=0;j<i;j++){
	  std::cout<<j+1<<" "<<j+1<<"\n";
	}
	std::cout<<i+1<<" "<<i+4<<"\n";
	for(int j=i+4;j<S.length();j++){
	  std::cout<<j+1<<" "<<j+1<<"\n";
	}
	return;
      }
    }
    assert(0);
  }else{
    int pow2=1;
    while(pow2<ones) pow2*=2;
    int rem=pow2-ones;
    std::vector<std::pair<int,int> > frags;
    for(int i=0;i<S.size();i++){
      if(S[i]=='0'){
	frags.emplace_back(i,i);
	continue;
      }
      //invariant during this phase: rem <= remaining_ones-2-#steps
      if(rem>=4){
	frags.emplace_back(i,i+2);
	rem-=3+(S[i+1]=='1');
	i+=2;
	continue;
      }
      if(rem>=1){
	frags.emplace_back(i,i+1);
	rem--;
	i++;
	continue;
      }
      frags.emplace_back(i,i);
    }
    std::cout<<frags.size()<<"\n";
    for(auto frag:frags){
      std::cout<<frag.first+1<<" "<<frag.second+1<<"\n";
    }
  }
}

int main(){
  int T;
  std::cin>>T;
  while(T--){
    solve();
  }
}