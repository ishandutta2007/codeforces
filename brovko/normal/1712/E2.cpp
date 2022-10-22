#include <bits/stdc++.h>
#define int long long

using namespace std;
using li = long long;

const int N = 2e5 + 5;

vector <int> divs[N];
int L[N], R[N], f[N];
vector <int> Q[N];
vector <int> ans(N);

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += f[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i < N; i |= i + 1)
        f[i] += d;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i)
            divs[j].push_back(i);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
        cin >> L[i] >> R[i];



    for(int i = 0; i < t; i++)
    {
        Q[R[i]].push_back(i);
        Q[L[i] - 1].push_back(i);
    }

    for(int i = 1; i < N; i++)
    {
        int x = (int)divs[i].size() - 1;
        int k = -1;

        while(x > 0)
        {
            k++;
            inc(divs[i][x - 1] + 1, k * (k - 1) / 2);
            inc(divs[i][x] + 1, -(k * (k - 1) / 2));
            x--;
        }

        inc(0, (k + 1) * (k) / 2);
        inc(divs[i][x] + 1, -(k * (k + 1) / 2));

        for(auto j:Q[i])
        {
            if(R[j] == i)
                ans[j] += sum(L[j]);
            else ans[j] -= sum(L[j]);
        }
    }

//    cout << ans[0] << endl;

    for(int j = 0; j < t; j++)
    {
        int l = L[j], r = R[j];

        ans[j] += max(0ll, r / 6 - (2 * l - 1) / 6);
        ans[j] += max(0ll, r / 15 - (5 * l - 1) / 30);

//        for(int i = l; i <= r; i++)
//        {
//            if(i % 6 == 0 && i / 2 >= l)
//                ans[j]++;
//
//            if(i % 15 == 0 && 2 * i / 5 >= l)
//                ans[j]++;
//        }

//        cout << ans << "\n";
    }

    for(int i = 0; i < t; i++)
    {
        cout << (R[i] - L[i] + 1) * 1ll * (R[i] - L[i]) * (R[i] - L[i] - 1) / 6 - ans[i] << "\n";
    }
}