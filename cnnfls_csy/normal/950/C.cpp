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
int n,m,i,j,cnt,sz;
struct BIT
{
	int arr[200005];
	int lowbit(int x) {return x&(-x);}
	void add(int x,int y)
	{
		for (int i=x;i<=200002;i+=lowbit(i)) arr[i]+=y;
	}
	int query()
	{
		int s=0,i;
		for (i=20;i>=0;i--)
		{
			s+=(1<<i);
			if (s>200002)
			{
				s-=(1<<i);
				continue;
			}
			if (arr[s])
			{
				s-=(1<<i);
				continue;
			}
		}
		return s+1;
	}
}sum,sum2;
string st;
vector<int> ans[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>st;
	for (i=0;i<st.size();i++)
	{
		if (st[i]=='0')
		{
			int add=sum.query();
			if (add>cnt)
			{
				cnt++;
				ans[cnt].push_back(i+1);
				sum2.add(cnt,1);
			}
			else
			{
				sum.add(add,-1);
				sum2.add(add,1);
				ans[add].push_back(i+1);
			}
			sz++;
		}
		else
		{
			if (!sz)
			{
				cout<<-1;
				return 0;
			}
			sz--;
			int add=min(sum2.query(),cnt);
			ans[add].push_back(i+1);
			sum.add(add,1);
			sum2.add(add,-1);
		}
	}
	if (sz!=cnt)
	{
		cout<<-1;
		return 0;
	}
	cout<<cnt<<endl;
	for (i=1;i<=cnt;i++)
	{
		cout<<ans[i].size();
		for (j=0;j<ans[i].size();j++) cout<<' '<<ans[i][j];
		cout<<endl;
	}
	return 0;
}