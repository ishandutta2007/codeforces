#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N],n;

int main() {	
	scanf("%d",&n);
	n *= 2;
	for(int i = 0; i < n; ++i)
		scanf("%d",a+i);
	sort(a,a+n);
	int ans = 1<<20;
	for(int i = 0; i < n; ++i) {
		for(int j = i+1; j < n; ++j) {
			int b = 0;
			for(int k = 0; k < n;) {
				if(k == i || k == j) {
					++k;
					continue;
				}
				int nxt = k + 1;
				while(nxt==i||nxt==j) ++nxt;
				b += a[nxt]-a[k];
				k = nxt+1;
			}
			ans = min(ans,b);
		}
	}
	printf("%d\n",ans);
}