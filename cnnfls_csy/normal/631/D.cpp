#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#define sqr(x) (x)*(x)
using namespace std;
//vector<string> s1,s2;
vector<pair<char,long long>/**/> s1,s2,all;
char ch;
long long n,m,i,j,pos,x,ans,np,ns,l,r,z[400005];
double ti;
int main()
{
	//ti=clock();
	//freopen("1.out","r",stdin);
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d-%c",&x,&ch);
		if (!s1.empty()&&s1.back().first==ch) s1.back().second+=x;
			else s1.push_back(make_pair(ch,x));
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d-%c",&x,&ch);
		if (!s2.empty()&&s2.back().first==ch) s2.back().second+=x;
			else s2.push_back(make_pair(ch,x));
	}
	//cerr<<clock()-ti<<endl;
	if (s2.size()==1)
	{
		for (i=0;i<s1.size();i++)
		{
			if (s1[i].first==s2[0].first&&s2[0].second<=s1[i].second)
			{
				ans+=s1[i].second-s2[0].second+1;
			}
		}
		printf("%I64d\n",ans);
		return 0;
	}
	//cerr<<clock()-ti<<endl;
	if (s2.size()==2)
	{
		for (i=0;i+1<s1.size();i++)
		{
			if (s1[i].first==s2[0].first&&s2[0].second<=s1[i].second)
			{
				if (s1[i+1].first==s2[1].first&&s2[1].second<=s1[i+1].second)
				{
					ans++;
				}
			}
		}
		printf("%I64d\n",ans);
		return 0;
	}
	//cerr<<clock()-ti<<endl;
	for (i=1;i+1<s2.size();i++) all.push_back(s2[i]);
	all.push_back(make_pair('@',-1));
	for (i=0;i<s1.size();i++) all.push_back(s1[i]);
	//cerr<<clock()-ti<<endl;
	int t=all.size();
	int cnt=0;
	for (i=1;i<t;i++)
	{
		if (i<=r)
		{
			z[i]=min(z[i-l],r-i);
			//cnt++;
		}
		while (i+z[i]<t&&all[z[i]].first==all[i+z[i]].first&&all[z[i]].second==all[i+z[i]].second)
		{
			z[i]++;//cnt++;
		}
		if (i+z[i]-1>r)//i>r tle
		{
			l=i;
			r=i+z[i]-1;
			//cnt++;
		}
		//cerr<<cnt<<endl;
		//if (i%1000==0) cerr<<i<<' '<<cnt<<endl;
		/*if (i==100000)
		{
			cnt++;
			cnt--;
		}*/
	}
	//cerr<<cnt<<endl;
	/*for (i=0;i<all.size();i++) cerr<<all[i].first<<'-'<<all[i].second<<' ';
	cerr<<endl;
	for (i=0;i<all.size();i++) cerr<<z[i]<<' ';
	cerr<<endl;*/
	//cerr<<clock()-ti<<endl;
	for (i=0;all[i].first!='@';i++);
	for (i++;i+s2.size()-2<all.size();i++)
	{
		if (z[i]==s2.size()-2)
		{
			if (all[i-1].first==s2[0].first&&all[i-1].second>=s2[0].second)
			{
				if (all[i+s2.size()-2].first==s2.back().first&&all[i+s2.size()-2].second>=s2.back().second)
				{
					ans++;
				}
			}
		}
	}
	//cerr<<clock()-ti<<endl;
	printf("%I64d\n",ans);
	return 0;
}