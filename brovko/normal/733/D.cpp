#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], b[100005], c[100005];
map <pair <int, int>, int> q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int Max = 0;
    int ind = 0;
    int ind2 = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];

        if(a[i] > b[i])
            swap(a[i], b[i]);

        if(b[i] > c[i])
            swap(b[i], c[i]);

        if(a[i] > b[i])
            swap(a[i], b[i]);

        int x = q[{b[i], c[i]}];

        if(x > 0)
        {
            x--;

            if(min(a[x] + a[i], min(b[i], c[i])) > Max)
               {
                   Max = min(a[x] + a[i], min(b[i], c[i]));
                   ind = i + 1;
                   ind2 = x + 1;
               }

            if(a[i] > a[x])
                q[{b[i], c[i]}] = i + 1;
        }
        else
        {
            if(min(a[i], min(b[i], c[i])) > Max)
            {
                Max = min(a[i], min(b[i], c[i]));
                ind = i + 1;
                ind2 = 0;
            }

            q[{b[i], c[i]}] = i + 1;
        }
    }

    if(ind2 == 0)
    {
        cout << "1\n";
        cout << ind;
    }
    else
    {
        cout << "2\n" << ind << ' ' << ind2;
    }
}