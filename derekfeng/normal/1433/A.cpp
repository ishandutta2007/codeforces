#import<bits/stdc++.h>
int n,t,x;main(){for(std::cin>>t;t--;)std::cin>>n,std::cout<<10*(n%10-1)+(x=log(n)/log(10)+1)*(x+1)/2<<'\n';}