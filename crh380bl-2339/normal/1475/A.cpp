#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	long long n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		while(n%2==0)n>>=1;
		if(n!=1)puts("YES");
		else puts("NO");
	}
	return 0;
}