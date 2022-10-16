#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,a[100005],sum,ans;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	int n;
	cin>>n;
	int nowx=0,nowy=0;
	for (int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n/2;i++){
		nowx+=a[i];
	}
	sum-=nowx;
	cout<<(nowx*nowx+sum*sum)<<endl;
	return 0;
}