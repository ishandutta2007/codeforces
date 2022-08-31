#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,sum,cur=1,zero;
map<char,int> num;
vector<pair<int,char>/**/> all;
string st;
set<char> s;
int qp(int x,int y)
{
	if (y==0) return 1;
	int t=qp(x,y/2);
	if (y&1) return sqr(t)*x; else return sqr(t);
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		s.insert(st[0]);
		reverse(st.begin(),st.end());
		for (j=0;j<st.length();j++)
		{
			num[st[j]]+=qp(10,j);
		}
	}
	for (char i='a';i<='j';i++)
	{
		all.push_back(make_pair(num[i],i));
	}
	sort(all.begin(),all.end(),greater<pair<int,char>/**/>());
	for (i=0;i<all.size();i++)
	{
		cerr<<all[i].first<<' '<<all[i].second<<endl;
		if (!(zero||s.count(all[i].second))){zero=1;continue;}
		sum+=all[i].first*(i+1-zero);
	}
	cout<<sum<<endl;
	return 0;
}