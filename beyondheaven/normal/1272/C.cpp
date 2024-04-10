#include<bits/stdc++.h>
typedef long long LL;
int main()
{
	std::ios::sync_with_stdio(false);
	
	int n,k;std::cin>>n>>k;
	std::string s;std::cin>>s;
	
	std::set<char>c;
	for(int i=0;i<k;++i)
	{
		char o;
		while((std::cin>>o),(!isalpha(o)));
		c.insert(o);
	}
	
	for(int i=0;i<n;++i)
	if(!c.count(s[i]))s[i]=' ';
	
	std::stringstream ss(s);
	LL ans=0;
	while(ss>>s)
	{
		LL o=s.length();
		ans+=o*(o+1)/2;
	}
	
	std::cout<<ans<<std::endl;
	return 0;
}