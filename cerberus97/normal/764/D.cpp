/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, MX = 1e9;

int main()
{
	int n;
	cin >> n;
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += MX; y1 += MX;
		cout << (x1 % 2) + 2*(y1 % 2) + 1 << '\n';
	}
}