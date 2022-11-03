#include <algorithm>
#include <iostream>

long long L, R;
long long count;

int last_digit(long long n) {
	return n % 10;
}

int first_digit(long long n) {
	while(n > 9)
		n /= 10;
	return n;
}

long long prior_to(long long n) {
	if(n < 10)
		return n;
	return n / 10 + 9 - (last_digit(n) < first_digit(n));
}

void read() {
	std::cin >> L >> R;
}

void write() {
	std::cout << count;
}

void solve() {
	count = prior_to(R) - prior_to(L - 1);
}

int main() {
	read();
	solve();
	write();
	return 0;
}