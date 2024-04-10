#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 1 << 20;
int k;
PII e[MAX];
int cnt = 0;

void buduj(int v)
{
    for(int i = v + 3; i <= v + k + 1; ++i)
        e[cnt++] = MP(v, i);
    for(int i = v + 1; i <= v + 2; ++i)
        for(int j = i + 1; j <= v + k + 1; ++j)
            e[cnt++] = MP(i, j);
    for(int i = v + 3; i <= v + k + 1; ++i)
         for(int j = i + 1 + ((i - v) & 1); j <= v + k + 1; ++j)
            e[cnt++] = MP(i, j);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

    cin >> k;
    if (k % 2 == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    if (k== 1)
    {
        cout << "2 1" << endl << "1 2" << endl;
        return 0;
    }
    int v = 2;
    FOR(i, 0, k)
    {
        buduj(v);
        e[cnt++] = MP(1, v);
        v += k + 2;
    }
    cout << v - 1 << " " << cnt << endl;
    FOR(i, 0, cnt)
        cout << e[i].X << " " << e[i].Y << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}