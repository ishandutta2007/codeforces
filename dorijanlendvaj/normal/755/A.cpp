#include <bits/stdc++.h>

using namespace std;

int n;

bool prim(int a)
{
	for (int e=2;e<=sqrt(a);++e)
	{
		if (a%e==0) return false;
	}
	return true;
}

int main()
{
	cin>>n;
	for (int i=1;i<=1000;++i)
	{
		if (!prim(n*i+1))
		{
			cout<<i<<endl;
			break;
		}
	}
}