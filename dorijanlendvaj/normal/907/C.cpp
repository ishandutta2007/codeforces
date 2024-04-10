#include <bits/stdc++.h>

using namespace std;

int n,ti;
bool fo;
char ac;
string cu;
bool moz[101];
bool app[101];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<26;++i) moz[i]=1;
	for (int i=0;i<n;++i)
	{
		if (i==n-1)
		{
			cout<<ti<<endl;
			break;
		}
		cin>>ac>>cu;
		if (ac=='.')
		{
			for (int j=0;j<cu.size();++j) moz[cu[j]-'a']=0;
		}
		if (ac=='!')
		{
			if (fo) ++ti;
			else
			{
				for (int j=0;j<26;++j) app[j]=0;
				for (int j=0;j<cu.size();++j) app[cu[j]-'a']=1;
				for (int j=0;j<26;++j) if (!app[j]) moz[j]=0;
			}
		}
		if (ac=='?')
		{
			if (fo) ++ti;
			else moz[cu[0]-'a']=0;
		}
		int mog1=0;
		for (int j=0;j<26;++j)
		{
			if (moz[j])
			{
				++mog1;
			}
		}
		if (mog1==1)
		{
			fo=1;
		}
	}
}