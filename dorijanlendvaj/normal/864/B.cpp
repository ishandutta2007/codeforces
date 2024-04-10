#include <bits/stdc++.h>

using namespace std;

string h;
int n;
int rj;
set<char> dis;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>h;
	for (int i=0;i<n;++i)
	{
		if (h[i]<'a') continue;
		dis.clear();
		while (h[i]>='a')
		{
			dis.insert(h[i]);
			++i;
		}
		rj=max(rj,int(dis.size()));
	}
	cout<<rj<<endl;
}