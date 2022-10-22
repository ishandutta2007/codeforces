#include <bits/stdc++.h>

using namespace std;


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, K;
        cin >> n >> K;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int L = 0, R = 1e9 + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int k = 0;

            vector <int> b = a;

            for(int i = 0; i < n; i++)
                if(b[i] * 2 < M)
                    b[i] = 1e9, k++;

            int F = 2;

            for(int i = 0; i < n - 1; i++)
            {
                if(min(b[i], b[i + 1]) >= M)
                    F = 0;
                else if(max(b[i], b[i + 1]) >= M)
                    F = min(F, 1);
            }

            k += F;

//            cout << M << ' ' << k << endl;

            if(k <= K)
                L = M;
            else R = M;
        }

        cout << L << "\n";
    }
}

/*
1
2 1
5 9

*/