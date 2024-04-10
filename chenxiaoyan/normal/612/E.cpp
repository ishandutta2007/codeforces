#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
void prt(int x){
	if(x>9)prt(x/10);
	putchar(x%10^48);
}
const int N=1000000;
int n;
int a[N+1];
bool vis[N+1];
vector<int> v;
void dfs(int x){
	if(vis[x])return;
	vis[x]=true;
	v.pb(x);
	dfs(a[x]);
}
vector<vector<int> > vv;
vector<int> havsz[N+1];
int ans[N+1];
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)if(!vis[i]){
		v.clear();
		dfs(i);
		if(v.size()&1){
			vector<int> v0(v.size());
			for(int j=0,now=0;j<v.size();j++,(now+=2)%=v.size())v0[now]=v[j];
			for(int j=0;j<v.size();j++)ans[v0[j]]=v0[(j+1)%v.size()];
		}
		else vv.pb(v);
	}
	for(int i=0;i<vv.size();i++)havsz[vv[i].size()].pb(i);
	for(int i=2;i<=n;i+=2)
		if(havsz[i].size()&1)return puts("-1"),0;
		else for(int j=0;j<havsz[i].size();j+=2){
			vector<int> &v0=vv[havsz[i][j]],&v1=vv[havsz[i][j+1]],v2(2*v0.size());
			for(int k=0,now=0;k<v0.size();k++,now+=2)v2[now]=v0[k],v2[now+1]=v1[k];
			for(int k=0;k<v2.size();k++)ans[v2[k]]=v2[(k+1)%v2.size()];
		}
	for(int i=1;i<=n;i++)prt(ans[i]),putchar(' ');
	return 0;
}
/*1
4
2 1 4 3
*/
/*2
4
2 1 3 4
*/
/*3
5
2 3 4 5 1
*/