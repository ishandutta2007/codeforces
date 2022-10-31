#include<bits/stdc++.h>
#define int long long
const int N=100050,P=32;
using namespace std;

int to[P][N];
int n,a[N],p[N],in[N],b[N];
int mx;
int vis[N],res[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i],to[0][i]=p[i],in[p[i]]++;
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=max(0ll,in[i]-1);
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i]*(a[i]<=n),mx=max(mx,a[i]);
	for(int i=1;i<P;i++)
		for(int j=1;j<=n;j++)
			to[i][j]=to[i-1][to[i-1][j]];
	int p=(mx-n)/cnt;
	set<int> s;
	for(int i=1;i<=n;i++)if(a[i]<=n)vis[a[i]]=1;
	for(int i=1;i<=n;i++)if(!vis[i])s.insert(i);
	for(int i=1;i<=n;i++){
		int nw=i;
		for(int j=P-1;j>=0;j--)
			if(p>>j&1)
				nw=to[j][nw];
		if(a[nw]<=n)
			res[i]=a[nw],a[nw]=n+1;
		else
			res[i]=*s.lower_bound(b[nw]),s.erase(res[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<res[i]<<' ';
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}