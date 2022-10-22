#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int f, s1, s2, f1;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cout << "? 0 0" << endl;
    cin >> f;

    for(int i=29;i>=0;i--)
    {
        cout << "? " << s1+(1ll << i) << ' ' << s2+(1ll << i) << endl;
        cin >> f1;
        if(f1==f)
        {
            cout << "? " << s1 << ' ' << s2+(1ll << i) << endl;
            cin >> f1;
            if(f1==1)
            {
                s1+=(1ll << i);
                s2+=(1ll << i);
            }
        }
        else
        {
            if(f==1)
                s1+=(1ll << i);
            else s2+=(1ll << i);
            cout << "? " << s1 << ' ' << s2 << endl;
            cin >> f;
        }
    }
    cout << "! " << s1 << ' ' << s2 << endl;
}