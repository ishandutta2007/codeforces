#include <iostream>
#include <queue>
using namespace std;

queue<int> qu;
int main() {
	int n; cin >> n;
	qu.push(4);
	qu.push(7);
	int t;
	while ((t = qu.front()) <= n) {
		if (n % t == 0) return cout << "YES", 0;
		qu.pop();
		qu.push(t * 10 + 4);
		qu.push(t * 10 + 7);
	}
	cout << "NO";
	return 0;
}