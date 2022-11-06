#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
int a[100000],b[100000],x=0,y=0;
int main(){
	int T,n,z,i;
	scanf("%d",&T);
	while(T--){
		x=y=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&z);
			if(z&1)a[++x]=z;
			else b[++y]=z;
		}
		for(i=1;i<=x;++i)printf("%d ",a[i]);
		for(i=1;i<=y;++i)printf("%d ",b[i]);
		puts("");
	} 
	return 0;
}