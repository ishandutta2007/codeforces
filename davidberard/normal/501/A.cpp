#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int vasya = max(3*b/10, b-b/250*d);
	int misha = max(3*a/10, a-a/250*c);
	if(vasya > misha) cout << "Vasya" << endl;
	else if(vasya < misha) cout << "Misha" << endl;
	else cout << "Tie" << endl;

	return 0;
}