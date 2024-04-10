#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        int mask = 0;

        for(int j = 30; j >= 0; j--)
        {
            mask += (1 << j);

            map <int, int> mpa, mpb;

            for(int i = 0; i < n; i++)
                mpa[a[i] & mask]++;

            for(int i = 0; i < n; i++)
                mpb[(b[i] & mask) ^ mask]++;

//            cout << mask << endl;
//
//            for(auto x:mpa)
//                cout << x.f << ' ' << x.s << endl;
//
//            for(auto x:mpb)
//                cout << x.f << ' ' << x.s << endl;

            if(mpa != mpb)
                mask -= (1 << j);
        }

        cout << mask << "\n";
    }
}