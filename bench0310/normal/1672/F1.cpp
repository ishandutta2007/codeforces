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
        vector<int> a(n,0);
        vector<int> c(n+1,0);
        vector<array<int,2>> v(n);
        int m=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            m=max(m,(++c[a[i]]));
            v[i]={a[i],i};
        }
        ranges::sort(v);
        vector<int> b(n);
        for(int i=0;i<n;i++) b[v[i][1]]=v[(i+m)%n][0];
        for(int i=0;i<n;i++) cout << b[i] << " \n"[i==n-1];
    }
    return 0;
}