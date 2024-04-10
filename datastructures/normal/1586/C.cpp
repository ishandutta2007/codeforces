#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
int n,m,q,f[1000005],a[1000005];
char s[1000005];
int id(int x,int y){
	if (x<1||x>n||y<1||y>m)return 0;
	return (x-1)*m+y; 
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%s",s+(i-1)*m+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			f[id(i,j)]=j;
			if (s[id(i-1,j)]!='X')f[id(i,j)]=min(f[id(i,j)],f[id(i-1,j)]);
			if (s[id(i,j-1)]!='X')f[id(i,j)]=min(f[id(i,j)],f[id(i,j-1)]);
			a[j]=max(a[j],f[id(i,j)]);
		}
	}
	for (int i=1;i<=m;i++)a[i]=max(a[i],a[i-1]);
	cin>>q;
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if (a[r]<=l)puts("Yes");
		else puts("No");
	}
	return 0;
}