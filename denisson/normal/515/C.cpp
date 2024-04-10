#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//

#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)

//
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const bool is_testing = false;
const int p = 31;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 8;

str s;
int ans[10];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> s >> s;
    forn(i, s.size())
    {
        if(s[i] == '2')
            ans[2]++;
        if(s[i] == '3')
            ans[3]++;
        if(s[i] == '4')
            ans[2] += 2, ans[3]++;
        if(s[i] == '5')
            ans[5]++;
        if(s[i] == '6')
            ans[3]++, ans[5]++;
        if(s[i] == '7')
            ans[7]++;
        if(s[i] == '8')
            ans[7]++, ans[2] += 3;
        if(s[i] == '9')
            ans[7]++, ans[3] += 2, ans[2] += 1;
    }
    for (int i = 9; i >= 2; i--)
        while(ans[i])
            cout << i, ans[i]--;
}
//190660JM