#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>

typedef std::pair<int, int> ii;

int N, M, W;
int A[100000];

bool is_ok(int h) {
	int increment = 0, m = M;
	std::queue<ii> queue;
	for(int n = 0; n < N; ++n) {
		while(!queue.empty() && queue.front().first <= n) {
			increment -= queue.front().second;
			queue.pop();
		}
		if(A[n] + increment >= h) continue;
		if(m - (h - A[n] - increment) < 0) return false;
		queue.push(ii(n + W, h - A[n] - increment));
		m -= h - A[n] - increment;
		increment += h - A[n] - increment;
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> M >> W;
	for(int n = 0; n < N; ++n)
		std::cin >> A[n];
	
	//[lo, hi)
	int lo = *std::min_element(A, A + N), hi = *std::max_element(A, A + N) + M + 1;
	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(is_ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	
	std::cout << lo;
}