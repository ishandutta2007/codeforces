#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
int n,k,a[N],p[N],t[N],s[N],ans;
int calc(int l,int r){return l>r?0:s[r]-s[l-1];}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]*t[i];
	for(int i=k;i<=n;i++)ans=max(ans,calc(1,i-k)+calc(i+1,n)+p[i]-p[i-k]);
	printf("%d\n",ans);
	return 0;
}