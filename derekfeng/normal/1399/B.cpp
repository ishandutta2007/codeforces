#include<bits/stdc++.h>
long long i,n,s,t,x,y,a[60],b[60];
main(){for(std::cin>>t;t--;){std::cin>>n;for(i=0,x=y=1e9;i++<n;)std::cin>>a[i],x=std::min(x,a[i]);for(i=0;i++<n;)std::cin>>b[i],y=std::min(y,b[i]);for(i=s=0;i++<n;)s+=std::max(a[i]-x,b[i]-y);std::cout<<s<<'\n';}}