#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define wp(x) cout << x.first << ' ' << x.second << '\n';
#define wm(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' '; cout << LN;
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;

int n;
pair <db, db> t;
pair <db, db> a[100007];
db ma = -LINF, mi = LINF;

db dist(pair <db, db> t1, pair <db, db> t2){
	re sqrt((t1.XX - t2.XX) * (t1.XX - t2.XX) + (t1.YY - t2.YY) * (t1.YY - t2.YY));
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
    int n;
    cin >> n;
    pair<double, double> P;
    cin >> P.first >> P.second;
    vector<pair<double, double> > a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    double mini = 1e18, maxi = -1;
    for (int i = 0; i < n; i++)
    {
        double pa = dist(P, a[i]), pb = dist(P, a[(i + 1) % n]);
        maxi = max(maxi, pa);
        mini = min(mini, pa);
        double ab = dist(a[i], a[(i + 1) % n]);
        if (pb*pb + ab*ab >= pa*pa && pa*pa + ab*ab >= pb*pb)
        {
            double p = (pa + pb + ab)*0.5;
            double S = sqrt(p*(p - pa)*(p - pb)*(p - ab));
            double h = 2 * S / ab;
            mini = min(mini, h);
        }
    }
    printf("%.12f\n", pi * (maxi*maxi - mini*mini));
    return 0;
	cout.precision(8);
	cout << pi * (ma * ma - mi * mi);
}