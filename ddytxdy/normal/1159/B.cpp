#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=3e5+50;
int n,a[N],c[N],m,p[2][N],ans=2e9;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)c[i]=a[i];
	sort(c+1,c+n+1);m=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+m+1,a[i])-c;
	
	for(int i=1;i<=n;i++){
		if(!p[0][a[i]])p[0][a[i]]=i;
		p[1][a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(p[1][i]!=1)ans=min(ans,c[i]/(p[1][i]-1));
		if(p[0][i]!=n)ans=min(ans,c[i]/(n-p[0][i]));
	}
	printf("%d",ans);
	return 0;
}