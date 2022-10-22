#include<bits/stdc++.h>
int n,m,q,x;
std::string s[100],t[100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)std::cin>>s[i];
	for(int i=1;i<=m;i++)std::cin>>t[i];
	for(scanf("%d",&q);q--;){
	  scanf("%d",&x);
	  std::cout<<s[(x-1)%n+1]<<t[(x-1)%m+1]<<std::endl;
	}
	return 0;
}