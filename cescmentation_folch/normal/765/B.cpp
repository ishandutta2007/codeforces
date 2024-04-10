#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    int k = 0;
    for (int i = 0; i < a.size(); ++i) {
	if (a[i] - 'a' > k) {
	    cout << "NO" << endl;
	    return 0;
	}
	else if (a[i] - 'a' == k) ++k;
    }
    cout << "YES" << endl;
}