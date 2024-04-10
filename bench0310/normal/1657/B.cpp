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
        int n,b,x,y;
        cin >> n >> b >> x >> y;
        ll res=0;
        int a=0;
        for(int i=1;i<=n;i++)
        {
            if(a+x<=b) a+=x;
            else a-=y;
            res+=a;
        }
        cout << res << "\n";
    }
    return 0;
}