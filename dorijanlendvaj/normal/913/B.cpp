#include <bits/stdc++.h>

using namespace std;

vector<int> ch[1001];
int n;
int p[1001];
bool d=true;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n-1;++i)
	{
		cin>>p[i+1];
		--p[i+1];
		ch[p[i+1]].push_back(i+1);
	}
	for (int i=0;i<n;++i)
	{
		int nk=0;
		for (int j=0;j<ch[i].size();++j)
		{
			if (!ch[ch[i][j]].size())
			{
				++nk;
			}
		}
		if (nk<3 && ch[i].size())
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}