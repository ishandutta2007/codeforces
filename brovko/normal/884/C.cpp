#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], used[100005];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }

    for(int i = 0; i < n; i++)
        if(used[i] == 0)
    {
        int k = 0;
        int x = i;

        while(used[x] == 0)
        {
            k++;
            used[x] = 1;
            x = a[x];
        }

        v.push_back(k);
    }

    sort(v.begin(), v.end());

    if(v.size() == 1)
    {
        cout << v[0] * v[0];
        return 0;
    }

    int s = v[(int)v.size() - 1] + v[(int)v.size() - 2];
    s *= s;

    for(int i = 0; i < (int)v.size() - 2; i++)
        s += v[i] * v[i];

    cout << s;
}