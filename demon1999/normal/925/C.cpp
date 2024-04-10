#include <bits/stdc++.h>

using namespace std;

vector<long long> v[60];
int cnt[60];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("C.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        int last = 0;
        for (int j = 0; j < 60; j++)
        {
            if (x & (1ll << j))
            {
                cnt[j]++;
                last = j;
            }
        }
        v[last].push_back(x);
    }
    for (int i = 0; i < 60; i++)
    {
        if (v[i].size() > cnt[i] - v[i].size() + 1)
        {
            cout << "No" << endl;
            //cout << i << " " << v[i].size() << " " << cnt[i] << endl;
            return 0;
        }
    }
    long long cur = 0;
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (v[j].size() > 0 && (cur & (1ll << j)) == 0ll)
            {
                cout << v[j][v[j].size() - 1] << " ";
                cur ^= v[j][v[j].size() - 1];
                v[j].pop_back();
                break;
            }
        }
    }
    cout << endl;
    return 0;
}