#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
int t,n;char s[120];
int sum[120][2];
 
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s+1;
		for(int i=1;i<=n;i++)
			putchar(s[n]);
		putchar('\n');
	}
	return 0;
}