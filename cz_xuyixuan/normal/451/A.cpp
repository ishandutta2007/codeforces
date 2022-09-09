#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (min(n, m) & 1) cout << "Akshat" << endl;
	else cout << "Malvika" << endl;
	return 0;
}