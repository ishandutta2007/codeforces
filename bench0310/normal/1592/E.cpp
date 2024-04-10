#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<array<int,2>> v((1<<20),{n+1,n+1});
    int res=0;
    for(int b=0;b<20;b++)
    {
        int up=(1<<20)-(1<<(b+1));
        vector<int> x(n+1,0);
        for(int i=1;i<=n;i++) x[i]=x[i-1]^(a[i]&up);
        int l=1;
        while(l<=n)
        {
            if((a[l]&(1<<b))==0)
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<=n&&(a[r+1]&(1<<b))) r++;
            for(int i=l;i<=r;i++)
            {
                v[x[i-1]][i&1]=min(v[x[i-1]][i&1],i);
                res=max(res,i-v[x[i]][!(i&1)]+1);
            }
            for(int i=l;i<=r;i++) v[x[i-1]][i&1]=n+1;
            l=r+1;
        }
    }
    cout << res << "\n";
    return 0;
}