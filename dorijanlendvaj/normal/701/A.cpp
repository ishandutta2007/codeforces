#include <bits/stdc++.h>

using namespace std;

int n;
int h[101];
int z,d;
bool done[101];

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		z+=h[i];
	}
	z*=2;
	z/=n;
	for (int i=0;i<n;++i)
	{
		if (!done[i])
		{
			d=z-h[i];
			for (int j=i+1;j<n;++j)
			{
				if (h[j]==d && !done[j])
				{
					cout<<i+1<<' '<<j+1<<endl;
					done[i]=1;
					done[j]=1;
					break;
				}
			}
		}
	}
}