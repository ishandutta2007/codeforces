#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,x;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x;
		if (x>14&&x%14>=1&&x%14<=6)puts("YES");
		else puts("NO");
	}
	return 0;
}