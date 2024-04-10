#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, t, a[200005], b[200005], ans, Min;
vector <pair <int, pair <int, int> > > v;
set <pair <int, pair <int, int> > > s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for(int i=0; i<n; i++)
    {
        cin >> a[i] >> b[i];
        v.push_back({b[i], {a[i], i}});
    }

    sort(v.begin(), v.end());
    Min = 1e9;

    int T = 0;

    for(auto to:v)
        if(to.first <= t)
    {

        int x = to.first;
        int y = to.second.first;
        int z = to.second.second;

        Min = min(Min, y);

        s.insert({y, {x, z}});
        T += x;

        while(Min < s.size() || T > t)
            {
                T -= (*(s.begin())).second.first;
                s.erase(*(s.begin()));

                if(s.size() == 0)
                    Min = 1e9;
                else Min = (*(s.begin())).first;
            }



        ans = max(ans, (int)s.size());
    }

    cout << ans << "\n" << ans << "\n";




    Min = 1e9;
    T = 0;

    while(!s.empty())
        s.erase(*s.begin());


    for(auto to:v)
        if(to.first <= t)
    {

        int x = to.first;
        int y = to.second.first;
        int z = to.second.second;

        Min = min(Min, y);
        s.insert({y, {x, z}});
        T += x;

        while(Min < (int)s.size() || T > t)
            {
                T -= (*(s.begin())).second.first;
                s.erase(*(s.begin()));

                if(s.size() == 0)
                    Min = 1e9;
                else Min = (*(s.begin())).first;
            }


        if((int)s.size() == ans)
        {
            //cout << Min << endl;
            for(int j=0; j<ans; j++)
            {
                cout << ((*s.begin()).second.second + 1) << ' ';
                s.erase(*s.begin());
            }
            return 0;
        }
    }
}

/*

5 1000000
1 1
1 1000
3 100
2 50
4 600

*/