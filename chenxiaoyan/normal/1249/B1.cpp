/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000;
int n;
vector<int> nei[N+1];
bool vis[N+1];
int cnt;
int cc[N+1],hav[N+1];
void dfs(int x){
	vis[x]=true;
	cc[x]=cnt;hav[cnt]++;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(!vis[y])dfs(y);
	}
}
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)nei[i].clear(),vis[i]=false,hav[i]=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		nei[i].pb(x);nei[x].pb(i);
	}
	cnt=0;
	for(int i=1;i<=n;i++)if(!vis[i])cnt++,dfs(i);
	for(int i=1;i<=n;i++)cout<<hav[cc[i]]<<" ";
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}