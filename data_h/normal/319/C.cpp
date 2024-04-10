#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 200000;
const long long mod = 1000000000000000;

struct bignum
{
	long long a, b;
	void clear() {
		a = b = 0;
	}
	friend bignum operator +(bignum a, bignum b) {
		bignum c;
		c.clear();
		c.a = a.a + b.a;
		c.b = a.b + b.b;
		c.a += c.b / mod;
		c.b %= mod;
		return c;
	}
	friend bignum operator +(bignum a, long long b) {
		bignum c;
		c.clear();
		c.a = a.a;
		c.b = a.b + b;
		c.a += c.b / mod;
		c.b %= mod;
		return c;
	}	
	friend int operator <(bignum a, bignum b) {
		if (a.a != b.a)
			return a.a < b.a;
		return a.b < b.b;
	}	
	void print()
	{
		if (!a)
			printf("%I64d\n", b);
		else {
			printf("%I64d", a);
			printf("%015I64d", b);
			printf("\n");
		}
	}
};

long long a[MAXN], b[MAXN];
bignum dp[MAXN];
int q[MAXN], timee[MAXN];
int s, t, n;

bignum calc(int j, int i) {
	return dp[j] + (a[i] * b[j] - b[j] + b[i]);
}

int calct(int i, int j) {
	
	int l = max(i, j), r = n, mid;
	while(l < r) {
		mid = (l + r) / 2;
		if (calc(i, mid) < calc(j, mid))
			l = mid + 1;
		else
			r = mid;
	}
	if (l == n && calc(i, n) < calc(j, n))
		return n + 1;
	return l;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%I64d", &b[i]);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		dp[i].clear();
	dp[1] = dp[1] + b[1];
	s = 1, t = 1;
	q[1] = 1; timee[1] = 0;
	for(int i = 2; i <= n; i++) {
		while(t > s && calc(q[s + 1], i) < calc(q[s], i))
			s++;
		dp[i] = calc(q[s], i);
		int ti = calct(q[t], i);
		while(t > s && ti < timee[t]) {
			t--;
			ti = calct(q[t], i);
		}
		q[++t] = i;
		timee[t] = ti;
	}
	//for(int i = 1; i <= n; i++)
	//	dp[i].print();
	dp[n].print();
	return 0;
}