#include <bits/stdc++.h>

using namespace std;

int di1[5001];
int di2[5001];
int n;
int pos1,pos2;
long long res;

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>pos1>>pos2;
		++di1[pos1+pos2-2];
		++di2[pos1-pos2+999];
	}
	for (int i=0;i<=1998;++i)
	{
		res+=(di1[i]*(di1[i]-1))/2;
		res+=(di2[i]*(di2[i]-1))/2;
	}
	cout<<res<<endl;
}