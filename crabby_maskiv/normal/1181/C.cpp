#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
char a[N][N];
int r[N][N],d[N][N];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>(a[i]+1);
	for(i=1;i<=n;i++){
		for(j=m;j;j--){
			if(a[i][j]==a[i][j+1]) r[i][j]=r[i][j+1]+1;
			else r[i][j]=1;
		}
	}
	for(i=1;i<=m;i++){
		for(j=n;j;j--){
			if(a[j][i]==a[j+1][i]) d[j][i]=d[j+1][i]+1;
			else d[j][i]=1;
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(i+3*d[i][j]-1>n) continue;
			if(d[i+d[i][j]][j]!=d[i][j]) continue;
			if(d[i+2*d[i][j]][j]<d[i][j]) continue;
			int mn=inf;
			for(k=i;k<i+3*d[i][j];k++) mn=min(mn,r[k][j]);
			ans+=mn;
		}
	}
	cout<<ans;
	return 0;
}