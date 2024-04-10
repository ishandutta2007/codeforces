#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const int M=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=1000000007ll;
int vis[N][M];
int a[N],b[N];
int n,m;
int main(){
    ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	
	for(i=1;i<=n;i++){
		char ch;cin>>ch;
		vis[i][1]=ch-'0';
	}
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=b[i];j++) vis[i][j]=vis[i][1];
		for(j=b[i]+1;j<M;j++){
			if((j-b[i]+a[i]-1)/a[i]>(j-1-b[i]+a[i]-1)/a[i])
				vis[i][j]=!vis[i][j-1];
			else vis[i][j]=vis[i][j-1];
		}
	}
	int ans=0;
	for(i=1;i<M;i++){
		int cnt=0;
		for(j=1;j<=n;j++) cnt+=vis[j][i];
		//cout<<i<<" "<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans;
    return 0;
}