#include<bits/stdc++.h>
using namespace std;
int dis[3][200003],n,m;
long long val[200003];
vector<int>v[200003];
void BFS(int x,int a)
{
	dis[a][x]=0;
	queue<int>Q;
	Q.push(x);
	while(!Q.empty())
	{
		int nw=Q.front(),len=dis[a][nw];
		Q.pop();
		for(int i=0;i<v[nw].size();i++)
			if(dis[a][v[nw][i]]==-1)
			{
				dis[a][v[nw][i]]=len+1;
				Q.push(v[nw][i]);
			}
	}
}
void solve(){
	int x,y,z;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
	x--;
	y--;
	z--;
	for(int i=0;i<n;i++)
		v[i].clear();
	for(int i=0;i<=m;i++)
		val[i]=0;
	for(int i=1;i<=m;i++)
		scanf("%d",val+i);
	sort(val+1,val+m+1);
	for(int i=1;i<=m;i++)
		val[i]+=val[i-1];
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dis,-1,sizeof(dis));
	BFS(x,0);
	BFS(y,1);
	BFS(z,2);
	long long ans=2333333333333333333;
	for(int i=0;i<n;i++)
		if(dis[0][i]+dis[1][i]+dis[2][i]<=m)
			ans=min(ans,val[dis[1][i]]+val[dis[0][i]+dis[1][i]+dis[2][i]]);
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
}