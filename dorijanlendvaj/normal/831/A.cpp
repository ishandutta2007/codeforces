#include <bits/stdc++.h>

using namespace std;

int n;
int h[101];
int sta;
bool moz;

int main()
{
	std::cin.sync_with_stdio(false);
	moz=true;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		if (i)
		{
			if (sta==0 && h[i]<=h[i-1]) sta=1;
			if (sta==1 && h[i]<h[i-1]) sta=2;
			if (sta==1 && h[i]>h[i-1]) moz=false;
			if (sta==2 && h[i]>=h[i-1]) moz=false;
		}
	}
	if (moz) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}