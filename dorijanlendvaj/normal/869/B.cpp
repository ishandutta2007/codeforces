#include <bits/stdc++.h>

using namespace std;

long long a,b;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a>>b;
	long long c=b-a;
	if (c >= 5)
		cout<<0<<endl;
	else
	{
		int sol = 1;
		for (long long i = a + 1; i<=b; ++i)
			sol = sol * (i % 10) % 10;
		cout<<sol<<endl;
	}
}