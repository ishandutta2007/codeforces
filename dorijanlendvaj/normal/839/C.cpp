#include <bits/stdc++.h>

using namespace std;

int n,a,b;
double rj;
vector<int> sus[100001];
queue<int> qu;
int ud[100001];
double pro[100001];
bool bio[100001];

void bfs()
{
	qu.push(0);
	while (qu.size())
	{
		int to=qu.front();
		qu.pop();
		int dj=0;
		for (int i=0;i<sus[to].size();++i)
		{
			if (bio[sus[to][i]]) continue;
			++dj;
		}
		for (int i=0;i<sus[to].size();++i)
		{
			if (bio[sus[to][i]]) continue;
			ud[sus[to][i]]=ud[to]+1;
			qu.push(sus[to][i]);
			pro[sus[to][i]]=pro[to]/dj;
		}
		bio[to]=true;
		if (dj==0) rj+=pro[to]*ud[to];
	}
}

int main()
{
	cin>>n;
	for (int i=0;i<n-1;++i)
	{
		cin>>a>>b;
		--a;
		--b;
		sus[a].push_back(b);
		sus[b].push_back(a);
	}
	pro[0]=1;
	bfs();
	cout<<fixed<<setprecision(10)<<rj<<endl;
}