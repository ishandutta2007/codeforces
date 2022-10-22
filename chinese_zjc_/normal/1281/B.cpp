//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n;
string s,c;
bool flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		cin>>s>>c;
		int len=s.length();
		for(int i=0;i<len;++i)
		{
			int MAX=i;
			for(int j=len-1;j>i;--j)
			{
				if(s[MAX]>s[j])
				{
					MAX=j;
				}
			}
			if(MAX!=i)
			{
				swap(s[MAX],s[i]);
				break;
			}
		}
		if(s<c)
		{
			cout<<s<<endl;
		}
		else
		{
			cout<<"---"<<endl;
		}
	}
	return 0;
}