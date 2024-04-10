#import<bits/stdc++.h>
int i,m,n,t,a[60];
main(){for(std::cin>>t;t--;){std::cin>>n;for(i=0;i++<n;)std::cin>>a[i];std::sort(a,a+i);for(i=0,m=999;++i<n;)m=std::min(m,a[i+1]-a[i]);std::cout<<m<<"\n";}}