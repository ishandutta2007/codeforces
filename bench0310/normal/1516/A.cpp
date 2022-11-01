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
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++)
        {
            int x=min(k,a[i]);
            a[i]-=x;
            a[n]+=x;
            k-=x;
        }
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}