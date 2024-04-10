#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll a[20];
void sol(){
	int num=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		while(a[i]%2==0)a[i]/=2,num++;
	}
	sort(a,a+n);
	for(int i=0;i<num;i++)a[n-1]*=2;
	ll ans=0;
	for(int i=0;i<n;i++)ans+=a[i];
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}