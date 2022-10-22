#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int n, tx[100005], ty[100005];

int sum(int* t, int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int* t, int i, int d)
{
    for(; i < n; i |= i + 1)
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> n >> q;

    vector <int> X(n), Y(n);

    while(q--)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            if(X[x] == 0)
                inc(tx, x, 1);

            if(Y[y] == 0)
                inc(ty, y, 1);

            X[x]++;
            Y[y]++;
        }
        else if(t == 2)
        {
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            if(X[x] == 1)
                inc(tx, x, -1);

            if(Y[y] == 1)
                inc(ty, y, -1);

            X[x]--;
            Y[y]--;
        }
        else
        {
            int x, y, x2, y2;
            cin >> x >> y >> x2 >> y2;

            x--;
            y--;
            x2--;
            y2--;

            if(sum(tx, x2) - sum(tx, x - 1) == x2 - x + 1 || sum(ty, y2) - sum(ty, y - 1) == y2 - y + 1)
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
}