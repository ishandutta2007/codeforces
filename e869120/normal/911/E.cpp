#include <iostream>
#include <stack>
using namespace std;
#pragma warning (disable: 4996)

stack<int>S; int n, k, a[200009], num = 1; bool used[200009];

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]); used[a[i]] = true;
		while (!S.empty() && S.top() == num) { S.pop(); num++; }
		if (!S.empty() && S.top() < a[i]) { cout << "-1" << endl; return 0; }
		S.push(a[i]);
	}
	int V = 0, rem = k;
	while (!S.empty()) {
		int Y = S.top(); S.pop();
		for (int i = Y; i > V; i--) {
			if (used[i] == false) { a[rem] = i; rem++; }
		}
		V = Y;
	}
	for (int i = n; i > V; i--) { if (used[i] == false) { a[rem] = i; rem++; } }
	for (int i = 0; i < n; i++) {
		if (i)printf(" ");
		printf("%d", a[i]);
	}
	cout << endl;
	return 0;
}