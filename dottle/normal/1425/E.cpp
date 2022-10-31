#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,k;
int a[N],d[N],mx[N];

void solve0(){
	int ans=0;//its able to choose 0 atoms
	for(int i=n,s=0;i>=1;i--){
		s+=a[i];
		ans=max(ans,s-d[i]);
	} 
	cout<<ans<<endl;
}

void solve1(){
	int sum=0,ans=0;
	for(int i=1;i<=n;i++)	
		sum+=a[i];
	for(int i=n,s=0,mn=1e9;i>=1;i--)
		s+=a[i],mx[i]=max(mx[i+1],s-d[i]);
	for(int i=1,s=0,mn=1e9;i<n;i++){
		s+=a[i];
		mn=min(mn,d[i]);
		ans=max(ans,s-mn+mx[i+1]);
		ans=max(ans,max(mx[i+1],mx[1]-min(a[i+1],d[i+1])));
	}
	cout<<ans<<endl;
}

void solve2(){
	int sum=0,mn=1e18;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(i<n)mn=min(mn,d[i]);
	}
	int ans=0;
	ans=max(ans,a[n]-d[n]);
	ans=max(ans,sum-mn);
	cout<<ans<<endl;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>d[i];
	if(k==0)solve0();
	if(k==1)solve1();
	if(k>=2)solve2();
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}