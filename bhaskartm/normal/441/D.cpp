#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
 
using namespace std;
 
const int N = 3005;
 
int n, m, k, p[N];
bool used[N];
 
inline void use_cycle(int v) {
	for (int i = v; !used[i]; i = p[i])
		used[i] = true;
}
 
int main() {
	
	scanf("%d", &n);
 
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		p[i]--;
	}
 
	scanf("%d", &m);
	m = n - m;
 
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			k++;
			use_cycle(i);
		}
 
	for (int i = 0; i < n; ++i)
		used[i] = false;
 
	printf("%d\n", (int)abs(k-m));
 
	if (k > m) {
		use_cycle(0);
		for (int i = 1; i < n && k > m; ++i) {
			if (!used[i]) {
				printf("%d %d ", 1, i+1);
				k--;
				use_cycle(i);
			}
		}
	}
 
	if (k < m) {
		for (int i = 0; i < n && k < m; ++i) {
			vector <int> pos(n, -1);
			
			int cur = 0;
			for (int j = p[i]; j != i; j = p[j])
				pos[j] = cur++;
			pos[i] = cur;
			
			cur = 0;
			for (int j = i+1; j < n && k < m; ++j)
				if (pos[j] >= cur) {
					printf("%d %d ", i+1, j+1);
					k++;
					cur = pos[j]+1;
					swap(p[i], p[j]);
				}
				
		}
	}
 
	return 0;
}