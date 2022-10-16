#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct node{
	int a,b;
}a[1000005],b[1000005];
bool cmp(node x,node y){
	return x.a<y.a;
}
int t;
int n,m,mx[1000005];
int d[1000005];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i].a>>a[i].b;
	for (int i=1;i<=m;i++)cin>>b[i].a>>b[i].b;
	sort(b+1,b+1+m,cmp);
	for (int i=m;i>=1;i--)mx[i]=max(mx[i+1],b[i].b);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (b[j].a>=a[i].a)d[b[j].a-a[i].a]=max(d[b[j].a-a[i].a],mx[j]-a[i].b+1);
	}
	for (int i=1000000;i>=0;i--)d[i]=max(d[i],d[i+1]);
	int ans=1000000000;
	for (int i=0;i<=1000000;i++)ans=min(ans,i+d[i]);
	cout<<ans<<endl;
	return 0;
}