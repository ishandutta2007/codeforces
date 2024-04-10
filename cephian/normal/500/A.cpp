#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int n;

bool find(int s, int t) {
	if (s == t)
		return true;
	if (s > t)
		return false;
	return find(s + arr[s], t);
}

int main() {
	ios::sync_with_stdio(0);

	int ind;
	cin >> n >> ind;
	arr.reserve(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	if (find(0, ind - 1))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}