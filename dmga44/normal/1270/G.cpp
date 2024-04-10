#include <bits/stdc++.h>
using namespace std;
/// MACROS
#define int long long
#define sz size
#define ll long long
#define ull unsigned long long
#define ld long double
#define ii pair<int, int>
#define fst first
#define scd second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define pf push_front
#define fl '\n'
// #define el endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
/// FUNCTIONS
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) __lg(x)
#define pi acos(-1)
#define YN(x) cout << ((x) ? ("YES") : ("NO")) << fl;
#define yn(x) cout << ((x) ? ("Yes") : ("No")) << fl;
#define precision(x)       \
    cout.setf(ios::fixed); \
    cout.precision(x);
void print(const vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << fl;
}
vector<int> read(int cnt)
{
    vi v(cnt);
    for (int i = 0; i < cnt; i++)
        cin >> v[i];
    return v;
}

vi g[1000005];
int prnt[1000005];
bool mk[1000003];
int ig[1000003];
bool vis[1000003];

int found = 0;
int top = 0;

int wr = 1;

void dfs(int u, int p)
{
    prnt[u] = p;
    mk[u] = 1;
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!mk[v])
        {
            dfs(v, u);
        }
        else
        {
            if (vis[v])
            {
                found = u;
                top = v;
            }
        }
    }
    vis[u] = false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        found = 0;
        int enc = 0;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            mk[i] = 0;
            ig[i] = 0;
            vis[i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                enc = i;
            }
            g[i].pb(i - x);
        }

        if (enc)
        {
            cout << 1 << fl;
            cout << enc << fl;
            continue;
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (!mk[i])
            {
                dfs(i, -1);
                int wr = found;
                while (wr != top)
                {
                    ans.pb(wr);
                    wr = prnt[wr];
                }
                ans.pb(top);
                break;
            }
        }


        cout << ans.sz() << fl;
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << fl;
    }

    return 0;
}