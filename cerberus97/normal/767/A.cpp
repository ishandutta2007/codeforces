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

const int N = 1e5 + 5;

bool have[N] = {0};

int main()
{
	int n;
	cin >> n;

	int nxt = n;
	for (int i = 1; i <= n; ++i)
	{	
		int a;
		cin >> a;
		have[a] = 1;
		while (nxt > 0 and have[nxt])
		{
			cout << nxt << ' ';
			--nxt;
		}

		cout << endl;
	}
}