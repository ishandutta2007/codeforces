#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5;
int main () {
	int n,a,b;
	scanf ("%d %d %d",&n,&a,&b);
	for (int takeA = 0; (long long)takeA * a <= n; takeA++) {
		int have = takeA * a;
		int need = n - have;
		assert(need >= 0);
		if (need % b == 0) {
			int takeB = need / b;
			for (int i = 0; i < takeA*a; i += a) {
				//[i+1,i+a]
				for (int j = i+1; j < i+a; j++) printf ("%d ",j+1);
				printf ("%d ",i+1);
			}
			for (int i = takeA * a; i < n; i += b) {
				//[i+1,i+b]
				for (int j = i+1; j < i+b; j++) printf ("%d ",j+1);
				printf ("%d ",i+1);
			}
			printf ("\n");
			return 0;
		}
	}
	printf ("-1\n");
	return 0;
}