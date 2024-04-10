#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> k;

    vector <int> v;

    while(a)
    {
        v.pb(a % 10);
        a /= 10;
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
    {
        int Max = i;

        for(int j = i; j <= min((int)v.size() - 1, i + k); j++)
        {
            if(v[j] > v[Max])
                Max = j;
        }

        int j = Max;

        while(j > i)
        {
            swap(v[j], v[j - 1]);
            j--;
            k--;
        }
    }

    for(auto x:v)
        cout << x;
}