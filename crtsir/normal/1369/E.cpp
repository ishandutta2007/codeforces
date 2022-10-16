#include<bits/stdc++.h>
using namespace std;
int n,m,w[100003],s[100003];
vector<pair<int,int> >v[200003];
bool vis[100003],vist[200003];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>w[i];
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		v[a].push_back(make_pair(b,i+1));
		v[b].push_back(make_pair(a,i+1));
		s[a]++;
		s[b]++;
	}
	queue<int>Q;
	for(int i=0;i<n;i++)
		if(w[i]>=s[i])
		{
			Q.push(i);
			vis[i]=1;
		}
	vector<int>ans;
	while(!Q.empty())
	{
		int nw=Q.front();
		Q.pop();
		vector<int>tmp;
		for(int i=0;i<v[nw].size();i++)
			if(!vist[v[nw][i].second-1])
			{
				s[v[nw][i].first]--;
				tmp.push_back(v[nw][i].first);
				ans.push_back(v[nw][i].second);
				vist[v[nw][i].second-1]=1;
			}
		for(int i=0;i<tmp.size();i++)
			if(w[tmp[i]]>=s[tmp[i]]&&!vis[tmp[i]])
			{
				Q.push(tmp[i]);
				vis[tmp[i]]=1;
			}
	}
	if(ans.size()==m)
	{
		cout<<"AlIVE\n";
		for(int i=m-1;i>=0;i--)
			cout<<ans[i]<<' ';
	}
	else
		cout<<"DEAD";
}