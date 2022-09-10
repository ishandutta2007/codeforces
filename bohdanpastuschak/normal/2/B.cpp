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

const int MAX = 1 << 10;
int n;
int a[MAX][MAX];
int A2[MAX][MAX];
int A5[MAX][MAX];
int dp2[MAX][MAX];
int dp5[MAX][MAX];

void calc2()
{
    dp2[n][n - 1] = dp5[n][n - 1] = 0;;
    RFOR(i, n, 0)
        RFOR(j, n, 0)
            dp2[i][j] = A2[i][j] + min(dp2[i + 1][j], dp2[i][j + 1]);
}

void calc5()
{
    RFOR(i, n, 0)
        RFOR(j, n, 0)
            dp5[i][j] = A5[i][j] + min(dp5[i + 1][j], dp5[i][j + 1]);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

FOR(i,0,MAX)
    FOR(j,0,MAX)
        dp2[i][j]=dp5[i][j] = INF;
    cin >> n;
    FOR(i, 0, n)
        FOR(j, 0, n)
            cin >> a[i][j];
    bool is_zero = 0;
    string res;
    FOR(i, 0, n)
        FOR(j, 0, n)
            if(!a[i][j])
            {
                is_zero = 1;
                res.clear();
                FOR(x, 0, i)
                    res += 'R';
                FOR(y, 0, n - 1)
                    res += 'D';
                FOR(x, 0, n - i - 1)
                    res += 'R';
            }
    
    FOR(i, 0, n)
        FOR(j, 0, n)
            if (!a[i][j])
                a[i][j] = 10;
    FOR(i, 0, n)
        FOR(j, 0, n)
        {
            int t = a[i][j];
            while(t % 2 == 0)
                A2[i][j]++, t >>= 1;
            t = a[i][j];
            while(t % 5 == 0)
                A5[i][j]++, t /= 5;
        }
        
    calc2();
    calc5();
    if (dp2[0][0] && dp5[0][0] && is_zero)
    {
        
    for(auto& i: res)
        if (i=='D')
            i = 'R';
        else i = 'D';
        cout << 1 << endl <<  res << endl;
        return 0;
    }
    
    res.clear();
    if (dp2[0][0] < dp5[0][0])
    {
        // FOR(i,0,n)
        // {
        //     FOR(j,0,n)
        //         cout << dp2[i][j];
        //     cout << endl;
                
        // }
        int x = 0, y = 0;
        while(x < n - 1&& y < n - 1)
        {
            if (dp2[x][y] - A2[x][y] == dp2[x + 1][y])
                ++x, res.PB('R');
            else
                ++y, res.PB('D');
        }
        
        while(n - 1> x++)
            res.PB('R');
        while(n - 1> y++)
            res.PB('D');
    }
    else
    {
        
        // FOR(i,0,n)
        // {
        //     FOR(j,0,n)
        //         cout << dp5[i][j];
        //     cout << endl;
                
        // }
      int x = 0, y = 0;
        while(x < n - 1&& y < n - 1)
        {
            if (dp5[x][y] - A5[x][y] == dp5[x + 1][y])
                ++x, res.PB('R');
            else
                ++y, res.PB('D');
        }
        
        while(n - 1> x++)
            res.PB('R');
        while(n - 1> y++)
            res.PB('D');   
    }
    for(auto& i: res)
        if (i=='D')
            i = 'R';
        else i = 'D';
        assert(SZ(res) == n + n - 2);
    cout << min(dp2[0][0], dp5[0][0]) << endl << res << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}