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

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    cout << (6* n - 1) * k << endl;
    int start = 2;
    FOR(i, 0, n)
    {
        for(int j = 6*i + 1; j <= 6*i + 5; j += 2)
            cout << k * j << " ";
       
        while(1)
        {
            bool mo = 1;
             for(int j = 6*i + 1; j <= 6*i + 5; j += 2)
                mo &= __gcd(j, start) == 1;
            if (!mo)
            {
                start += 2;
                continue;
            }
            
            break;
        }
        
       
        cout << start* k << endl;
        start += 2;
    }
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}