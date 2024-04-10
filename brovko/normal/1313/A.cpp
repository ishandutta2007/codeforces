#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        if(a<b)
            swap(a, b);
        if(b<c)
            swap(b, c);
        if(a<b)
            swap(a, b);
        int k=0;
        if(a)
        {
            a--;
            k++;
        }
        if(b)
        {
            b--;
            k++;
        }
        if(c)
        {
            c--;
            k++;
        }

        if(a!=0 && b!=0)
        {
            a--;
            b--;
            k++;
        }

        if(a!=0 && c!=0)
        {
            a--;
            c--;
            k++;
        }

        if(b!=0 && c!=0)
        {
            b--;
            c--;
            k++;
        }

        if(a!=0 && b!=0 && c!=0)
        {
            a--;
            b--;
            c--;
            k++;
        }

        cout << k << endl;
    }
}