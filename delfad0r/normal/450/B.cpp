#include <iostream>

int X, Y;
int N;

int mod(int a, int b) {
	return ((a % b) + b) % b;
}

int foo() {
	switch(mod(N, 6)) {
		case 0:
		return X -Y;
		case 1:
		return X;
		case 2:
		return Y;
		case 3:
		return Y - X;
		case 4:
		return -X;
		case 5:
		return -Y;
	}
	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> X >> Y >> N;
	std::cout << mod(foo(), 1000000007); 
}