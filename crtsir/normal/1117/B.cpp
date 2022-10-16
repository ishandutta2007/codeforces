#include<bits/stdc++.h>
using namespace std;
long long n,a[200003],k,m;
int main(){cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		scanf("%lld",a+i);
	sort(a,a+n);
	long long ans=a[n-2]*(m/(k+1));
	ans+=a[n-1]*(m-m/(k+1));
	cout<<ans;
}