#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <map>

const int DEBUG = 0;

int n, m;
int inv10;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int inv(int a, int n) {
    long long x, y;
    exgcd(a, n, x, y);
    return (x % n + n) % n;
}

const int N = 1e5 + 7;
std::vector<std::pair<int, int> > adj[N];
long long answer = 0;
int del[N], father[N], size[N], power10[N], p_inv10[N];
std::map<int, int> count[2];

int find(int s) {
	std::vector<int> queue;
	queue.push_back(s);
	father[s] = -1;
	for (int head = 0; head < (int)queue.size(); head++) {
		int u = queue[head];
		size[u] = 1;
		for (auto e : adj[u]) {
			int v = e.first;
			if (!del[v] && v != father[u]) {
				father[v] = u;
				queue.push_back(v);
			}
		}
	}
	int all = queue.size();
	for (int i = all - 1; i >= 0; i--) {
		int u = queue[i];
		bool ok = true;
		for (auto e : adj[u]) {
			int v = e.first;
			if (!del[v] && v != father[u]) {
				size[u] += size[v];
				ok &= (size[v] <= (all + 1) / 2);
			}
		}
		ok &= ((all - size[u]) <= (all + 1) / 2);
		if (ok) {
			return u;
		}
	}
	assert(false);
}

std::vector<int > delay[2];

__inline int query(std::map<int, int> &count, int c) {
	if (count.count(c)) {
		return count[c];
	} else {
		return 0;
	}
}

void dfs(int u, int dep, int num0, int num1) {
	answer += (num0 == 0);
	answer += (num1 == 0);
	answer += query(count[1], num0);
	answer += query(count[0], 1LL * num1 * p_inv10[dep] % m);
	delay[0].push_back((m - num0) % m);
	delay[1].push_back(1LL * (m - num1) % m * p_inv10[dep] % m);
	//printf("%d %d %d\n", u, num0, num1);
	for (auto e : adj[u]) {
		int v = e.first, digit = e.second;
		if (v != father[u] && !del[v]) {
			father[v] = u;
			dfs(v, dep + 1, (num0 + 1LL * power10[dep] * digit) % m, (1LL * num1 * 10 + digit) % m);
		}
	}
}

void divide(int s) {
	int u = find(s);
if (DEBUG) {
	printf("divide %d\n", u);
}
	del[u] = 1;
	count[0].clear();
	count[1].clear();
	long long bak_answer = answer;
	for (auto e : adj[u]) {
		int v = e.first;
		if (del[v]) continue;
		father[v] = u;
		delay[0].clear();
		delay[1].clear();
		dfs(v, 1, e.second % m, e.second % m);
		for (int i = 0; i < 2; i++) {
			for (auto d : delay[i]) {
				count[i][d]++;
			}
		}
	}
if (DEBUG) {
	printf("answer += %lld\n", answer - bak_answer);
}
	for (auto e : adj[u]) {
		int v = e.first;
		if (!del[v]) {
			divide(v);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	if (m == 1) {
		printf("%lld\n", 1LL * n * n - n);
		return 0;
	}
	inv10 = inv(10, m);
if (DEBUG) {
	printf("inv10 = %d\n", inv10);
}
	assert(1LL * 10 * inv10 % m == 1);
	power10[0] = p_inv10[0] = 1;
	for (int i = 1; i <= n; i++) {
		power10[i] = 1LL * power10[i - 1] * 10 % m;
		p_inv10[i] = 1LL * p_inv10[i - 1] * inv10 % m;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(std::make_pair(v, w));
		adj[v].push_back(std::make_pair(u, w));
	}
	divide(0);
	std::cout << answer << std::endl;
	return 0;
}