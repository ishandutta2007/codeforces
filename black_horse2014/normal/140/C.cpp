#include <bits/stdc++.h>
using namespace std;

map<int, int> M;
typedef pair<int, int> PII;
set<PII> s;

struct data {
	int a[4];
	data(int x = 0, int y = 0, int z = 0) {
		a[0] = x, a[1] = y, a[2] = z;
		sort(a, a + 3);
	}
} b[111111];

int main() {
	
	int k = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (M.count(x)) M[x]++;
		else M[x] = 1;
	}
	for (map<int, int> :: iterator it = M.begin(); it != M.end(); it++) {
		s.insert(PII(it->second, it->first));
	}
	while (s.size() > 2) {
		set<PII> :: iterator it = s.end();
		it--;
		int x = it->second, xn = it->first;
		it--;
		int y = it->second, yn = it->first;
		it--;
		int z = it->second, zn = it->first;
		s.erase(PII(xn, x));
		if (xn > 1) s.insert(PII(xn - 1, x));
		s.erase(PII(yn, y));
		if (yn > 1) s.insert(PII(yn - 1, y));
		s.erase(PII(zn, z));
		if (zn > 1) s.insert(PII(zn - 1, z));
		b[k++] = data(x, y, z);
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d %d %d\n", b[i].a[2], b[i].a[1], b[i].a[0]);
	}
	
	return 0;
}