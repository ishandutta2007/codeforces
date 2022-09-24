#include <bits/stdc++.h>

using namespace std;

long long fakt(long long a)
{
	if (a==0) return 1;
	return a*fakt(a-1);
}

int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<fakt(min(a,b))<<endl;
}