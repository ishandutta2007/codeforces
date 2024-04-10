/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000000;
int n,m,s;
string a[N+1];
int Sum[N+1];
vector<int> son[N+2];int fa[N+2];
int stk[N+1],top;
int ans[N+2];
void dfs(int x){
	stk[top++]=x;
	ans[x]=stk[max(0,top-1-s)]-x;
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];
		dfs(y);
	}
	top--;
}
int main(){
	cin>>n>>s>>m;
	for(int i=1;i<=n;i++)cin>>a[i],Sum[i]=Sum[i-1]+a[i].size()+1;
	fa[n+1]=n+1;
	for(int i=n;i;i--){
		fa[i]=fa[i+1];
		while(Sum[fa[i]-1]-Sum[i-1]-1>m)fa[i]--;
		if(fa[i]!=i)son[fa[i]].pb(i);
	}
//	for(int i=1;i<=n+1;i++)cout<<fa[i]<<" ";puts("");
	for(int i=1;i<=n+1;i++)if(fa[i]==i)top=0,dfs(i);
	int mx=*max_element(ans+1,ans+n+2);
	for(int i=1;i<=n+1;i++)if(ans[i]==mx){
		while(s--){
			for(int j=i;j<fa[i];j++)cout<<a[j]<<(j<fa[i]-1?" ":"\n");
			i=fa[i];
		}
		return 0;
	}
}
/*1
9 4 12
this is a sample text for croc final round
*/
/*2
9 1 9
this is a sample text for croc final round
*/
/*3
6 2 3
croc a a a croc a
*/
/*4
2 2 5
first second
*/