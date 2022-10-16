#include<bits/stdc++.h>
using namespace std;
bool vis[8][8];
int n;
vector<pair<int,int> >ans;
void dfs(int x,int y,int num){
	if(x==7&&y==7){
		if(num==n)
		{
			cout<<"a1";
			for(int i=0;i<n;i++)cout<<' '<<char(ans[i].first+'a')<<ans[i].second+1;
			exit(0);
		}
		return;
	}
	if(num>=n)return;
	for(int i=0;i<8;i++)
	{
		if(!vis[i][y])
		{
			ans.push_back(make_pair(i,y));
			vis[i][y]=1;
			dfs(i,y,num+1);
			vis[i][y]=0;
			ans.pop_back();
		}
		if(!vis[x][i])
		{
			ans.push_back(make_pair(x,i));
			vis[x][i]=1;
			dfs(x,i,num+1);
			vis[x][i]=0;
			ans.pop_back();
		}
	}
}
int main(){
	cin>>n;
	vis[0][0]=1;
	dfs(0,0,0);
}