#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> ans;
	int count2 = 1;
	while (n > 0) {
		if ((n&1) == 1) {
			ans.push_back(count2);
		}
		n /= 2;
		count2++;
	}
	for (int i = ans.size()-1; i >= 1; --i) {
		cout << ans[i] << " ";
	}
	cout << ans[0];
}