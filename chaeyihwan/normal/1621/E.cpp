#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

vector<ll> group[100002];
vector<int> ans[100002];
struct groupinfo
{
    ll S, num, idx;
    groupinfo() : groupinfo(0, 0, 0) {}
    groupinfo(ll _S, ll _n, ll _i) : S(_S), num(_n), idx(_i) {}

    bool operator < (const groupinfo O) const
    {
        return S * O.num > O.S * num;
    }
} gi[100002];
ll a[100002];
int state[100002], U[100002], D;

void print(int m)
{
    for(int i=1;i<=m;i++)
    {
        int s = ans[i].size();
        for(int j=1;j<s;j++) cout << ans[i][j];
    }
    cout << "\n";
}

void change(int x)
{
    int u = U[x];
    ll A = a[u];
    ll N = gi[x].num;
    ll S = gi[x].S;
    int I = gi[x].idx;
    int k = group[I].size() - 1;

    for(int i=1;i<=k;i++)
    {
        if(A * (N-1) >= S - group[I][i]) ans[I][i] = 1;
    }
}

void change2(int x)
{
    int u = D;
    ll A = a[u];
    ll N = gi[x].num;
    ll S = gi[x].S;
    int I = gi[x].idx;
    int k = group[I].size() - 1;

    for(int i=1;i<=k;i++)
    {
        if(A * (N-1) >= S - group[I][i]) ans[I][i] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=1;i<=m;i++) group[i].clear();
        for(int i=1;i<=m;i++) ans[i].clear();
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) a[i] = -a[i];
        sort(a+1, a+n+1);
        for(int i=1;i<=n;i++) a[i] = -a[i];

        for(int i=1;i<=m;i++)
        {
            int k; cin >> k;
            group[i].resize(k+1);
            ans[i].resize(k+1);
            ll sum = 0;
            for(int j=1;j<=k;j++)
            {
                cin >> group[i][j];
                sum += group[i][j];
                ans[i][j] = 0;
            }

            gi[i] = groupinfo(sum, k, i);
        }

        sort(gi + 1, gi + m + 1);

        for(int i=1;i<=m;i++)
        {
            if(a[i] * gi[i].num < gi[i].S) state[i] = -1;
            else if(i < n && a[i+1] * gi[i].num >= gi[i].S) state[i] = 1;
            else state[i] = 0;
        }

        U[1] = 1;
        for(int i=2;i<=m;i++)
        {
            if(state[i-1] == 1) U[i] = U[i-1];
            else U[i] = i;
        }

        int cnt = 0;
        for(int i=1;i<=m;i++) if(state[i] == -1) cnt++;

        if(cnt == 0)
        {
            for(int i=1;i<=m;i++) change(i);
            print(m);
            continue;
        }

        if(cnt == 1)
        {
            for(int i=1;i<=m;i++) if(state[i] == -1) change(i);
        }
        bool flag1 = false,flag2 = false;
        if(state[1] == -1) flag1 = true;
        for(int i=2;i<=m;i++)
        {
            if(a[i-1] * gi[i].num < gi[i].S)
            {
                if(flag1) flag2 = true;
                else flag1 = true;
            }
        }

        if(flag2)
        {
            print(m);
            continue;
        }

        for(int i=m;i>=1;i--)
        {
            if(state[i] == -1)
            {
                D = i;
                break;
            }
        }
        for(int i=1;i<=m;i++)
        {
            change2(i);
            if(state[i] == -1) break;
        }

        print(m);
    }
}