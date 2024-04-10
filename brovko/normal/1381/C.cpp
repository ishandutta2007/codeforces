#include <bits/stdc++.h>
//#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int t, n, x, y, a[100005], b[100005], used[100005], c[100005], d[100005], Max;

bool comp(int i, int j)
{
    if(a[i] == Max)
        return false;

    if(a[j] == Max)
        return true;

    return (a[i] < a[j]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x >> y;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n + 2; i++)
        {
            b[i] = 0;
            used[i] = 0;
            c[i] = 0;
            d[i] = 0;
        }

        int k = 0;

        set <pair <int, int> > q;

        vector <int> g[n + 5];

        for(int i = 0; i < n; i++)
        {
            b[a[i]]++;
            g[a[i]].push_back(i);
        }

        for(int i = 1; i <= n + 1; i++)
        {
            q.insert({0, i});
        }

        int mex = 1;

        while(b[mex])
            mex++;

        int f = 0;

        for(int i = 0; i < n * 3; i++)
            if(!q.empty())
        {
            pair <int, int> p = *q.begin();

            if((int)g[p.second].size() > 0 && (p.first + 1) * 2 <= n && (k < y - x || f == 1))
            {
                k++;
                used[g[p.second][(int)g[p.second].size() - 1]] = 1;
                g[p.second].pop_back();

                q.erase(p);
                q.insert({p.first + 1, p.second});

                d[p.second]++;

                if(d[p.second] * 2 > k)
                    f = 1;
                else f = 0;
            }
            else q.erase(p);
        }

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                b[a[i]]--;

        if(k < y - x || n - k < x || f == 1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            Max = 1;

            for(int i = 1; i < n + 2; i++)
                if(b[i] > b[Max])
                    Max = i;

            vector <int> v;

            for(int i = 0; i < n; i++)
            {
                if(used[i] == 1 && a[i] != Max)
                    v.push_back(i);
            }

            for(int i = 0; i < n; i++)
            {
                if(used[i] == 1 && a[i] == Max)
                    v.push_back(i);
            }

            //cout << 1 << endl;

            sort(v.begin(), v.end(), comp);

            //cout << 1.25 << endl;

            for(int i = 0; i < (int)v.size(); i++)
            {
                int z = i + b[Max];
                while(z >= v.size())
                    z -= v.size();
                
                c[v[z]] = a[v[i]];
            }

            //cout << 1.5 << endl;

            for(int i = 0; i < min((int)v.size(), k - (y - x)); i++)
                c[v[i]] = mex;

            //cout << 2 << endl;



            for(int i = 0; i < n; i++)
                if(used[i] == 0)
                {
                    if(x > 0)
                    {
                        x--;
                        c[i] = a[i];
                    }
                    else c[i] = mex;
                }

            for(int i = 0; i < n; i++)
                cout << c[i] << ' ';

            cout << "\n";
        }
    }
}

/*
1
20 0 17
1 19 12 14 20 3 21 9 8 18 16 10 1 21 21 9 14 13 18 3
*/