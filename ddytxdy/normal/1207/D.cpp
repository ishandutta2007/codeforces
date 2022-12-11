#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50,mod=998244353;
int n,ans,J[N],anss=1;
struct node{int x,y;}a[N];
bool cmp1(node a,node b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool cmp2(node a,node b){return a.y!=b.y?a.y<b.y:a.x<b.x;}
int main(){
	scanf("%d",&n);
	J[0]=1;
	for(int i=1;i<=n;i++)J[i]=1ll*J[i-1]*i%mod;
	ans=J[n];
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp1);
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j<n&&a[j+1].x==a[j].x)j++;
		anss=1ll*anss*J[j-i+1]%mod;
		i=j;
	}
	ans=(ans-anss)%mod;
	anss=1;
	sort(a+1,a+n+1,cmp2);
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j<n&&a[j+1].y==a[j].y)j++;
		anss=1ll*anss*J[j-i+1]%mod;
		i=j;
	}
	ans=(ans-anss)%mod;
	for(int i=1;i<n;i++)if(a[i+1].x<a[i].x)printf("%d\n",(ans+mod)%mod),exit(0);
	anss=1;
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j<n&&a[j+1].y==a[j].y&&a[j+1].x==a[j].x)j++;
		anss=1ll*anss*J[j-i+1]%mod;
		i=j;
	}
	ans=(ans+anss)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}