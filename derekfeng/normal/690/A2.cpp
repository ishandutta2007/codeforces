#include<bits/stdc++.h>
main(){int x;std::cin>>x;std::cout<<(x-(x&1^1)*(1<<((int)floor(log2(x)))))/2;}