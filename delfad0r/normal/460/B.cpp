#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

long long sum_of_digits(long long n) {
	long long s = 0;
	while(n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

long long A, B, C;
std::vector<long long> solutions;

long long my_pow(long long n) {
	long long res = 1;
	for(int a = 0; a < A; ++a)
		res *= n;
	return res;
}

int main() {
	std::cin >> A >> B >> C;
	
	for(long long s = 1; s <= 81LL; ++s) {
		long long x = B * my_pow(s) + C;
		if(x > 0LL && x < 1000000000LL && sum_of_digits(x) == s)
			solutions.push_back(x);
	}
	
	std::sort(solutions.begin(), solutions.end());
	
	std::cout << solutions.size() << '\n';
	for(std::vector<long long>::iterator it = solutions.begin(); it != solutions.end(); ++it)
		std::cout << *it << ' ';
}