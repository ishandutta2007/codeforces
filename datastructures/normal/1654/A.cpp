#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
int t,n,a[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		cout<<a[n-1]+a[n]<<endl;
	}
	return 0;
}