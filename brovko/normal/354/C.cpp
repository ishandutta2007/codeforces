#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 2e6 + 13;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> L(N);

    for(int i = 0; i < n; i++)
        L[a[i]] = a[i];

    for(int i = 1; i < N; i++)
        if(L[i] == 0)
            L[i] = L[i - 1];

//    for(int i = 0; i < 20; i++)
//        cout << i << ' ' << L[i] << endl;

    int ans = 0;

    for(int i = 1; i < N; i++)
    {
        bool F = (L[i - 1] == 0);

        for(int j = i; j + i < N; j += i)
            F &= (L[j + i - 1] - j <= k);

        if(F)
            ans = i;
    }

    cout << ans;
}