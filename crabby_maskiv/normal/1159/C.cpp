#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll mod=998244353;
int n,m;
ll b[N],g[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>b[i];
	for(i=1;i<=m;i++) cin>>g[i];
	sort(b+1,b+n+1);
	sort(g+1,g+m+1);
	if(g[1]<b[n]){
		cout<<-1;
		return 0;
	}
	ll ans=0;
	for(i=1;i<=n;i++)
		ans+=b[i]*m;
	for(i=2;i<=m;i++)
		ans+=g[i]-b[n];
	if(g[1]==b[n]) ans+=g[1]-b[n];
	else ans+=g[1]-b[n-1];
	cout<<ans;
	return 0;
}