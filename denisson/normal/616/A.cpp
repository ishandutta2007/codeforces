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

const int MAXN = 100007;
char ss1[1000007], ss2[1000007];
int uk1 = 0, uk2 = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    scanf("%s", ss1);
    scanf("%s", ss2);
    str s1 = ss1, s2 = ss2;
    while(s1[uk1] == '0')
        uk1++;
    while(s2[uk2] == '0')
        uk2++;
    if (s1.size() - uk1 < s2.size() - uk2)
    {
        cout << "<";
        exit(0);
    }
    if (s1.size() - uk1 > s2.size() - uk2)
    {

        cout << ">";
        exit(0);
    }
    for (int i = 0; i < s1.size() - uk1; i++)
    {
        if (s1[uk1 + i] - '0' < s2[uk2 + i] - '0')
        {
            cout << "<";
            exit(0);
        }
        if (s1[uk1 + i] - '0' > s2[uk2 + i] - '0')
        {
            cout << ">";
            exit(0);
        }
    }
    cout << "=";
}