#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int n,m;
int a[N],sum[N],s;
int res[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		s+=a[i];
		sum[i]=(sum[i-1]+a[i])%n;
	}
	sort(sum+1,sum+m);
	for(int i=1;i<m;i++){
		res[i]=sum[i]-sum[i-1];
	}
	res[m]=n-sum[m-1];
	int ans=ceil(1.*s/n);
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
		cout<<res[i]<<' ';cout<<endl;
	for(int i=1,j=1,r=a[1];i<=ans;i++){
		for(int k=1;k<=m;k++){
			if(r<=0)j++,r=a[j];
			r-=res[k];
			cout<<min(j,m)<<' ';
		}
		cout<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}