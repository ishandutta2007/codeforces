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
        vector<int> b(n+1,0);
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=1;i<=n;i++) cin >> c[i];
        vector<int> res(n+1,0);
        res[1]=a[1];
        for(int i=2;i<n;i++) res[i]=(a[i]==res[i-1]?b[i]:a[i]);
        if(a[n]!=res[n-1]&&a[n]!=res[1]) res[n]=a[n];
        else if(b[n]!=res[n-1]&&b[n]!=res[1]) res[n]=b[n];
        else res[n]=c[n];
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}