#include <bits/stdc++.h>
using namespace std;

int a[111];

int main() {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	int k = 0, pen = 0, s = 10;
	for (int i = 0; i < n; i++) {
		if (s + a[i] > 720) break;
		k++;
		if (s + a[i] > 360) pen += (s + a[i] - 360);
		s += a[i];
	}
	cout<<k<<' '<<pen<<endl;
	
	return 0;
}