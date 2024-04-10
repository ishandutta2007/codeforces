#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,a[100005];
signed main(){
	cin>>n;
	for (int i=1;i<=2*n;i++)cin>>a[i];
	sort(a+1,a+1+2*n);
	int flag=1;
	for (int i=1;i<=2*n;i++){
		if (a[i]!=a[1])flag=0;
	}
	if (flag==1){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=1;i<=2*n;i++)cout<<a[i]<<' ';
	return 0;
}