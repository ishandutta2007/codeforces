#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n;
int f[100001];

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>f[i];
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (j%2==0) ++f[j];
			else --f[j];
			if (f[j]<0) f[j]+=n;
			if (f[j]>=n) f[j]-=n;
		}
		bool tempfake=false;
		for (int j=0;j<n;++j) if (f[j]!=j) tempfake=true;
		if (!tempfake)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}