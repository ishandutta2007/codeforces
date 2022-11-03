#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
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
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

str s;
vec <char> st;
int uk = 0;
int ans = 0;

char ok(char c)
{
    if (c == '{')
        re '}';
    if (c == '(')
        re ')';
    if (c == '[')
        re ']';
    if (c == '<')
        re '>';
}

bool op(char c)
{
    if (c == '{' || c == '[' || c == '<' || c == '(')
        re true;
    else
        re false;
}

int main()
{
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("approximate.in", "r", stdin); freopen("approximate.out", "w", stdout);
    cin >> s;
    st.resize(1110007);
    forn(i, s.size())
    {
        if (op(s[i]))
        {
            st[uk] = s[i];
            uk++;
        }
        else
        {
            if (uk == 0)
            {
                ans = -1;
                break;
            }
            else
            {
                uk--;
                char c = st[uk];
                if (ok(c) != s[i])
                    ans++;
            }
        }
    }
    if (uk != 0)
        ans = -1;
    if (ans == -1)
        cout << "Impossible";
    else
        cout << ans;
}