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
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
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

const bool is_testing = 0;
const int p = 31;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 11;
const int MAXN = 2e5 + 7;

int n;
str s;
int a[3];
set<char> ans;

bool odin(int a, int b)
{
    bool f = false;
    if (a==0 && b == 0)
        f = true;
    if (a > 0 && b > 0)
        f = true;
    re f;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("input.txt", "r", stdin);
    }
    cin >> n >> s;
    forn(i, n)
    {
        if (s[i] == 'B')
            a[0]++;
        if (s[i] == 'G')
            a[1]++;
        if (s[i] == 'R')
            a[2]++;
    }
    if (odin(a[0], a[1]))
        ans.in('R');
    if (odin(a[0], a[2]))
        ans.in('G');
    if (odin(a[1], a[2]))
        ans.in('B');
    if (a[0] > 1 && a[1] > 1)
    {
        ans.in('B');
        ans.in('G');
    }
    if (a[0] > 1 && a[2] > 1)
    {
        ans.in('B');
        ans.in('R');
    }
    if (a[1] > 1 && a[2] > 1)
    {
        ans.in('G');
        ans.in('R');
    }


    if (a[0] == 1 && a[1] > 1)
    {
        ans.in('B');
    }
    if (a[0] > 1 && a[1] == 1)
    {
        ans.in('G');
    }



    if (a[0] == 1 && a[2] > 1)
    {
        ans.in('B');
    }
    if (a[0] > 1 && a[2] == 1)
    {
        ans.in('R');
    }



    if (a[1] == 1 && a[2] > 1)
    {
        ans.in('G');
    }
    if (a[1] > 1 && a[2] == 1)
    {
        ans.in('R');
    }
    for (set<char> :: iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it;
}
//190660JM