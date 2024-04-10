#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 3e5 + 5;

int p[N], used[N], a[N], u2[N], f[N], tin[N], tout[N], T, Pair[N], ord[N];
vector <int> g[N], et;

void dfs(int v)
{
    u2[v] = 1;
    et.pb(v);
    tin[v] = T++;

    for(auto to:g[v])
        if(u2[to] == 0)
            dfs(to);

    tout[v] = T - 1;
}

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += f[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i < N; i |= i + 1)
        f[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    stack <int> st;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            if(!st.empty())
                p[i + 1] = st.top() + 1;
            else p[i + 1] = 0;

            st.push(i);
        }
        else
        {
            if(!st.empty())
            {
                used[st.top() + 1] = 1;
                Pair[i + 1] = st.top() + 1;
                st.pop();
            }
        }
    }

    for(int i = 1; i <= n; i++)
        if(used[i])
        {
            g[used[p[i]] ? p[i] : 0].pb(i);
            ord[i] = g[used[p[i]] ? p[i] : 0].size();
        }

//    for(int i = 0; i <= n; i++)
//        for(auto to:g[i])
//            cout << i << ' ' << to << endl;

    for(int i = 0; i <= n; i++)
        a[i] = g[i].size() * 1ll * (g[i].size() + 1) / 2;

    dfs(0);

    for(int i = 0; i < et.size(); i++)
        inc(i, a[et[i]]);

    while(q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if(t == 1)
        {
            int k = g[p[l]].size();
            inc(tin[p[l]], -k * (k + 1) / 2 + k * (k - 1) / 2);
        }
        else
        {
            int R = Pair[r];
            int k = ord[R] - ord[l] + 1;

//            cout << "! " << l << ' ' << R << ' ' << tin[l] << ' ' << tout[R] << endl;

            cout << k * (k + 1) / 2 + sum(tout[R]) - sum(tin[l] - 1) << "\n";
        }
    }
}