#include <bits/stdc++.h>

using namespace std;

string h;
int rj;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>h;
	for (int i=0;i<h.size();++i)
	{
		if (h[i]=='a' || h[i]=='e' || h[i]=='i' || h[i]=='o' || h[i]=='u' || h[i]=='1' || h[i]=='3' || h[i]=='5' || h[i]=='7' || h[i]=='9') ++rj;
	}
	cout<<rj<<endl;
}