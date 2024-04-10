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
        int n;
        cin >> n;
        array<int,4> a;
        for(int i=0;i<4;i++) cin >> a[i];
        bool res=0;
        for(int i=0;i<16;i++)
        {
            array<int,4> c;
            for(int j=0;j<4;j++) c[j]=((i>>j)&1);
            bool ok=1;
            for(int j=0;j<4;j++)
            {
                int x=a[j]-c[j]-c[(j+1)%4];
                ok&=(0<=x&&x<=n-2);
            }
            res|=ok;
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}