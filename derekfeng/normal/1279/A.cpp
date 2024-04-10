#include <bits/stdc++.h> 
using namespace std;
int main(){
	int T;cin>>T;
	while (T--){
		int a[3];for (int i=0;i<3;i++)cin>>a[i];
		sort (a,a+3);
		if (a[2]>a[0]+a[1]+1) puts("No");
		else puts("Yes");
	}
}