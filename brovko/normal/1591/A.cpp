#include <bits/stdc++.h>

using namespace std;

int n, a[105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int s = 1;

        for(int i = 0; i < n; i++)
            s += a[i];

        int F = 1;

        for(int i = 1; i < n; i++)
        {
            if(a[i] == 0 && a[i - 1] == 0)
                F = 0;

            if(a[i] == 1 && a[i - 1] == 1)
                s += 4;
        }

        if(F)
            cout << s << "\n";
        else cout << "-1\n";
    }
}