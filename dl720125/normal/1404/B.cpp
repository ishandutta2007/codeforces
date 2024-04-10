#include <bits/stdc++.h>
using namespace std;

int n,pos,mx;
vector<int> v[100010];

inline int check(int x,int y,int pr,int dist)
{
	if(x==y) return dist;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		int u=v[x][i];
		int val=check(u,y,x,dist+1);
		if(val!=-1) return val;
	}
	return -1;
}

inline void dfs(int x,int pr,int dist)
{
	if(dist>mx){
		mx=dist;
		pos=x;
	}
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		int u=v[x][i];
		dfs(u,x,dist+1);
	}
}

signed main()
{
	int t;
	cin>>t;
	while(t--){
		int a,b,da,db;
		cin>>n>>a>>b>>da>>db;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int dis=check(a,b,-1,0);
		if(dis<=da){
			cout<<"Alice\n";continue;
		}
		mx=0;dfs(1,-1,0);
		mx=0;dfs(pos,-1,0);
		if(mx<=2*da){
			cout<<"Alice\n";continue;
		}
		if(2*da>=db){
			cout<<"Alice\n";continue;
		}
		cout<<"Bob\n";
	}
	return 0;
}