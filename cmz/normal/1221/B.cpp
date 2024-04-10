#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			if ((i+j)%2==0) printf("W");
			else printf("B");
		puts("");
	}
	return 0;
}