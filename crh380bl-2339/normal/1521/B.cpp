#include<bits/stdc++.h>
using namespace std;
int a[100002];
int x[100002],y[100002],A[100002],B[100002];
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
int main(){
	int T,n,i,j,tot,mx,id;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		mx=2147483647;id=0;
		for(i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]<mx){
				mx=a[i];
				id=i;
			}
		}
		tot=0;
		for(i=1;i<=n;++i){
			if(i==id)continue;
			++tot;
			x[tot]=id;y[tot]=i;
			A[tot]=mx;B[tot]=mx+((i-id)&1);
			a[x[tot]]=A[tot];
			a[y[tot]]=B[tot];
		}
		printf("%d\n",tot);
		for(i=1;i<=tot;++i)printf("%d %d %d %d\n",x[i],y[i],A[i],B[i]);
	} 
	return 0;
}