/*
Hanit Banga
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	int a, b;
	cin >> a >> b;

	if (abs(a - b) <= 1 and a + b > 0)
		cout << "YES";

	else
		cout << "NO";
}