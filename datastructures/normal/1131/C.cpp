#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
int n,tot,a[100005],ans[100005],mn=2e9;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i+=2)ans[++tot]=a[i];
	tot=0;
	for (int i=2;i<=n;i+=2)ans[n-tot]=a[i],tot++;
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}