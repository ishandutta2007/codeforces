#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<map>
#define sqr(x) (x)*(x)
#define mk(x,y,z) make_pair(make_pair(x,y),z)
using namespace std;
int n,m,i,j,k,l,x,len;
vector<int> num,nxt;
vector<pair<pair<int,int>,int>/**/> ans;
bool ok=0;
//map<vector<int>,vector<int>/**/> pre;
void dfs(vector<int> num,int x)
{
	if (x>len)
	{
		return;
	}
	int i,j,k;
	for (i=0;i<num.size()&&!ok;i++)
	{
		for (j=0;j<num.size()&&!ok;j++)
		{
			for (k=1;k<=8&&!ok;k*=2)
			{
				//cerr<<"-----"<<i<<' '<<j<<' '<<num.size()<<' '<<num[i]<<' '<<num[j]<<' '<<k<<' '<<num[i]+num[j]*k<<endl;
				nxt=num;
				nxt.push_back(num[i]+num[j]*k);
				//cerr<<"-----"<<nxt.back()<<' '<<nxt.back()==n<<endl;
				//for (i=0;i<nxt.size();i++) cerr<<nxt[i]<<' ';
				//cerr<<endl;
				//system("pause");
				//pre[nxt]=num;
				if (nxt.back()==n) {ok=1;return;}
				dfs(nxt,x+1);
				if (ok) return;
			}
		}
	}
	for (i=0;i<num.size()&&!ok;i++)
	{
		for (k=1;k<=8&&!ok;k*=2)
		{
			nxt=num;
			nxt.push_back(num[i]*k);
			//pre[nxt]=num;
			if (nxt.back()==n) {ok=1;return;}
			dfs(nxt,x+1);
			if (ok) return;
		}
	} 
}
int main()
{
	cin>>n;
	if (n==1)
	{
		cout<<"0";
		return 0;
	}
	for (len=1;!ok;len++)
	{
		num.clear();
		num.push_back(1);
		dfs(num,1);
	}
	num=nxt;
	for (i=1;i<=len;i++)
	{
		bool ok=0;
		for (j=0;j<num.size()-1&&!ok;j++)
		{
			for (k=0;k<num.size()-1&&!ok;k++)
			{
				for (l=1;l<=8&&!ok;l*=2)
				{
					if (num[j]+num[k]*l==num.back())
					{
						ans.push_back(mk(j,k,l));
						ok=1;
					}
				}
			}
		}
		for (k=0;k<num.size()-1&&!ok;k++)
		{
			for (l=1;l<=8&&!ok;l*=2)
			{
				if (num[k]*l==num.back())
				{
					ans.push_back(mk(-1,k,l));
					ok=1;
				}
			}
		}
		num.pop_back();
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for (i=0;i<ans.size();i++)
	{
		//cerr<<ans[i].first.first<<' '<<ans[i].first.second<<' '<<ans[i].second<<endl;
		cout<<"lea e"<<((char)(i+'b'))<<"x, [";
		if (ans[i].first.first==-1)
		{
			cout<<ans[i].second<<"*e"<<((char)(ans[i].first.second+'a'))<<"x";
		}
		else
		{
			cout<<"e"<<((char)(ans[i].first.first+'a'))<<"x + "<<ans[i].second<<"*e"<<((char)(ans[i].first.second+'a'))<<"x";
		}
		cout<<"]"<<endl;
	}
	return 0;
}