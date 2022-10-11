#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n, m, k;
int main() {
	cin >> n >> m >> k; k--;
	int a1 = (k / (2 * m)), a2 = (k % (2 * m)) / 2, a3 = (k % 2);
	char c = 'L'; if (a3 == 1)c = 'R';
	cout << a1 + 1 << ' ' << a2 + 1 << ' ' << c << endl;
	return 0;
}