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
const int MAXN = 1;

int n, siz = 0, head = -1;
map <str, int> name;
map <int, str> know;
int next1[200007], pred[200007];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen("stones.in", "r", stdin); freopen("stones.out", "w", stdout);
    srand(14123);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n;
    forn(i, n)
    {
        str s;
        cin >> s;
        int id;
        if (!name.count(s))
        {
            name[s] = ++siz;
            know[siz] = s;
            id = siz;
            if (head == -1)
            {
                head = id;
                next1[id] = -1;
                pred[id] = -1;
            }
            else
            {
                pred[head] = id;
                next1[id] = head;
                head = id;
            }
        }
        else
        {
            id = name[s];
            if (id != head)
            {
                next1[ pred[id] ] = next1[id];
                if (next1[id] != -1)
                    pred[ next1[id] ] = pred[id];
                pred[head] = id;
                next1[id] = head;
                head = id;
            }
        }
    }
    int uk = head;
    while(uk != -1)
    {
        cout << know[uk] << LN;
        uk = next1[uk];
    }
}
//190660JM