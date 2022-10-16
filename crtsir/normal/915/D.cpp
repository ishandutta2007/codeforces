#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >cycle;
bool g[503][503],vis[503],rvis[503];
int n,a,b,m,res=0;
bool ck2(int x)
{
	//cout<<x<<' ';
	rvis[x]=1;
	for(int i=0;i<n;i++)
		if(g[x][i]){
			if(vis[i]==1)
			{
				//cout<<i<<endl;
				return 0;
			}
			if(rvis[i]==1)continue;
			vis[i]=1;
			if(!ck2(i))return 0;
			vis[i]=0;
		}
	return 1;
}
void check(){
	for(int i=0;i<cycle.size();i++){
		g[cycle[i].first][cycle[i].second]=0;
		bool ans=1;
		memset(rvis,0,sizeof(rvis));
		memset(vis,0,sizeof(vis));
		for(int j=0;j<n;j++)
			if(!vis[j]){
				vis[j]=1;
				ans&=ck2(j);
				vis[j]=0;
			}
		//cout<<vis[0];
		if(ans==1){
			cout<<"YES";
			exit(0);
		}
		g[cycle[i].first][cycle[i].second]=1;
	}
	cout<<"NO";
	exit(0);
}
void ck(int x){
	rvis[x]=1;
	for(int i=0;i<n;i++)
		if(g[x][i]){
			if(vis[i]==1)
			{
				cycle.push_back(make_pair(x,i));
				check();
			}
			if(rvis[i])continue;
			vis[i]=1;
			cycle.push_back(make_pair(x,i));
			ck(i);
			cycle.pop_back();
			vis[i]=0;
		}
}
int main(){
	//freopen("join.out","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		g[--a][--b]=1;
	}
	for(int i=0;i<n;i++)
		if(!rvis[i])
		{
			vis[i]=1;
			ck(i);
			vis[i]=0;
		}
	cout<<"YES";
}