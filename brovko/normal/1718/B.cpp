#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 50;

vector <int> v[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int k;
        cin >> k;

        vector <int> a(k);

        for(int i = 0; i < k; i++)
            cin >> a[i];

        vector <int> f(N);

        f[0] = f[1] = 1;

        for(int i = 2; i < N; i++)
            f[i] = f[i - 1] + f[i - 2];

        vector <int> used(N);

        for(int i = 0; i < k; i++)
            v[i].erase(v[i].begin(), v[i].end());

        for(int i = 0; i < k; i++)
            for(int j = N - 1; j >= 0; j--)
                if(a[i] >= f[j])
                {
                    a[i] -= f[j];
                    used[j]++;

                    v[i].pb(j);
                }

        bool F = 0;

        for(int i = 0; i < k; i++)
        {


            for(auto x:v[i])
            {
                used[x]--;
                a[i] += f[x];
            }

            bool fl = 1;

            a[i]--;
            v[i].erase(v[i].begin(), v[i].end());

            for(int j = N - 1; j >= 0; j--)
            {
                if(a[i] >= f[j])
                {
                    a[i] -= f[j];
                    used[j]++;

                    if(j == 1)
                        fl = 0;

                    v[i].pb(j);
                }
            }

            used[0]++;



            int r = N - 1;

            while(used[r] == 0)
                r--;

            for(int j = 0; j <= r; j++)
                fl &= (used[j] == 1);

            F |= fl;



//            if(fl)
//            {
//                cout << "! " << i << "\n";
//
//                for(auto x:used)
//                    cout << x << ' ';
//
//                cout << "\n";
//            }

            for(auto x:v[i])
            {
                used[x]--;
                a[i] += f[x];
            }

            a[i]++;
            v[i].erase(v[i].begin(), v[i].end());

            for(int j = N - 1; j >= 0; j--)
            {
                if(a[i] >= f[j])
                {
                    a[i] -= f[j];
                    used[j]++;

                    v[i].pb(j);
                }
            }

            used[0]--;
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}