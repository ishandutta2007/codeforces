#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans;
struct node{
	int x,id;
}a[1005];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i].x,a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)ans+=(i-1)*a[i].x+1;
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)cout<<a[i].id<<' ';
	cout<<endl;
	return 0;
}