#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300000;
int n,m;
int a[N+1],d[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
	sort(d+1,d+n);
	ll ans=0;
	for(int i=1;i<=n-m;i++)ans+=d[i];
	printf("%d",ans);
	return 0;
}