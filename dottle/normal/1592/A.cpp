#include<bits/stdc++.h>
//#define int long long
const int N=5005;
using namespace std;

int n,a[N],h,ans; 

void solve(){
	cin>>n>>h;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ans=h/(a[n]+a[n-1])*2;
	h%=(a[n]+a[n-1]);
	if(h)ans++;
	if(h>a[n])ans++;
	cout<<ans<<endl;
} 

int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}