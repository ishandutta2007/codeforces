#include<bits/stdc++.h>
using namespace std;
int t;
signed main(){
	cin>>t;
	while(t--) {
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++)
			if(i%3==0)putchar('a');
			else if(i%3==1)putchar('b');
			else putchar('c');putchar('\n');
	}
	return 0;
}