#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, INF = 2147483647;



int main()
{
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	cout << a[2] - a[0];

}