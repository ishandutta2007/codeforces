#include <algorithm>
#include <iostream>

int N;
int sequence[100000];
int l[100000], r[100000];
int max_length = 0;

void solve() {
	int begin = 0;
	for(int curr = begin; curr < N; ++curr) {
		l[curr] = curr - begin + 1;
		if(sequence[curr] >= sequence[curr + 1])
			begin = curr + 1;
	}
	begin = N - 1;
	for(int curr = begin; curr >= 0; --curr) {
		r[curr] = begin - curr + 1;
		if(sequence[curr - 1] >= sequence[curr])
			begin = curr - 1;
	}
	max_length = std::max(r[0], l[N - 1]);
	for(int i = 1; i < N; ++i) {
		if(sequence[i - 1] + 1 < sequence[i + 1]) {
			max_length = std::max(max_length, l[i - 1] + 1 + r[i + 1]);
		}
		else {
			max_length = std::max(max_length, std::max(l[i], r[i]) + 1);
		}
	}
}

void read() {
	std::cin >> N;
	for(int i = 0; i < N; ++i) {
		std::cin >> sequence[i];
	}
}

void write() {
	std::cout << std::min(max_length, N);
}

int main() {
	read();
	solve();
	write();
	return 0;
}