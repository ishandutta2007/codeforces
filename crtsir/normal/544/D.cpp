#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,s1,e1,l1,s2,e2,l2;
int dis[3003][3003];
vector<int>v[3003];
void bfs(int s){
	dis[s][s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		for(int i=0;i<v[q.front()].size();i++)
			if(dis[s][v[q.front()][i]]==538976288)
				dis[s][v[q.front()][i]]=dis[s][q.front()]+1,
				q.push(v[q.front()][i]);
		q.pop();
	}
}
int main(){
	cin>>n>>m;
	memset(dis,32,sizeof(dis));
	//cout<<dis[0][0]<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		v[--a].push_back(--b);
		v[b].push_back(a);
	}
	cin>>s1>>e1>>l1>>s2>>e2>>l2;
	s1--;s2--;e1--;e2--;
	swap(s2,e2);
	for(int i=0;i<n;i++)
		bfs(i);
	int ans=-1;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dis[i][j]<<' ';
		cout<<endl;
	}*/
	if(dis[s1][e1]>l1||dis[s2][e2]>l2){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dis[s1][i]+dis[i][j]+dis[j][e1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][e2]<=l2)
				ans=max(ans,m-dis[s1][i]-dis[i][j]-dis[j][e1]-dis[s2][i]-dis[j][e2]);
	ans=max(ans,m-dis[s1][e1]-dis[s2][e2]);
	swap(s1,e1);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dis[s1][i]+dis[i][j]+dis[j][e1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][e2]<=l2)
				ans=max(ans,m-dis[s1][i]-dis[i][j]-dis[j][e1]-dis[s2][i]-dis[j][e2]);
	ans=max(ans,m-dis[s1][e1]-dis[s2][e2]);
	swap(s2,e2);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dis[s1][i]+dis[i][j]+dis[j][e1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][e2]<=l2)
				ans=max(ans,m-dis[s1][i]-dis[i][j]-dis[j][e1]-dis[s2][i]-dis[j][e2]);
	ans=max(ans,m-dis[s1][e1]-dis[s2][e2]);
	swap(s1,e1);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dis[s1][i]+dis[i][j]+dis[j][e1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][e2]<=l2)
				ans=max(ans,m-dis[s1][i]-dis[i][j]-dis[j][e1]-dis[s2][i]-dis[j][e2]);
	ans=max(ans,m-dis[s1][e1]-dis[s2][e2]);
//	if(n!=2556)
		cout<<max(ans,m-dis[s1][e1]-dis[s2][e2]);
//	else
//		cout<<dis[s1][e1]<<' '<<dis[s2][e2]<<' ';
}