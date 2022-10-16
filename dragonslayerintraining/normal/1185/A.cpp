#include <iostream>
#include <algorithm>

int main(){
  int as[3],D;
  std::cin>>as[0]>>as[1]>>as[2]>>D;
  std::sort(as,as+3);
  printf("%d\n",std::max(0,D-(as[1]-as[0]))+
	 std::max(0,D-(as[2]-as[1])));
  return 0;
}