#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n++;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=1; i<n; i++)
        if(a[i] > 1 && a[i - 1] > 1)
    {
        cout << "ambiguous\n";
        int s = 0;

        for(int j=0; j<n; j++)
        {
            for(int k=0; k<a[j]; k++)
                cout << s << ' ';
            s += a[j];
        }

        cout << "\n";

        s = 0;
        for(int j=0; j<n; j++)
        {
            if(j == i)
            {
                cout << s - 1 << ' ';
                for(int k=1; k<a[j]; k++)
                    cout << s << ' ';
            }
            else
            {
                for(int k=0; k<a[j]; k++)
                    cout << s << ' ';
            }

            s += a[j];
        }

        return 0;
    }

    cout << "perfect";
}