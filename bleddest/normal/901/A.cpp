#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator << (ostream &out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, const vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

int h;
int a[100043];
vector<int> num;

bool read() {
 	if(scanf("%d", &h) != 1)
 		return false;
 	forn(i, h + 1) scanf("%d", &a[i]);
 	return true;
}

void solve() {
	bool ans = false;
	int pos = -1;
	int n = h + 1;
	forn(i, n - 1)
	{
		if (a[i] >= 2 && a[i + 1] >= 2 && !ans)
		{
			ans = true;
			pos = i;
		}
	}
	if (ans)
	{
		puts("ambiguous");
		num.resize(h + 1);
		int sum = 0;
		for(int i = 0; i <= h; i++)
		{
			num[i] = sum;
			sum += a[i];
		}
		for(int i = 0; i <= h; i++)
			for(int j = 0; j < a[i]; j++)
				printf("%d ", i == 0 ? 0 : num[i - 1] + 1);
		puts("");
		for(int i = 0; i <= h; i++)
			for(int j = 0; j < a[i]; j++)
				if (i == pos + 1 && j == 1)
					printf("%d ", num[i - 1] + 2);
				else
					printf("%d ", i == 0 ? 0 : num[i - 1] + 1);
		puts("");
	}
	else
		puts("perfect");
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	if(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}