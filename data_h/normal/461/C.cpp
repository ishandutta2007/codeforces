#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

int bit[N], a[N];
int n, q, rev;

inline int lowbit(int x) {
	return x & (-x);
}

void add(int pos, int val) {
	for(int i = pos; i <= n; i += lowbit(i)) {
		bit[i] += val;
	}
}

int ask(int pos) {
	int answer = 0;
	for(int i = pos; i; i -= lowbit(i)) {
		answer += bit[i];
	}
	return answer;
}

int main() {
	scanf("%d %d", &n, &q);
	rev = 0;
	for(int i = 1; i <= n; i++) {
		bit[i] = 0;
	}	
	for(int i = 1; i <= n; i++) {
		add(i, 1);
		a[i] = 1;
	}
	
	int start = 1, end = n;
	for(int i = 1; i <= q; i++) {
		int type, l, r, p;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d", &p);
			if (rev == 0 && start + p + p - 1 > end) {
				rev = 1;
				p = end - (start + p - 1);
			} else if (rev == 1 && end - p - p + 1 < start) {
				rev = 0;
				p = (end - p + 1) - start;
			}
			
			if (rev == 0) {
				r = start + p + p - 1;
				while(start < r) {
					add(r, a[start]);
					a[r] += a[start];
					start++;
					r--;
				}
			} else {
				l = end - p - p + 1;
				while(l < end) {
					add(l, a[end]);
					a[l] += a[end];
					end--;
					l++;
				}
			}
		} else {
			scanf("%d %d", &l, &r);
			if (rev == 0) {
				printf("%d\n", ask(start + r - 1) - ask(start + l - 1));
			} else {
				printf("%d\n", ask(end - l) - ask(end - r));
			}
		}
		
	/*	for(int j = start; j <= n; j++) {
			printf("%d ", a[j]);
		}
		puts("");
	*/
	}
	
	return 0;
}