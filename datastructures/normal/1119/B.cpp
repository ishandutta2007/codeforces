#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,h,a[100005],ans;
bool check(int n){
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	int ans=0;
	for (int i=1;i<=n;i+=2)ans+=a[i];
	if (ans<=h)return 1;
	return 0;
}
signed main(){
	cin>>n>>h;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (check(i))ans=i;
	}
	cout<<ans<<endl;
	return 0;
}