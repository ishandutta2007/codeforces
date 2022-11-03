#include <cmath>
#include <iomanip>
#include <iostream>

int M, N;
double P;

int main() {
	std::ios_base::sync_with_stdio(false);
	
	std::cin >> M >> N;
	
	double denom = 1.0 / M;
	P = M;
	for(int m = 1; m < M; ++m) {
		P -= pow(m * denom, N);
	}
	
	std::cout << std::fixed << std::setprecision(10) << P;
}