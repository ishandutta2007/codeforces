#include <bits/stdc++.h>
using namespace std;
int main() {	
	int n;
	scanf("%d",&n);
	int lg = -2000000;
	for(int i = 0; i < n; ++i) {
		int a,k=0;
		scanf("%d",&a);
		while(k*k < a) ++k;
		if(k*k != a)
			lg = max(lg,a);
	}
	printf("%d\n",lg);
}