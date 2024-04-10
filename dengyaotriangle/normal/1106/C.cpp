#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n;
int a[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i+i<=n;i++){
		ans+=(long long)(a[i]+a[n-i+1])*(long long)(a[i]+a[n-i+1]);
	}
	cout<<ans;
	return 0;
}