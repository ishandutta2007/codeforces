#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int t,n,a[N],c[N],m,l[N],r[N],f[N],ans;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=a[i];
	sort(c+1,c+n+1);m=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+m+1,a[i])-c;
	for(int i=1;i<=n;i++){if(!l[a[i]])l[a[i]]=i;r[a[i]]=i;}
	ans=f[1]=1;
	for(int i=2;i<=n;i++){
		if(l[i]>r[i-1])f[i]=f[i-1]+1;
		else f[i]=1;ans=max(ans,f[i]);
	}
	printf("%d\n",m-ans);
	for(int i=1;i<=m;i++)l[i]=0;
}
int main(){
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}