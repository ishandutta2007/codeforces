#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> v;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n - 2; j++)
        {
            while(a[j + 1] > a[j + 2] || a[j] > a[j + 2])
            {
                v.push_back(j + 1);

                swap(a[j], a[j + 1]);
                swap(a[j], a[j + 2]);
            }
        }

        int f = 0;

        if(a[0] == a[2] && a[0] > a[1])
        {
            v.push_back(1);
            v.push_back(1);
            swap(a[0], a[1]);
        }

        if(a[0] == a[2] && a[0] < a[1])
        {
            v.push_back(1);
            swap(a[1], a[2]);
        }

        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1])
                f = 1;

        if(f == 0)
        {
            cout << v.size() << "\n";

            for(auto to:v)
                cout << to << ' ';
        }
        else
        {
            int pp = 0;
            
            for(int i = 2; i < n - 1; i++)
                if(a[i] == a[i + 1] && pp == 0)
            {
                v.push_back(i);
                v.push_back(i - 1);
                swap(a[i - 1], a[i - 2]);
                pp = 1;
            }

            for(int i = 0; i < n; i++)
                for(int j = 0; j < n - 2; j++)
            {
                while(a[j + 1] > a[j + 2] || a[j] > a[j + 2])
                {
                    v.push_back(j + 1);

                    swap(a[j], a[j + 1]);
                    swap(a[j], a[j + 2]);
                }
            }

            if(a[0] > a[1] || a[0] > a[2] || a[1] > a[2])
            {
                v.push_back(1);
                swap(a[0], a[1]);
                swap(a[0], a[2]);
            }

            if(a[0] > a[1] || a[0] > a[2] || a[1] > a[2])
            {
                v.push_back(1);
                swap(a[0], a[1]);
                swap(a[0], a[2]);
            }


            f = 0;

            for(int i = 0; i < n - 1; i++)
                if(a[i] > a[i + 1])
                    f = 1;

            if(f == 0)
            {
                cout << v.size() << "\n";

                for(auto to:v)
                    cout << to << ' ';
            }
            else cout << -1;
        }

        cout << "\n";
    }
}