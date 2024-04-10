#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 3e5 + 5;

int n, q, p[N], used[N], a[N], u2[N], f[N], tin[N], tout[N], T, Pair[N], ord[N], qt[N], ql[N], qr[N], K[N];
vector <int> g[N], et, ford[N];
string s;

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

int sum_ord(int v, int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += ford[v][r];

    return ans;
}

void inc_ord(int v, int i, int d)
{
    for(; i < ford[v].size(); i |= i + 1)
        ford[v][i] += d;
}

void naive()
{
    for(int i = 0; i < q; i++)
    {
        int l = ql[i], r = qr[i], t = qt[i];
        l--;
        r--;

        if(t == 1)
        {
            s[l] = s[r] = '.';
        }
        else
        {
            int ans = 0;

            for(int L = l; L <= r; L++)
            {
                int x = 0;

                for(int R = L; R <= r; R++)
                {
                    x += (s[R] == '(' ? 1 : s[R] == ')' ? -1 : 0);

                    if(x < 0)
                        break;

                    if(x == 0 && s[L] != '.' && s[R] != '.')
                        ans++;
                }
            }

            cout << ans << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    int n, q;
    cin >> n >> q;

//    string s;
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
            p[i] = (used[p[i]] ? p[i] : 0);
            g[p[i]].pb(i);
            ord[i] = ford[p[i]].size();
            ford[p[i]].pb(0);
        }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j < ford[i].size(); j++)
            inc_ord(i, j, 1);

//    for(int i = 0; i <= n; i++)
//        for(auto to:g[i])
//            cout << i << ' ' << to << endl;

    for(int i = 0; i <= n; i++)
        K[i] = g[i].size();

    for(int i = 0; i <= n; i++)
        a[i] = g[i].size() * 1ll * (g[i].size() + 1) / 2;

    dfs(0);

    for(int i = 0; i < et.size(); i++)
        inc(i, a[et[i]]);

    set <int> S;

    for(int i = 1; i <= n; i++)
        if(used[i] || s[i - 1] == ')' && used[Pair[i]])
            S.insert(i);

    for(int i = 0; i < q; i++)
    {
        int t, l, r;
        cin >> qt[i] >> ql[i] >> qr[i];
        t = qt[i], l = ql[i], r = qr[i];

        if(t == 1)
        {
            inc(tin[p[l]], -K[p[l]]);
            K[p[l]]--;
            inc_ord(p[l], ord[l], -1);

            S.erase(l);
            S.erase(r);
        }
        else
        {
            if(S.lower_bound(l) == S.end() || S.upper_bound(r) == S.begin())
            {
                cout << "0\n";
                continue;
            }

            l = (*S.lower_bound(l));
            auto it = S.upper_bound(r);
            it--;
            r = (*it);

            if(l > r)
            {
                cout << "0\n";
                continue;
            }

            int R = Pair[r];

            int k = sum_ord(p[l], ord[R]) - sum_ord(p[l], ord[l] - 1);

            cout << k * (k + 1) / 2 + sum(tout[R]) - sum(tin[l] - 1) << "\n";
        }
    }

//    cout << endl;
//    naive();
}

/*
10 3
(()()))(()
1 2 3
1 4 5
2 1 6

*/