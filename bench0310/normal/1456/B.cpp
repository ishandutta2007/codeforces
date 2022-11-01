#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+2,0);
    a[n+1]=2000000000;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++)
    {
        int x=a[i]^a[i+1];
        if(a[i-1]>x||x>a[i+2])
        {
            cout << "1\n";
            return 0;
        }
    }
    assert(n<=60);
    int res=n;
    for(int i=1;i<=n;i++)
    {
        int x=0;
        for(int j=i;j<=n;j++)
        {
            x^=a[j];
            if(a[i-1]>x||x>a[j+1]) res=min(res,j-i);
            int y=0;
            for(int k=j+1;k<=n;k++)
            {
                y^=a[k];
                if(x>y) res=min(res,j-i+k-(j+1));
            }
        }
    }
    if(res==n) res=-1;
    cout << res << "\n";
    return 0;
}