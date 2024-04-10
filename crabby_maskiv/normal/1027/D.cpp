#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll c[N];
int a[N];
bool vis[N],vis2[N];
int flag=0;
ll mn,ans;
void dfs(int cur){
	vis[cur]=1;
	if(vis[a[cur]]){
		if(vis2[a[cur]])
			return;
		else{
			flag=a[cur];
			mn=inf;
		} 
	}
	else dfs(a[cur]);
	if(flag)
		mn=min(mn,c[cur]);
	if(flag==cur){
		ans+=mn;
		flag=0;
	}
	vis2[cur]=1;
}
int main(){
	cin>>n;
	int i;
	for(i=1;i<=n;i++) cin>>c[i];
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	cout<<ans;
    return 0;
}