#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		for(int i=0;i<n;i++) a[i]=s[i]-'0';
		bool ok=1;
		for(int tar=0;tar<=9;tar++)
		{
			ok=1;
			vector<int> col(n);
			vector<int> c1,c2;
			int last=-1,fi=n;
			for(int i=0;i<n;i++)
			{
				if(a[i]<tar)
				{
					last=i;
					col[i]=1;
					c1.push_back(i);
				}
				else if(a[i]>tar)
				{
					fi=min(fi,i);
					col[i]=2;
					c2.push_back(i);
				}
			}
			vector<int> tmp;
			for(int i=0;i<n;i++)
			{
				if(a[i]==tar)
				{
					if(i>last) {
						col[i]=1;
						c1.push_back(i);
					}
					else if(i<fi) {
						col[i]=2;
						tmp.push_back(i);
					}
					else {
						ok=0;
						break;
					}
				}
			}
			for(auto u:c2) tmp.push_back(u);
			c2=tmp;
			for(int i=1;i<c1.size();i++)
				if(a[c1[i]]<a[c1[i-1]]) ok=0;
			for(int i=1;i<c2.size();i++)
				if(a[c2[i]]<a[c2[i-1]]) ok=0;
			if(ok)
			{
				for(int i=0;i<n;i++)
					cout<<col[i];
				cout<<endl;
				break;
			}
		}
		if(!ok) cout<<'-'<<endl;
	}
}