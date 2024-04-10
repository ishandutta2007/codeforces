#include <bits/stdc++.h>

using namespace std;

int t,n;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>t;
	while (t--)
	{
		cin>>n;
		if (n<4 || (n%2 && n!=9 && n<12)) cout<<-1<<endl;
		else
		{
			int rj=0;
			if (n%2)
			{
				n-=9;
				++rj;
			}
			if (n%4)
			{
				n-=6;
				++rj;
			}
			cout<<rj+n/4<<endl;
		}
	}
}