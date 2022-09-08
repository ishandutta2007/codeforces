#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;
const int max_n = -1, inf = 1000111222;

int n;

bool f(int a, int b, int x, int y) {
	cout << "? " << a << " " << b << " " << x << " " << y << endl;
	cout.flush();
	string s;
	cin >> s;
	return s == "YES";
}

string up, down;

void get_up(int x, int y) {
	while (x + y < n + 1) {
		if (f(x, y + 1, n, n)) {
			up += 'R';
			++y;
		} else {
			up += 'D';
			++x;
		}
	}
}

void get_down(int x, int y) {
	while (x + y > n + 1) {
		if (f(1, 1, x - 1, y)) {
			down += 'D';
			--x;
		} else {
			down += 'R';
			--y;
		}
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	/*int x, y;
	for (int i = 1; i <= n; ++i) {
		if (f(1, 1, n - i + 1, i) && f(n - i + 1, i, n, n)) {
			x = n - i + 1;
			y = i;
			break;
		}
	}*/
	get_up(1, 1);
	get_down(n, n);
	reverse(down.begin(), down.end());
	cout << "! " << up + down << endl;
	cout.flush();
	return 0;
}