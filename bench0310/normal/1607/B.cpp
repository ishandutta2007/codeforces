#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll x,n;
        cin >> x >> n;
        ll y=-1;
        ll c=(n-1)/4;
        y-=4*c;
        int z=0;
        for(ll m=4*c+2;m<=n;m++)
        {
            if(z<=1) y+=m;
            else y-=m;
            z++;
        }
        if(n==0) cout << x << "\n";
        else if((x%2)==0) cout << x+y << "\n";
        else cout << x-y << "\n";
    }
    return 0;
}