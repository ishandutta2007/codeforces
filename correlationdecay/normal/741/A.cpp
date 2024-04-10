#include <bits/stdc++.h>
#define maxn 109
using namespace std;
int n;
int a[maxn];
bool vis[maxn];
bool dfs(int u,int root,int &cnt){
	vis[u]=1;
	cnt++;
	if(vis[a[u]]){
		if(a[u]==root)
			return 1;
		else
			return 0;
	}
	return dfs(a[u],root,cnt);
}
long long lcm(long long a,long long b){
	return a/__gcd(a,b)*b;
}
int b[maxn],tot;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long ans=1;
	for(int i=1;i<=n;i++){
		if(vis[i])
			continue;
		int cnt=0;
		if(!dfs(i,i,cnt)){
			puts("-1");
			return 0;
		}
		if(cnt%2==0){
			cnt/=2;
		}
		ans=lcm(ans,cnt);
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}