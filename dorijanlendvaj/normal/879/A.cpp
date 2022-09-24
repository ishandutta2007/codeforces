#include <bits/stdc++.h>

using namespace std;

int cur,n;
int s,d;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>s>>d;
		for (int j=s;;j+=d)
		{
			if (j>cur)
			{
				cur=j;
				break;
			}
		}
	}
	cout<<cur<<endl;
}