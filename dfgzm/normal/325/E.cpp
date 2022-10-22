#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k,n,m,vis[maxn],cnt,Q[maxn],top;
void dfs(int now){
	vis[now]++;
	if(!vis[now*2%n])dfs(now*2%n);
	if(!vis[(now*2+1)%n])dfs((now*2+1)%n);
	Q[++top]=now;	
}
int main(){
	cin>>n;
	if(n&1)cout<<-1<<endl;
	else{
		dfs(0);
		while(top)cout<<Q[top--]<<' ';cout<<0<<endl;
	}
	return 0;
}