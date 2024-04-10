#include <bits/stdc++.h>

using namespace std;

int a,b,f,k,c,rj;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a>>b>>f>>k;
	c=b;
	for (int i=0;i<k;++i)
	{
		if (i%2==0)
		{
			if (c<f || b<a-f)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		else
		{
			if (c<a-f || b<f)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		if (i<k-1)
		{
			if (i%2==0)
			{
				if (f>c)
				{
					cout<<-1<<endl;
					return 0;
				}
				if (a*2-f>c)
				{
					++rj;
					c=b+f;
				}
			}
			else
			{
				if (a-f>c)
				{
					cout<<-1<<endl;
					return 0;
				}
				if (a+f>c)
				{
					++rj;
					c=b+(a-f);
				}
			}
			c-=a;
		}
		else
		{
			if (c<a) ++rj;
		}
		//cout<<c<<endl;
	}
	cout<<rj<<endl;
}