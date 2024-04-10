#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

int a[N][N],si[N],sj[N],n,m,k,sm1[N*N],sm2[N*N],p,ans=-1e18;
priority_queue<int> q;

main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],si[i]+=a[i][j],sj[j]+=a[i][j];
	for(int i=1;i<=n;i++)
		q.push(si[i]);
	for(int i=1;i<=k;i++)
		sm1[i]=sm1[i-1]+q.top(),q.push(q.top()-p*m),q.pop();
	while(q.size())q.pop();
	for(int i=1;i<=m;i++)
		q.push(sj[i]);
	for(int i=1;i<=k;i++)
		sm2[i]=sm2[i-1]+q.top(),q.push(q.top()-p*n),q.pop();
	while(q.size())q.pop();
	for(int i=0;i<=k;i++) 
		ans=max(ans,sm1[i]+sm2[k-i]-p*i*(k-i));
	cout<<ans;
}