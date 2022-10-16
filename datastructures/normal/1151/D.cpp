#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
struct node{
	int a,b;
}a[100005];
int n,ans;
bool cmp(node a,node b){
	return a.a-a.b>b.a-b.b;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d%I64d",&a[i].a,&a[i].b);
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		ans+=(a[i].a-a[i].b)*i-a[i].a+a[i].b*n;
	}
	cout<<ans<<endl;
	return 0;
}