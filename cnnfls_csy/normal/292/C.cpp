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
string st;
int n,m,i,j,len,used[15],x;
vector<string> ans;
vector<int> can;
bool check(int msk)
{
	int i;
	for (i=0;i<n;i++)
	{
		if (!(msk&(1<<i))) return 0;
	}
	return 1;
}
void getans(string st)
{
	int i,j,k,l;
	string st1,st2,st3,st4;
	//cerr<<st<<endl;
	for (i=1;i<st.length();i++)
	{
		for (j=i+1;j<st.length();j++)
		{
			for (k=j+1;k<st.length();k++)
			{
				st1=st2=st3=st4="";
				for (l=0;l<i;l++) st1.push_back(st[l]);
				for (l=i;l<j;l++) st2.push_back(st[l]);
				for (l=j;l<k;l++) st3.push_back(st[l]);
				for (l=k;l<st.length();l++) st4.push_back(st[l]);
				//cerr<<st1<<' '<<st2<<' '<<st3<<' '<<st4<<endl;
				if (st1.length()>3||st2.length()>3||st3.length()>3||st4.length()>3) continue;
				if (st1.length()==3&&st1>"255") continue;
				if (st2.length()==3&&st2>"255") continue;
				if (st3.length()==3&&st3>"255") continue;
				if (st4.length()==3&&st4>"255") continue;
				if (st1!="0"&&st1[0]=='0') continue;
				if (st2!="0"&&st2[0]=='0') continue;
				if (st3!="0"&&st3[0]=='0') continue;
				if (st4!="0"&&st4[0]=='0') continue;
				ans.push_back(st1+"."+st2+"."+st3+"."+st4);
			}
		}
	}
}
void dfs(int x,string st,int msk)
{
	if (x>=len)
	{
		if (check(msk)) getans(st);
		return;
	}
	int i,y=len-x-1;
	if (x>y)
	{
		string nxt=st;
		nxt.push_back(st[y]);
		dfs(x+1,nxt,msk);
	}
	else
	{
		for (i=0;i<can.size();i++)
		{
			used[i]++;
			string nxt=st;
			nxt.push_back(can[i]+'0');
			dfs(x+1,nxt,msk|(1<<i));
			used[i]--;
		}
	}
}
int main()
{
	cin>>n;
	if (n>6)
	{
		cout<<0;
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		cin>>x;
		can.push_back(x);
	}
	sort(can.begin(),can.end());
	reverse(can.begin(),can.end());
	for (i=4;i<=12;i++)
	{
		len=i;
		dfs(0,"",0);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for (i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}