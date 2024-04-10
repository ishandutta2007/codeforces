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
        vector<int> b(n+1,0);
        auto go=[&](int m)
        {
            for(int i=1;i<=m/2;i++) b[i]=a[m+1-i];
            for(int i=m/2+1;i<=m;i++) b[i]=-a[m+1-i];
        };
        if((n%2)==0) go(n);
        else
        {
            go(n-3);
            int x=a[n-2];
            int y=a[n-1];
            int z=a[n];
            int i=-y,j1=x;
            int j2=-z,k=y;
            int p=1+((j1+j2)==0);
            b[n-2]=i;
            b[n-1]=j1+p*j2;
            b[n]=p*k;
        }
        for(int i=1;i<=n;i++) cout << b[i] << " \n"[i==n];
    }
    return 0;
}