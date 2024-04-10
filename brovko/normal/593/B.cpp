#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, x1, x2, k[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x1 >> x2;

    for(int i = 0; i < n; i++)
        cin >> k[i] >> b[i];

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
        v.pb({k[i] * x1 + b[i], k[i] * x2 + b[i]});

    sort(v.begin(), v.end());

//    for(auto to:v)
//        cout << to.x << ' ' << to.y << endl;

    for(int i = 1; i < n; i++)
        if(v[i].x > v[i - 1].x && v[i].y < v[i - 1].y)
        {
            cout << "YES";
            return 0;
        }

    cout << "NO";
}