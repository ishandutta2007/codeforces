#include <bits/stdc++.h>

using namespace std;

int n,m;
int mini;
vector<int> rj;
vector<int> tem;
string a,b;

int main()
{
	cin>>n>>m>>a>>b;
	mini=1000001;
	for (int i=0;i<=m-n;++i)
	{
		int temp=0;
		tem.clear();
		for (int j=0;j<n;++j)
		{
			if (b[i+j]!=a[j])
			{
				++temp;
				tem.push_back(j+1);
			}
		}
		if (temp<mini)
		{
			mini=temp;
			rj=tem;
		}
	}
	cout<<mini<<endl;
	for (int i=0;i<rj.size();++i) cout<<rj[i]<<' ';
	cout<<endl;
}