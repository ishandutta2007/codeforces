/*








*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=100,M=1000000;
int n,m;
int p[M+1];
int dis[N+1][N+1]; 
void floyd(){
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
vector<int> ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=1;j<=n;j++)dis[i][j]=i==j||s[j-1]=='1'?1:inf;
	}
	cin>>m;
	for(int i=1;i<=m;i++)scanf("%d",p+i);
	floyd();
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";puts("");}
	ans.pb(1);
	for(int i=3;i<=m;i++)if(dis[p[ans.back()]][p[i-1]]+dis[p[i-1]][p[i]]!=dis[p[ans.back()]][p[i]])ans.pb(i-1);
	ans.pb(m);
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<p[ans[i]]<<" ";
	return 0;
}