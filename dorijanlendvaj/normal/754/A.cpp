#include <bits/stdc++.h>

using namespace std;

int n;
int h[1001];
int nu;
int su;
int poc;
bool mog;
vector<pair<int,int> > rje;

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		if (h[i]!=0) mog=true;
	}
	if (!mog) cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		poc=1;
		for (int i=0;i<n;++i)
		{
			su+=h[i];
			if (su==0)
			{
				if (su-h[i]!=0)
				{
					rje.push_back(make_pair(poc,i));
					++nu;
					poc=i+1;
					su=h[i];
				}
			}
		}
		if (poc<=n)
		{
			rje.push_back(make_pair(poc,n));
			++nu;
		}
		cout<<nu<<endl;
		for (int i=0;i<nu;++i) cout<<rje[i].first<<' '<<rje[i].second<<endl;
	}
}