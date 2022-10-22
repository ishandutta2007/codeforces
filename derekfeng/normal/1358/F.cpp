#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200005],b[200005],nb[200005];
vector<ll>v;
void restore(ll *A){
	for(int i=n;i;i--)A[i]-=A[i-1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	bool ok=1;
	for(int i=1;i<=n;i++)if(a[i]!=b[i])ok=0;
	if(ok)return puts("SMALL\n0"),0;
	if(n==1)return puts("IMPOSSIBLE"),0;
	if(n==2){
		for(;;){
			if(b[1]>b[2])v.push_back(-1),swap(b[1],b[2]);
			if(b[1]==a[1]){
				ll X=b[2]-a[2];
				if(X%b[1]==0&&X>=0&&a[2]>=b[2]%b[1]){
					X/=b[1];
					v.push_back(X);
					break;
				}
			}
			if(b[1]==a[2]){
				ll X=b[2]-a[1];
				if(X%b[1]==0&&X>=0&&a[1]>=b[2]%b[1]){
					X/=b[1];
					v.push_back(X);
					v.push_back(-1);
					break;
				}
			}
			v.push_back(b[2]/b[1]),b[2]=b[2]%b[1];
			v.push_back(-1),swap(b[1],b[2]);
			if(b[1]<=0||b[2]<=0)return puts("IMPOSSIBLE"),0;
		}
	}else{
		for(;;){
			ok=1;
			for(int i=1;i<=n;i++)if(a[i]!=b[i])ok=0;
			if(ok)break;
			ok=1;
			for(int i=1;i<=n;i++)if(a[i]!=b[n-i+1])ok=0;
			if(ok){
				v.push_back(-1);
				break;
			}
			if(b[1]==b[n])return puts("IMPOSSIBLE"),0;
			if(b[1]>b[n])v.push_back(-1),reverse(b+1,b+n+1);
			v.push_back(1),restore(b);
			for(int i=1;i<=n;i++)if(b[i]<=0)return puts("IMPOSSIBLE"),0;
		}
	}
	reverse(v.begin(),v.end());
	ll sum=0,ans=0;
	for(auto x:v)sum+=max(x,0ll),ans+=abs(x);
	if(sum>2e5)return printf("BIG\n%lld",sum),0;
	printf("SMALL\n%lld\n",ans);
	for(auto x:v){
		if(x<0)putchar('R');
		else for(int i=0;i<x;i++)putchar('P');
	}
}