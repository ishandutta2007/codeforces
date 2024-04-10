#include<bits/stdc++.h>
using namespace std;
queue<pair<int,string> >card;
vector<string>ans[103];
int n,t,m,c[103],a[103][2],b[103][2],d[103][103];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>t;
	for(int i=0;i<n;i++)
		cin>>a[i][0]>>b[i][0]>>a[i][1]>>b[i][1];
	cin>>m;
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s>>c[i];
		card.push(make_pair(i,s));
	}
	int T=t,k=0,x=0;
	while(card.size())
	{
		bool end=0;
		pair<int,string>q=card.front();
		card.pop();
		int st=max(1,c[q.first]-a[k][x]-b[k][!x]-d[k][q.first]);
		if(st<=T)
		{
			ans[k].push_back(q.second),
			T-=st;
			if(!T)end=1;
		}
		else
		{
			d[k][q.first]+=T;
			card.push(q);
			end=1;
		}
		if(end)
		{
			k=(k+1)%n;
			if(!k)x=!x;
			T=t;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i].size();
		for(int j=0;j<ans[i].size();j++)
			cout<<' '<<ans[i][j];
		cout<<endl;
	}
}