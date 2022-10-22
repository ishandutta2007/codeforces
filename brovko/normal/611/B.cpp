#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int a, b, ans;
map <int, int> m;

void f(int x, int F)
{
    if(x > b)
        return;

    if(x >= a && F == 1)
    {
        m[x]++;

        if(m[x] == 1)
            ans++;

//        cout << x << ' ';
    }

    f(x * 2 + 1, F);

    if(F == 0)
        f(x * 2, 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    f(1, 0);

    cout << ans;
}