#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int x;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    while(x % 10 == 0)
        x /= 10;

    while(x)
    {
        v.push_back(x % 10);
        x /= 10;
    }

    for(int i=0; i<v.size(); i++)
        if(v[i] != v[(int) v.size() - 1 - i])
    {
        cout << "NO";
        return 0;
    }

    cout << "YES";
}