#include<bits/stdc++.h>
using namespace std;
vector<int>ans,e[303];
int n,a,b,x,y;
void make_queue(int from,int to)
{
	queue<vector<int> >q;
	vector<int>V;
	V.push_back(from);
	q.push(V);
	while(q.front()[q.front().size()-1]!=to){
		vector<int>v=q.front();
		int m=q.front().size()-1;
		for(int i=0;i<e[v[m]].size();i++)
			if(v.size()<2||v[v.size()-2]!=e[v[m]][i])
			{
				v.push_back(e[v[m]][i]);
				q.push(v);
				v.pop_back();
			}
		q.pop();
	}
	for(int i=1;i<q.front().size();i++)
		ans.push_back(q.front()[i]);
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	x=0;
	ans.push_back(0);
	while(cin>>y)
	{
		make_queue(x,y-1);
		x=y-1;
	}
	make_queue(y-1,0);
	if(ans.size()!=n*2-1)
		cout<<-1;
	else
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]+1<<' ';
}