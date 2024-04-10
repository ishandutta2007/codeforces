#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b; cin >> a >> b;
	for(int i = a.size() - 1; i >= 0; --i) if(a[i] < 'z') {
		a[i]++;
		for(int j = i + 1; j < a.size(); ++j) a[j] = 'a';
		break;
	}
	if(a < b) cout << a << endl;
	else puts("No such string");
	return 0;
}