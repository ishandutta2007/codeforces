#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
int n;
inline std::string& Normal(std::string&str)
{
	std::sort(str.begin(),str.end());
	return str;
}
int main()
{
	std::cin>>n;
	if(n==1)
	{
		std::string str;
		std::cout<<"? 1 1"<<std::endl;
		std::cout.flush();
		std::cin>>str;
		std::cout.flush();
		std::cout<<"! "<<str<<std::endl;
		return 0;
	}
	std::multiset<std::string>s;
	std::cout<<"? "<<1<<' '<<n<<std::endl;
	std::cout.flush();
	for(int i=1;i<=n*(n+1)/2;++i)
	{
		std::string str;
		std::cin>>str;
		s.insert(Normal(str));
	}
	std::cout<<"? "<<2<<' '<<n<<std::endl;
	std::cout.flush();
	for(int i=1;i<=n*(n-1)/2;++i)
	{
		std::string str;
		std::cin>>str;
		s.erase(s.find(Normal(str)));
	}
	std::vector<std::string>v;
	for(auto str:s)v.push_back(str);
	auto cmp=[](std::string a,std::string b){return a.length()<b.length();};
	std::sort(v.begin(),v.end(),cmp);
	std::string ans=v[0];
	std::map<char,int>mp;
	for(int i=1;i<n;++i)
	{
		for(auto c:v[i])++mp[c];
		for(auto c:v[i-1])--mp[c];
		for(char c='a';c<='z';++c)
		if(mp[c]!=0)
		{
			ans=ans+c;
			mp[c]--;
		}
	}
	std::cout<<"! "<<ans<<std::endl;
	return 0;
}