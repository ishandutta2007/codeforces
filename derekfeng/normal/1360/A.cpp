#include<bits/stdc++.h>
main(){int t,a,b,s;for(std::cin>>t;t--;){std::cin>>a>>b;s=std::min(std::max(a+a,b),std::max(a,b+b));std::cout<<s*s<<'\n';}}