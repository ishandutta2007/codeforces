#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
int n,m;
int a[N];
int mnp[N][N];
ll solve(int l,int r,ll x){
	if(l>r) return 0;
	ll ans=a[mnp[l][r]]-x;
	ans+=solve(l,mnp[l][r]-1,a[mnp[l][r]]);
	ans+=solve(mnp[l][r]+1,r,a[mnp[l][r]]);
	return min(ans,r-l+1ll);
}
int main(){
//	freopen("big.in","r",stdin);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		mnp[i][i]=i;
		for(j=i+1;j<=n;j++){
			if(a[j]<a[mnp[i][j-1]]) mnp[i][j]=j;
			else mnp[i][j]=mnp[i][j-1];
		}
	}
	cout<<solve(1,n,0);
	return 0;
}