#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j;
vector<int> cnt;
string st,lim,ans;
void dfs(int x,string st,bool up,vector<int> cnt2)
{
	if (x==lim.size())
	{
		if (st<=lim) ans=max(ans,st);
		return;
	}
	int i;
	if (!up)
	{
		int j;
//	cerr<<st<<endl;
		for (j=9;!cnt2[j];j--);//cerr<<cnt2[j]<<' '<<j<<endl; 
		while (x<lim.size())
		{
			while (!cnt2[j]) j--;
			cnt2[j]--;
			st.push_back(j+'0');
			x++;
//	cerr<<st<<endl;
		}
		if (st<=lim) ans=max(ans,st);
		return;
	}
	for (i=0;i<=lim[x]-'0';i++)
	{
		if (cnt2[i])
		{
			cnt2[i]--;
			string st1=st;
			//cerr<<st1<<" "<<i<<endl;
			st1.push_back(i+'0');
			//cerr<<st1<<" "<<i<<endl;
			dfs(x+1,st1,i==lim[x]-'0',cnt2);
			cnt2[i]++;
		}
	}
}
int main()
{
	cin>>st>>lim;
	if (lim.size()>st.size())
	{
		sort(st.begin(),st.end());
		reverse(st.begin(),st.end());
		cout<<st;
		return 0;
	}
	for (i=0;i<=9;i++) cnt.push_back(0);
	for (i=0;i<st.length();i++) cnt[st[i]-'0']++;
	dfs(0,"",1,cnt);
	cout<<ans;
	return 0;
}