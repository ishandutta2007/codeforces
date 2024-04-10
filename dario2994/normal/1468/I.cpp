#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n;
    cin >> n;
    LL dx1, dy1, dx2, dy2;
    cin >> dx1 >> dy1 >> dx2 >> dy2;
    LL det = llabs(dx1*dy2 - dy1*dx2);
    if (det != n) {
		cout << "NO\n";
		return 0;
	}
	LL gg = llabs(__gcd(dy1, dy2));
	dy1 /= gg, dy2 /= gg;
	LL det2 = llabs(dx1*dy2 - dy1*dx2);
	cout << "YES\n";
	for (int x = 0; x < det2; x++) {
		for (int y = 0; y < gg; y++) cout << x << " " << y << "\n";
	}
}