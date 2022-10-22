#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if(min(n, m)==1)
    {
        int x=max(n, m);
        if(x%6==0)
            cout << x;
        else if(x%6==5)
            cout << x-1;
        else if(x%6==4)
            cout << x-2;
        else cout << x/6*6;

        return 0;
    }

    if(n+m==5 && n*m==6)
    {
        cout << 4;
        return 0;
    }

    if(max(n, m)<3)
    {
        cout << 0;
        return 0;
    }

    if(min(n, m)==2 && max(n, m)==7)
    {
        cout << 12;
        return 0;
    }



    cout << n*m/2*2;
}