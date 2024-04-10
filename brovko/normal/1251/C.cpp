#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> s;
        vector <int> c, nc;
        for(auto to:s)
            if((to-'0')%2==0)
                c.push_back(to-'0');
            else nc.push_back(to-'0');

        c.push_back(1e9);
        nc.push_back(1e9);

        int x=0;
        int y=0;
        while(x+1<c.size() || y+1<nc.size())
        {
            if(c[x]<nc[y])
            {
                cout << c[x];
                x++;
            }
            else
            {
                cout << nc[y];
                y++;
            }
        }
        cout << "\n";
    }
}