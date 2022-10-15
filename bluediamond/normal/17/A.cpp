#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
bool e[N];
bool shit[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    e[2] = 1;
    for (int i = 3; i <= N; i += 2)
        e[i] = 1;
    for (int i = 3; i * i <= N; i += 2)
        if (e[i])
            for (int j = i * i; j <= N; j += 2 * i)
                e[j] = 0;
    vector<int> all;
    int n, k, cur = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        if (e[i])
            all.push_back(i);
    for (int i = 1; i < (int)all.size(); i++)
    {
        int xo = all[i - 1] + all[i] + 1;
        cur += (xo <= n && e[xo]);
    }
    if (cur >= k)
        cout << "YES\n";
    else
        cout << "NO\n";

}