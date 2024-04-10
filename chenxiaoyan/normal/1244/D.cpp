/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=100000;
int n;
int cst[4][N+1];
vector<int> nei[N+1];
int dep[N+1];
int st;
int bfs(int a,int b,int c){
	queue<int> q;
	q.push(st);
	int res=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		int cc=dep[x]%3==0?a:dep[x]%3==1?b:c;
		res+=cst[cc][x];
		for(int i=0;i<nei[x].size();i++){
			int y=nei[x][i];
			if(dep[y]==dep[x]-1)continue;
			dep[y]=dep[x]+1;
			q.push(y);
		}
	}
	return res;
}
int ans[N+1];
void bfs0(int a,int b,int c){
	queue<int> q;
	q.push(st);
	while(q.size()){
		int x=q.front();
		q.pop();
		int cc=dep[x]%3==0?a:dep[x]%3==1?b:c;
		ans[x]=cc;
		for(int i=0;i<nei[x].size();i++){
			int y=nei[x][i];
			if(dep[y]==dep[x]-1)continue;
			q.push(y);
		}
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=3;i++)for(int j=1;j<=n;j++)cin>>cst[i][j];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)cnt1+=nei[i].size()==1,cnt2+=nei[i].size()==2;
	if(cnt1!=2||cnt2!=n-2)return puts("-1"),0;
	for(int i=1;i<=n;i++)if(nei[i].size()==1)st=i;
	int mn=inf,mn1,mn2,mn3;
	for(int i=1;i<=n;i++)dep[i]=-2;dep[st]=0;
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)for(int k=1;k<=3;k++)if(i!=j&&i!=k&&j!=k)
		if(bfs(i,j,k)<mn)mn=bfs(i,j,k),mn1=i,mn2=j,mn3=k;
	cout<<mn<<"\n";
	bfs0(mn1,mn2,mn3);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
/*1
3
3 2 3
4 3 2
3 1 3
1 2
2 3
*/