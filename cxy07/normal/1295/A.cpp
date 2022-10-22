//Code By CXY
#include<bits/stdc++.h>
using namespace std;

int T,n;

int main () {
	cin >> T;
	while(T--) {
		cin >> n;
		if(n & 1) printf("7");
		else printf("1");
		for(register int i = 1;i < n / 2; ++i)
			printf("1");
		puts("");
	}
	return 0;
}