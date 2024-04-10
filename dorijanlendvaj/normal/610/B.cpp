#include <bits/stdc++.h>

using namespace std;

#define int long long

int mini,m1;
int dist;
int f[200001];
int n;
int pos;

signed main()
{
	cin>>n;
	mini=1<<30;
	for (int i=0;i<n;++i) cin>>f[i],mini=min(mini,f[i]);
	for (int i=0;i<n;++i) if (f[i]==mini)
	{
		pos = i;
		break;
	}
	for (int i=n-1;i>=0;--i)
	{
		if (f[i] == mini)
			pos = i;
		dist = (pos - i + n) % n;
		m1=max(m1,n*mini+dist);
	}
	cout<<m1<<endl;
}