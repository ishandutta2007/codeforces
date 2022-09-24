#include <bits/stdc++.h>

using namespace std;

int n,m,k,rj,rj1,ma;
bool h[101][101];
int nu[101];

int ch(int j)
{
	ma=0;
	int wh=0,o=0;
	for (int i=0;i<n;++i) nu[i]=0;
	for (int i=0;i<n;++i)
	{
		if (!h[i][j]) continue;
		for (int l=i;l<i+min(k,n-i);++l)
		{
			nu[i]+=h[l][j];
		}
		if (nu[i]>ma)
		{
			wh=o;
			ma=nu[i];
		}
		++o;
	}
	return wh;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) cin>>h[i][j];
	for (int j=0;j<m;++j)
	{
		rj1+=ch(j);
		rj+=ma;
	}
	cout<<rj<<' '<<rj1<<endl;
}