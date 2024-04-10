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
const int max_n = 55, inf = 1000111222;

set<PII> S;
int n;

struct point {
	int x, y;

	void read() {
//		while(true)
//		{
//			x = rand() % n + 1;
//			y = rand() % n + 1;
//			if (S.count(MP(x, y))) continue;
//			S.insert(MP(x, y));
//			break;
//		}
		cin >> x >> y;
	}
};

bool cmpx(const point &a, const point &b) {
	return a.x < b.x;
}

bool cmpy(const point &a, const point &b) {
	return a.y < b.y;
}

vector<point> v1, v2;
int A[max_n][max_n];

struct state {
	point a, b;
	string s;

	void reads() {
		a.read();
		b.read();
	}

	void move(int x, int y, int cnt = inf) {

		while (a.x > x && cnt) {
			if (A[a.x-1][a.y]) return;
			swap(A[a.x-1][a.y], A[a.x][a.y]);

			v1.push_back(a);

			--a.x;
			v2.push_back(a);
			--cnt;
			s += "U";
		}
		while (a.x < x && cnt) {
			if (A[a.x+1][a.y]) return;
			swap(A[a.x+1][a.y], A[a.x][a.y]);

			v1.push_back(a);
			++a.x;
			v2.push_back(a);
			--cnt;
			s += "D";
		}
		while (a.y > y && cnt) {

			if (A[a.x][a.y - 1]) return;
			swap(A[a.x][a.y - 1], A[a.x][a.y]);

			v1.push_back(a);
			--a.y;
			v2.push_back(a);
			--cnt;
			s += "L";
		}
		while (a.y < y && cnt) {

			if (A[a.x][a.y + 1]) return;
			swap(A[a.x][a.y + 1], A[a.x][a.y]);

			v1.push_back(a);
			++a.y;
			v2.push_back(a);
			--cnt;
			s += "R";
		}
	}
};

bool cmpax(const state &a, const state &b) {
	return a.a.x < b.a.x;
}

bool cmpay(const state &a, const state &b) {
	return a.a.y < b.a.y;
}

bool cmpbx(const state &a, const state &b) {
	return a.b.x < b.b.x;
}

bool cmpby(const state &a, const state &b) {
	return a.b.y < b.b.y;
}

int m;
state a[max_n];

void write() {
	cout << v1.size() << "\n";
	for (int i = 0; i < v1.size(); ++i) {
		cout << v1[i].x << " " << v1[i].y << " " << v2[i].x << " " << v2[i].y << "\n";
	}
}


bool check(vector<PII> from, vector<PII> to)
{
	FILL(A, -1);

	FOR (i, 0, SZ(from))
	{
		int x = from[i].first;
		int y = from[i].second;

		A[x][y] = i;
	}

	FOR (i, 0, SZ(v1))
	{

//		cout<<"--"<<endl;
//		FOR (j, 1, n+1)
//		{
//			FOR (k, 1, n+1)
//			{
//				if (A[j][k] == -1) cout<<' ';
//				else cout<<(char)('a' + A[j][k]);
//			}
//			cout<<endl;
//		}
//		cout<<"--"<<endl;

		int x1 = v1[i].x;
		int y1 = v1[i].y;
		int x2 = v2[i].x;
		int y2 = v2[i].y;

		if (abs(x1 - x2) + abs(y1 - y2) != 1)
		{
			cout<<"diff != 1 at " << i <<endl;
		}

		if (A[x1][y1] == -1)
		{
			cout<<"No item at "<<i<<endl;
		}
		if (A[x2][y2] != -1)
		{
			cout<<"Bad item ad "<<i<<endl;
		}

		swap(A[x1][y1], A[x2][y2]);
	}
//	FOR (j, 1, n+1)
//			{
//				FOR (k, 1, n+1)
//				{
//					if (A[j][k] == -1) cout<<' ';
//					else cout<<(char)('a' + A[j][k]);
//				}
//				cout<<endl;
//			}
//			cout<<endl;

	FOR (i, 1, n+1)
	{
		FOR (j, 1, n+1)
		{
			if (A[i][j] == -1) continue;
			int ind = A[i][j];
			if (to[ind] != MP(i, j))
			{
				cout<<"Bad final position of "<<ind<<endl;
			}
		}
	}

	return true;
}

int main()
{
//	srand(4774);
//	freopen("in.txt", "r", stdin);
//	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;

	vector<PII> from;
	vector<PII> to;

	FILL(A, 0);

	for (int i = 0; i < m; ++i) {
		a[i].a.read();
		from.PB(MP(a[i].a.x, a[i].a.y));
		A[a[i].a.x][a[i].a.y] = 1;
	}
	for (int i = 0; i < m; ++i) {
		a[i].b.read();

		to.PB(MP(a[i].b.x, a[i].b.y));
	}
	sort(a, a + m, cmpay);
	while (true) {
		bool ok = false;
		for (int i = 0; i < m; ++i) {
			int x = a[i].a.x, y = i + 1;
			if (a[i].a.y != y) {
				bool f = true;
				for (int j = 0; j < m; ++j) {
					if (a[j].a.x == x && a[j].a.y == y) {
						f = false;
						break;
					}
				}
				if (f) {
					ok = true;
					a[i].move(x, y, 1);
				}
			}
		}
		if (!ok) {
			break;
		}
	}
	//write();
//	cout<<SZ(v1)<<endl;
	sort(a, a + m, cmpbx);
	for (int i = 0; i < m; ++i) {
		a[i].move(i + 1, a[i].a.y);
	}
	//write();
//	cout<<SZ(v1)<<endl;
	sort(a, a + m, cmpby);
	for (int i = 0; i < m; ++i) {
		a[i].move(a[i].a.x, i + 1);
	}
//	cout<<SZ(v1)<<endl;
	for (int i = 0; i < m; ++i) {
		a[i].move(a[i].b.x, a[i].a.y);
	}
//	cout<<SZ(v1)<<endl;
	while (true) {
		bool ok = false;
		for (int i = 0; i < m; ++i) {
			int x = a[i].a.x, y = a[i].b.y;
			if (a[i].a.y != y) {
				bool f = true;
				for (int j = 0; j < m; ++j) {
					if (a[j].a.x == x && a[j].a.y == y) {
						f = false;
						break;
					}
				}
				if (f) {
					ok = true;
					a[i].move(x, y, 1);
				}
			}
		}
		if (!ok) {
			break;
		}
	}
	write();
	/*for (int i = 0; i < m; ++i) {
		cout << a[i].s << endl;
	}*/

//	cout<<check(from, to)<<endl;
	return 0;
}