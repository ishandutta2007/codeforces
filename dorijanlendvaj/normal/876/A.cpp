#include <bits/stdc++.h>

using namespace std;

int n,a,b,c,u;
int rj;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>a>>b>>c;
	for (int i=1;i<n;++i)
	{
		if (u==0)
		{
			if (a<b)
			{
				rj+=a;
				u=1;
			}
			else
			{
				rj+=b;
				u=2;
			}
		}
		else if (u==1)
		{
			if (a<c)
			{
				rj+=a;
				u=0;
			}
			else
			{
				rj+=c;
				u=2;
			}
		}
		else
		{
			if (b<c)
			{
				rj+=b;
				u=0;
			}
			else
			{
				rj+=c;
				u=1;
			}
		}
	}
	cout<<rj<<endl;
}