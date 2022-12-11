#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m;
struct node{
	int x,id;
	bool friend operator <(node a,node b){
		return a.x<b.x;
	}
}a[N];
bool cmp(node a,node b){
	return a.id<b.id;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);a[i].id=i;
		if(a[i].x<0)a[i].x=-a[i].x-1;
	}
	sort(a+1,a+n+1);
	if(n&1)m=n-1;else m=n;
	for(int i=1;i<=m;i++)a[i].x=-a[i].x-1;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)printf("%d ",a[i].x);
	return 0;
}