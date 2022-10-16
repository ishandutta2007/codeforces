#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int id,d;
}a[200005];
bool cmp(node a,node b){
	return a.d>b.d;
}
int n,c[200005],len,u[200005],v[200005],tot;
void add(int a,int b){
	++tot;
	u[tot]=a,v[tot]=b;
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		a[i].id=2*i-1;
		scanf("%d",&a[i].d);
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<n;i++)add(a[i].id,a[i+1].id);
	len=n;
	for (int i=1;i<=n;i++)c[i]=a[i].id;
	for (int i=1;i<=n;i++){
		add(c[i+a[i].d-1],a[i].id+1);
		if (i+a[i].d-1==len)c[++len]=a[i].id+1;
	}
	for (int i=1;i<2*n;i++)printf("%d %d\n",u[i],v[i]);
	return 0;
}