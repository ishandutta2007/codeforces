#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[200002];
int l[200002], r[200002];

vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++)
    {
        if(l[a[i]] == 0) l[a[i]] = i;
        else r[a[i]] = i;
    }

    for(int i=1;i<=n;i++)
    {
        if(l[a[i]] != 0 && r[a[i]] != 0) v.push_back({l[a[i]], r[a[i]]});
    }

    sort(v.begin(), v.end());
    if(v.empty()) { cout << "0"; return 0; }
    int m = v.size();

    int ans = 0;
    int s=0,b=0,c=0,cnt=1;
    for(int i=1;i<m;i++)
    {
        if(v[i].first > v[c].second)
        {
            ans += v[c].second - v[s].first - cnt;
            s = i; b = i; c = i; cnt = 1;
            continue;
        }
        if(v[i].second > v[c].second)
        {
            if(b == c) { c = i; cnt++; }
            else if(v[i].first > v[b].second) { cnt++; b = c; c = i; }
            else c = i;
        }
    }
    ans += v[c].second - v[s].first - cnt;

    cout << ans;
}