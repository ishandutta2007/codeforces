#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

int f(int x)
{
    return (x == 0 ? 0 : f(x / 10) + 1);
}

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

        vector <int> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        map <int, int> A, B;

        for(int i = 0; i < n; i++)
            A[a[i]]++;

        for(int i = 0; i < n; i++)
            B[b[i]]++;

        map <int, int> C;

        vector <int> used(n), ub(n);

        for(int i = 0; i < n; i++)
            if(B[a[i]])
            {
                A[a[i]]--;
                B[a[i]]--;
                used[i] = 1;
                C[a[i]]++;
            }

        for(int i = 0; i < n; i++)
            if(C[b[i]])
            {
                ub[i] = 1;
                C[b[i]]--;
            }

        int ans = 0;

        for(int i = 0; i < n; i++)
            if(a[i] >= 10 && used[i] == 0)
            {
                A[a[i]]--;
                a[i] = f(a[i]);
                A[a[i]]++;
                ans++;
            }

        for(int i = 0; i < n; i++)
            if(b[i] >= 10 && ub[i] == 0)
            {
                B[b[i]]--;
                b[i] = f(b[i]);
                B[b[i]]++;
                ans++;
            }

//        for(int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//
//        cout << "\n";
//
//        for(int i = 0; i < n; i++)
//            cout << b[i] << ' ';
//
//        cout << "\n";

        for(int i = 0; i < n; i++)
            if(used[i] == 0 && B[a[i]])
            {
                A[a[i]]--;
                B[a[i]]--;
                used[i] = 1;
                C[a[i]]++;
            }

        for(int i = 0; i < n; i++)
            if(C[b[i]] && ub[i] == 0)
            {
                C[b[i]]--;
                ub[i] = 1;
            }

//        for(int i = 0; i < n; i++)
//            cout << used[i] << ' ';
//
//        cout << "\n";
//
//        for(int i = 0; i < n; i++)
//            cout << ub[i] << ' ';
//
//        cout << "\n";

        for(int i = 0; i < n; i++)
            ans += (used[i] == 0 && a[i] > 1) + (ub[i] == 0 && b[i] > 1);

        cout << ans << "\n";
    }
}

/*
1
3
2 9 3
1 100 9

*/