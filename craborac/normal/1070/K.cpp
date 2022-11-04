#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

ll a[(int)1e5 + 10];

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % k != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    sum /= k;
    ll s = 0;
    int last = -1;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        if (s > sum)
        {
            cout << "No" << endl;
            return 0;
        }
        if (s == sum)
        {
            ans.push_back(i - last);
            last = i;
            s = 0;
        }
    }
    cout << "Yes" << endl;
    for (int i: ans)
        cout << i << " ";
    cout << endl;
    return 0;
}