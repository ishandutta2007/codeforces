#include <bits/stdc++.h>

using namespace std;

string h;

bool pal()
{
	for (int i=0;i<h.size()/2;++i)
	{
		if (h[i]!=h[h.size()-i-1]) return false;
	}
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>h;
	bool moz=pal();
	for (int i=0;i<10;++i)
	{
		h.insert(0,1,'0');
		moz|=pal();
	}
	if (moz) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}