#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+10,LIM=1e6;
int n,m,a[MAXN],t[MAXN],maxv,f[MAXN];
int l,k;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,v;i<=n;i++){
		scanf("%d",&v);
		if(v<=m){
			a[i]=v;
			t[v]++; 
			maxv=max(maxv,v);
		}
	}
	for(int j=1;j<=LIM;j++){
		for(int k=j;k<=LIM;k+=j){
			f[k] += t[j];
		}
	} 
	for(int j=1;j<=m;j++){
		if(f[j]>k){
			l=j;k=f[j];
		}
	}
	if(!l){
		printf("1 0\n");
		return 0;
	}
	printf("%d %d\n",l,k);
	for(int i=1;i<=n;i++){
		if(!a[i])continue;
		if(l%a[i]==0)printf("%d ",i);
	}
	return 0;
}