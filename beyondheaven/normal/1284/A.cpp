#include<iostream>
#include<string>
#define MaxN 200
int n,m,q;
std::string s[MaxN],t[MaxN];
int main()
{
	std::cin>>n>>m;
	for(int i=1;i<=n;++i)
	std::cin>>s[i];
	for(int i=1;i<=m;++i)
	std::cin>>t[i];
	std::cin>>q;
	for(int i=1,y;i<=q;++i)
	{
		std::cin>>y;
		std::cout<<s[(y-1)%n+1]<<t[(y-1)%m+1]<<std::endl;
	}
	return 0;
}