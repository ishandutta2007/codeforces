#include<bits/stdc++.h>
int i,t,n,a,b,c;
int main(){for(std::cin>>t;t--;){std::cin>>n>>a>>b;for(i=2;i++<n&&std::cin>>c;)a*(c-a||c-b)?std::cout<<(c-a&&c-b?i:2-(a!=c))<<'\n',a=0:0;}}