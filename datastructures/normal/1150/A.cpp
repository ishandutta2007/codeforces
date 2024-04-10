#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,r,a[100005],b[100005];
signed main(){
	cin>>n>>m>>r;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int j=1;j<=m;j++)cin>>b[j];
	sort(a+1,a+1+n),sort(b+1,b+1+m);
	if (b[m]<a[1]){
		cout<<r<<endl;
		return 0;
	}
	cout<<r%a[1]+r/a[1]*b[m]<<endl;
	return 0;
}