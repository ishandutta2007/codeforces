#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int h1, a1, c1, h2, a2;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    while(h2 > 0)
    {
        if(h2 <= a1)
        {
            h2 -= a1;
            v.push_back(1);
        }
        else
            if(h1 > a2)
        {
            h2 -= a1;
            h1 -= a2;
            v.push_back(1);
        }
        else
        {
            h1 += c1 - a2;
            v.push_back(0);
        }
    }

    cout << v.size() << "\n";

    for(auto to:v)
        if(to == 1)
            cout << "STRIKE\n";
        else cout << "HEAL\n";
}