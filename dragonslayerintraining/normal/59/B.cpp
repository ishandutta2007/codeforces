#include <iostream>
#include <set>

int main(){
  int N;
  std::multiset<int> evens,odds;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int flower;
    std::cin>>flower;
    if(flower%2==0){
      evens.insert(flower);
    }else{
      odds.insert(flower);
    }
  }
  if(odds.size()==0){
    std::cout<<0<<std::endl;
  }else{
    int odds_used=(odds.size()-1)/2*2+1;
    int sum=0;
    for(std::multiset<int>::reverse_iterator
	  it=odds.rbegin();it!=odds.rend();it++){
      if(odds_used>0){
	sum+=*it;
	odds_used--;
      }
    }
    for(std::multiset<int>::reverse_iterator
	  it=evens.rbegin();it!=evens.rend();it++){
      sum+=*it;
    }
    std::cout<<sum<<std::endl;
  }
  return 0;
}