#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
int gr[511];
vector<int> h;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	h.resize(n);
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
	}
	int i;
	for (i=0;i<n-1;++i)
	{
		/*for (int j=0;j<n;++j)
		{
			cout<<h[j]<<' '<<gr[h[j]]<<endl;
		}
		cout<<endl;*/
		if (h[0]>h[1])
		{
			++gr[h[0]];
			gr[h[1]]=0;
			int la=h[1];
			h.erase(h.begin()+1);
			h.push_back(la);
		}
		else
		{
			++gr[h[1]];
			gr[h[0]]=0;
			int la=h[0];
			h.erase(h.begin());
			h.push_back(la);
		}
		/*for (int j=0;j<n;++j)
		{
			cout<<h[j]<<' '<<gr[h[j]]<<endl;
		}
		cout<<endl<<endl;*/
		if (gr[h[0]]==k)
		{
			cout<<h[0]<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
}