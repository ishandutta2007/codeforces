#include <bits/stdc++.h>

using namespace std;

int a,mi;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a;
	mi=1000000000;
	for (int i=1;i<=a;++i)
	{
		int j=(a+i-1)/i;
		mi=min(mi,i*2+j*2);
	}
	cout<<mi<<endl;
}