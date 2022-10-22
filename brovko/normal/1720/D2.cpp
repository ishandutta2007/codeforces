#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 3e5 + 5;
const int LOGN = 30;

int val[LOGN][N][2][2];

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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int A[n][30], B[n][30], C[n][30];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 30; j++)
            {
                A[i][j] = ((i ^ a[i]) & ~((1 << j + 1) - 1));
                B[i][j] = bool(i & (1 << j));
                C[i][j] = bool(a[i] & (1 << j));
            }

//        for(int i = 0; i < n; i++)
//            cout << A[i][0] << ' ';
//
//        cout << "\n";

        vector <int> v[30];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 30; j++)
                v[j].pb(A[i][j]);

        for(int j = 0; j < 30; j++)
        {
            sort(v[j].begin(), v[j].end());
            v[j].erase(unique(v[j].begin(), v[j].end()), v[j].end());
        }


//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < 30; j++)
//                cout << A[i][j] << ' ';
//
//        cout << endl;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 30; j++)
                A[i][j] = lower_bound(v[j].begin(), v[j].end(), A[i][j]) - v[j].begin();

//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < 30; j++)
//                cout << A[i][j] << ' ';
//
//        cout << endl;

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int dp = 1;

            for(int j = 0; j < 30; j++)
            {
                dp = max(dp, val[j][A[i][j]][1 ^ C[i][j]][B[i][j]] + 1);
            }

            for(int j = 0; j < 30; j++)
                val[j][A[i][j]][B[i][j]][C[i][j]] = max(val[j][A[i][j]][B[i][j]][C[i][j]], dp);

            ans = max(ans, dp);
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 30; j++)
                val[j][A[i][j]][B[i][j]][C[i][j]] = 0;

        cout << ans << "\n";
    }
}