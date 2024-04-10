#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int n, k, a[10005], x[6];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    cout << "or 1 2" << endl;
    cin >> x[0];

    cout << "and 1 2" << endl;
    cin >> x[1];

    cout << "or 1 3" << endl;
    cin >> x[2];

    cout << "and 1 3" << endl;
    cin >> x[3];

    cout << "or 3 2" << endl;
    cin >> x[4];

    cout << "and 3 2" << endl;
    cin >> x[5];

    for(int i = 0; i < 30; i++)
        a[0] += ((x[0] & (1 << i)) + (x[1] & (1 << i)) + (x[2] & (1 << i)) + (x[3] & (1 << i)) - (x[4] & (1 << i)) - (x[5] & (1 << i))) / 2;

    a[1] = (x[0] ^ x[1] ^ a[0]);
    a[2] = (x[4] ^ x[5] ^ a[1]);

    for(int i = 3; i < n; i++)
    {
        int y, z;

        cout << "or 1 " << i + 1 << endl;
        cin >> y;

        cout << "and 1 " << i + 1 << endl;
        cin >> z;

        a[i] = (y ^ z ^ a[0]);
    }

    sort(a, a + n);

    cout << "finish " << a[k - 1] << endl;
}