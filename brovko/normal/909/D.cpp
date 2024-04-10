#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
vector <int> v, u;
int r[1000005], l[1000005], used[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();
    for(int i=0; i<n; i++)
        v.push_back(i);

    for(int i=0; i<n; i++)
    {
        r[i] = i + 1;
        l[i] = i - 1;
    }

    int x = 0;
    int f = 1;
    while(f)
    {


        u.erase(u.begin(), u.end());
        f = 0;
        for(auto to:v)
        {
            if(r[to] < n && s[to] != s[r[to]])
            {
                f = 1;

                //cout << "!" << to << ' ' << r[to] << endl;

                used[to] = 1;
                used[r[to]] = 1;
                if(l[to] >= 0)
                    {
                        if(used[l[to]] == 0)
                            u.push_back(l[to]);
                    }
            }
        }

        for(int i=0; i<u.size(); i++)
        {
            while(l[u[i]] >= 0 && used[l[u[i]]])
                l[u[i]] = l[l[u[i]]];
        }

        for(int i=(int)u.size()-1; i>=0; i--)
        {
            while(r[u[i]] < n && used[r[u[i]]])
                r[u[i]] = r[r[u[i]]];
        }

        v.erase(v.begin(), v.end());
        for(auto to:u)
            v.push_back(to);

        /*for(auto to:u)
            cout << to << ' ';
        cout << endl;*/



        x++;
    }
    cout << x - 1;
}