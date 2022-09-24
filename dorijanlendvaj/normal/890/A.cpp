#include <bits/stdc++.h>

using namespace std;

int h[11];
int s;

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (int i=0;i<6;++i)
	{
		cin>>h[i];
		s+=h[i];
	}
	if (s%2)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		for (int i=0;i<6;++i)
		{
			for (int j=i+1;j<6;++j)
			{
				for (int k=j+1;k<6;++k)
				{
					if (h[i]+h[j]+h[k]==s/2)
					{
						cout<<"YES"<<endl;
						return 0;
					}
				}
			}
		}
		cout<<"NO"<<endl;
	}
}