//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,len;
string a;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		cin>>a;
		len=a.length();
		if(a[len-2]=='p'&&a[len-1]=='o')
		{
			cout<<"FILIPINO"<<endl;
			continue;
		}
		if(((a[len-4]=='d'&&a[len-3]=='e')||(a[len-4]=='m'&&a[len-3]=='a'))&&a[len-2]=='s'&&a[len-1]=='u')
		{
			cout<<"JAPANESE"<<endl;
			continue;
		}
		if(a[len-5]=='m'&&a[len-4]=='n'&&a[len-3]=='i'&&a[len-2]=='d'&&a[len-1]=='a')
		{
			cout<<"KOREAN"<<endl;
			continue;
		}
	}
	return 0;
}