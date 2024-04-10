#include <bits/stdc++.h>

using namespace std;

vector<int> sols;
int n;

int zzn(int x)
{
	int rj=0;
	while (x)
	{
		rj+=x%10;
		x/=10;
	}
	return rj;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=n-1;i>=n-100;--i)
	{
		if (i+zzn(i)==n) sols.push_back(i);
	}
	reverse(sols.begin(),sols.end());
	cout<<sols.size()<<endl;
	for (int i=0;i<sols.size();++i) cout<<sols[i]<<endl;
}