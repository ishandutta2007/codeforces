#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int vis[N];
int s[N];
int l[N],r[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++) cin>>l[i]>>r[i];
	int ans=0;
	for(i=1;i<=m;i++){
		int k=0;
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(vis));
		for(j=1;j<=m;j++){
			if(i==j) continue;
			vis[l[j]]++;vis[r[j]+1]--;
		}
		for(j=1;j<=n;j++){
			vis[j]+=vis[j-1];
			s[j]+=(vis[j]==1);
			k+=(vis[j]>0);
		}
		for(j=1;j<=n;j++) s[j]+=s[j-1];
		for(j=1;j<=m;j++){
			if(i==j) continue;
			ans=max(ans,k-s[r[j]]+s[l[j]-1]);
		}
	}
	cout<<ans;
	return 0;
}