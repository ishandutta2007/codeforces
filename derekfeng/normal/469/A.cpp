#include<bits/stdc++.h>
using namespace std;
int n,m,x;
bool vis[103];
int main(){
	cin>>n;
	cin>>m;while(m--)cin>>x,vis[x]=1;
	cin>>m;while(m--)cin>>x,vis[x]=1;
	for(int i=1;i<=n;i++)if(!vis[i])
		return puts("Oh, my keyboard!"),0;
	puts("I become the guy.");
}