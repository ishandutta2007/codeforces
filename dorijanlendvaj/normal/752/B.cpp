#include <bits/stdc++.h>

using namespace std;

map<char,pair<char,bool> > m;
int n;
string a,b;
pair<char,char> po[10001];

int main()
{
	cin>>a>>b;
	for (char e='a';e<='z';++e) m[e]=make_pair(e,false);
	for (int i=0;i<a.size();++i)
	{
		if (m[b[i]].first!=a[i] || m[a[i]].first!=b[i])
		{
			if (m[b[i]].second==true || m[a[i]].second==true)
			{
				cout<<-1<<endl;
				return 0;
			}
			else
			{
				po[n].first=a[i];
				po[n].second=b[i];
				++n;
			}
		}
		m[b[i]]=make_pair(a[i],true);
		m[a[i]]=make_pair(b[i],true);
	}
	cout<<n<<endl;
	for (int i=0;i<n;++i)
	{
		cout<<po[i].first<<' '<<po[i].second<<endl;
	}
}