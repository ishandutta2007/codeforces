#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[100005];
vector<int>v2[100005];
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
map<int,int>nxt[100005];
long long dis[100005];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<100005;i++)
		dis[i]=LONG_LONG_MAX;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d",&a);
//	cout<<"HI";
		for(int j=0;j<a;j++)
			scanf("%d",&b),
			v2[i].push_back(int(b));
		if(a){
			nxt[i][v2[i][v2[i].size()-1]]=v2[i][v2[i].size()-1]+1;
			for(int j=v2[i].size()-2;j>=0;j--)
				if(v2[i][j]+1!=v2[i][j+1])
					nxt[i][v2[i][j]]=v2[i][j]+1;
				else
					nxt[i][v2[i][j]]=nxt[i][v2[i][j+1]];
			for(int j=v2[i].size()-1;j>=0;j--)nxt[i][v2[i][j]]-=v2[i][j];//cout<<nxt[i][v2[i][j]]<<' ';
		//	cout<<endl;
		}
	}
	dis[0]=nxt[0][0];
	q.push(make_pair(nxt[0][0],0));
	while(!q.empty()){
		pair<int,int>y=q.top();
		int x=q.top().second;
		q.pop();
		for(int i=0;i<v[x].size();i++)
			if(dis[v[x][i].first]>dis[x]+v[x][i].second+(v[x][i].first==n-1?0:nxt[v[x][i].first][dis[x]+v[x][i].second]))
			{
				dis[v[x][i].first]=dis[x]+v[x][i].second+(v[x][i].first==n-1?0:nxt[v[x][i].first][dis[x]+v[x][i].second]);
				q.push(make_pair(dis[v[x][i].first],v[x][i].first));
			}
	}
	if(dis[n-1]==LONG_LONG_MAX)
		cout<<-1;
	else
		cout<<dis[n-1];
}