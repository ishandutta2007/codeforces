#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 333333;
int a[N], n;
long long sum = 0, score = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n - 1; i++) {
		score += sum;
		score += a[i];
		sum -= a[i];
	}
	
	score += sum;
	
	cout << score << endl;
	return 0;
}