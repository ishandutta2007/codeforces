#include <bits/stdc++.h>
//#define int long long
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

        int L = 1, R = n + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            cout << "? " << L << ' ' << M - 1 << endl;

            int k = 0;

            for(int i = L; i < M; i++)
            {
                int x;
                cin >> x;

                if(x >= L && x < M)
                    k++;
            }

            if(k % 2)
                R = M;
            else L = M;
        }

        cout << "! " << L << endl;
    }
}