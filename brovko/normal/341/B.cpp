#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

using li = long long;
const int N = 1e5 + 5;

int t[N];

int get(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans = max(ans, t[r]);

    return ans;
}

void upd(int i, int val)
{
    for(; i < N; i |= i + 1)
        t[i] = max(t[i], val);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        upd(a[i], get(a[i]) + 1);

//        cout << get(N - 1) << endl;
    }

    cout << get(N - 1);
}

/*
7
5 4 6 3 2 1 7

*/