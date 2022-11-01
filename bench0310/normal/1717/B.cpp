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
        int n,k,r,c;
        cin >> n >> k >> r >> c;
        vector res(n+1,string(n+1,'.'));
        auto in=[&](int a,int b)->bool{return (1<=a&&a<=n&&1<=b&&b<=n);};
        auto go=[&](int a,int b)
        {
            if(((a+b)%k)!=((r+c)%k)) return;
            while(in(a,b))
            {
                res[a][b]='X';
                a--;
                b++;
            }
        };
        for(int i=1;i<=n;i++) go(i,1);
        for(int j=2;j<=n;j++) go(n,j);
        for(int i=1;i<=n;i++) cout << res[i].substr(1,n) << "\n";
    }
    return 0;
}