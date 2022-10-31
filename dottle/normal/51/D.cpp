#include<bits/stdc++.h>
#define int long long
#define double long double
const int N=1000005;
using namespace std;

int n,a[N],b[N];

int calc(int x,int y){
	memcpy(a,b,sizeof(a));
	double k=1.*a[y]/a[x];
	int ans=0;
	if(a[x]==0)k=0;
	if(k==0&&(a[y]))ans++;
	for(int i=y+1;i<=n;i++)
		if(abs(1.*a[i]/a[i-1]-k)>1e-10)
			a[i]=a[i-1],ans++;
	return ans;
}

void solve(){
	cin>>n;
	if(n==1)cout<<0<<endl,exit(0);
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	int ans;
	ans=min(2ll,min(calc(1,2),min(calc(1,3),calc(2,3))+1));
	cout<<ans<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}