#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int a[N];
int cnt[N],tmp[N];
ll sum[N];
int po(int x,ll k){
	int ret=1;
	while(k){
		if(k&1) ret=ret*x%m;
		x=x*x%m;
		k>>=1;
	}
	return ret;
}
int main(){
//	freopen("test.in","r",stdin);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n>2000){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++){
		for(j=0;j<m;j++){
			tmp[j]=cnt[((j-a[i]+a[i-1])%m+m)%m];
			sum[j]+=tmp[j];
		}
		for(j=0;j<m;j++) cnt[j]=tmp[j];
		sum[(a[i]-a[i-1])%m]++;
		cnt[(a[i]-a[i-1])%m]++;
	}
	int ans=1;
	for(j=0;j<m;j++){
	//	cout<<j<<" "<<sum[j]<<endl;
		ans=ans*po(j,sum[j])%m;
	}
		
	cout<<ans;
	return 0;
}