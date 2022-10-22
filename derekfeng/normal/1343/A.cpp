#include<iostream>
main(){int n,a,x;std::cin>>n;while(n--){std::cin>>a,x=3;while(a%x)x=x*2+1;std::cout<<a/x<<"\n";}}