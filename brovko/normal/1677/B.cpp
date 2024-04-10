#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector <int> r(n * m), c(n * m);

        vector <int> dif(m);
        int last = -1e9;

        for(int i = 0; i < n * m; i++)
        {
            r[i] = (i == 0 ? 0 : r[i - 1]) + (s[i] == '1' && i - last >= m) + dif[i % m];

            if(s[i] == '1')
            {
                if(i - last < m)
                {
                    int d = m - (i - last);
                    dif[(i + d) % m]++;
                    dif[i % m]--;
                }

                last = i;
            }

//            cout << r[i] << ' ';
//
//            if(i % m == m - 1)
//                cout << endl;
        }

        vector <int> used(m);
        int k = 0;

        for(int i = 0; i < n * m; i++)
        {
            if(s[i] == '1')
            {
                int j = i % m;

                if(used[j] == 0)
                {
                    used[j] = 1;
                    k++;
                }
            }

            c[i] = k;
        }

        for(int i = 0; i < n * m; i++)
            cout << r[i] + c[i] << ' ';

//        cout << "! " << r[n * m - 1] << ' ' << c[n * m - 1] << endl;

        cout << "\n";
    }
}

/*
1
2 4
11001101

*/