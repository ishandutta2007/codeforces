#include <iostream>

using namespace std;

int n, k;

int main() 
{
	cin >> n >> k;
	for (int i = 0; i < n; i += k) {
		for (int j = 0; i + j < n && j < k; ++j) {
			printf("%c", 'a' + j);
		}
	}
	printf("\n");
	return 0;
}