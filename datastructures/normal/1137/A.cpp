#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,a[1005][1005];
int tot,val1[1005][1005],val2[1005][1005],val3[1005][1005],val4[1005][1005];
struct node{
	int val,id;
}c[1005];
bool cmp(node a,node b){
	return a.val<b.val;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)c[j].val=a[i][j],c[j].id=j;
		sort(c+1,c+1+m,cmp);
		int num=0;
		for (int j=1;j<=m;j++){
			if (j==1||c[j].val!=c[j-1].val)num++;
			val1[i][c[j].id]=num;
		}
		num=0;
		for (int j=m;j>=1;j--){
			if (j==m||c[j].val!=c[j+1].val)num++;
			val2[i][c[j].id]=num;
		}
	}
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++)c[i].val=a[i][j],c[i].id=i;
		sort(c+1,c+1+n,cmp);
		int num=0;
		for (int i=1;i<=n;i++){
			if (i==1||c[i].val!=c[i-1].val)num++;
			val3[c[i].id][j]=num;
		}
		num=0;
		for (int i=n;i>=1;i--){
			if (i==n||c[i].val!=c[i+1].val)num++;
			val4[c[i].id][j]=num;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)printf("%d ",max(val1[i][j],val3[i][j])+max(val2[i][j],val4[i][j])-1);
		puts("");
	}
	return 0;
}