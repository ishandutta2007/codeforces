#include <bits/stdc++.h>

using namespace std;

int n;
string h[100001];
vector<string> seq[100001];
unordered_map<string,int> m;
set<string> uz;
string l;

bool pr(string a,string b)
{
	if (a.size()>=b.size()) return false;
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		uz.clear();
		for (int j=0;j<9;++j)
		{
			l.clear();
			for (int k=j;k<9;++k)
			{
				l.push_back(h[i][k]);
				if (uz.find(l)==uz.end())
				{
					++m[l];
					seq[i].push_back(l);
					uz.insert(l);
				}
				//cout<<l<<' '<<m[l]<<endl;
			}
		}
		sort(seq[i].begin(),seq[i].end(),pr);
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<seq[i].size();++j)
		{
			if (m[seq[i][j]]==1)
			{
				cout<<seq[i][j]<<endl;
				break;
			}
		}
	}
}