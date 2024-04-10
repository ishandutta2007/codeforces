#include <iostream>
using namespace std;

int main() {
	int n; cin >> n >> ws; char ch;
	int cnt['z' + 1] = {0};
	int ans = 0;
	while (n --) {
		cin >> ch; ch = tolower(ch);
		ans += cnt[ch] == 0;
		cnt[ch] = 1;
	}
	cout << (ans == 'z' - 'a' + 1 ? "YES" : "NO");
	return 0;
}