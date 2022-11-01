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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        bool res=0;
        int all=0;
        for(int i=1;i<=n;i++) all^=a[i];
        int x=0;
        //two
        for(int i=1;i<n;i++)
        {
            x^=a[i];
            res|=(x==(all^x));
        }
        //three
        x=0;
        for(int i=1;i<=n;i++)
        {
            x^=a[i];
            int y=0;
            for(int j=i+1;j<n;j++)
            {
                y^=a[j];
                res|=(x==y&&x==(all^x^y));
            }
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}