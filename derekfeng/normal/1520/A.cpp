#include<bits/stdc++.h>
int t,i,j,k,f,n;std::string s;
main(){for(std::cin>>t;t--;){std::cin>>n>>s,f=0;for(i=0;i<n;i++)for(j=i+1;j<n;j++)for(k=i+1;k<j;k++)if(s[i]==s[j]&&s[i]!=s[k])f=1;puts(f?"NO":"YES");}}