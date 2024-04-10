#include <stdio.h>

int a[1000005];
int tmp[1000005];

long long merge(int s, int e) {
	long long ret = 0;
	long long cnt = 0;
	int m = (s + e) >> 1;
	int p1 = s, p2 = m + 1;
	int p = s;
	while(p1 <= m && p2 <= e) {
		if(a[p1] < a[p2]) {
			tmp[p++] = a[p1++];
			ret += cnt;
		}
		else {
			tmp[p++] = a[p2++]; cnt++;
		}
	}
	while(p1 <= m) {
		tmp[p++] = a[p1++];
		ret += cnt;
	}
	while(p2 <= e) {
		tmp[p++] = a[p2++];
	}
	for(int i = s; i <= e; i++) a[i] = tmp[i];
	return ret;
}

long long f(int s, int e) {
	if(s >= e) return 0;
	int m = (s + e) >> 1;
	long long ret = f(s, m) + f(m + 1, e);
	ret += merge(s, e);
	return ret;
}

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	long long inv = f(1, N);
	if((N % 2) == (inv % 2)) puts("Petr");
	else puts("Um_nik");
	return 0;
}