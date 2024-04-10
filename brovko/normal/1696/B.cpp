#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

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
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int L = 0, R = n - 1;

        while(L < n && a[L] == 0)
            L++;

        while(R >= 0 && a[R] == 0)
            R--;

        if(L == n)
            cout << "0\n";
        else
        {
            int k = 0;

            for(int i = L; i <= R; i++)
                if(a[i] == 0)
                    k++;

            if(k)
                cout << "2\n";
            else cout << "1\n";
        }
    }
}