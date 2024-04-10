#include <bits/stdc++.h>
using namespace std;

const int maxn=1000+10;

int n,l,k;
string s;

int cnt[30]={0};


vector<int> v;

char ans[maxn][maxn]={0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>l>>k>>s;
	for(int i=0;i<s.length();i++)
		cnt[s[i]-'a']++;

	int nowi=1,nowj=1,top=1;
	for(int i=0;i<26;i++)
	{
		bool flag=false;
		while(cnt[i])
		{
//			cout<<"nowi: "<<nowi<<" nowj: "<<nowj<<endl;
			ans[nowi][nowj]='a'+i;
			cnt[i]--;

			if(nowi==k&&nowj==l)
			{
				flag=true;
				break;
			}
			nowi++;
			if(nowi>k)
			{
				nowi=top;
				nowj++;
			}
		}
		if(flag)
			break;

		top=nowi;
		if(top>k)
			break;
	}
	for(int i=0;i<26;i++)
		while(cnt[i]--)
			v.push_back(i);

	int now=0;
	for(int i=1;i<=l;i++)
		if(ans[k][i]!=0)	continue;
		else	ans[k][i]=v[now]+'a',now++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=l;j++)
			if(ans[i][j]!=0)	continue;
			else				ans[i][j]=v[now]+'a',now++;
	}


	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=l;j++)
			cout<<ans[i][j];
		cout<<endl;
	}
	

}