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
        int x=0;
        for(int i=1;i<=n-1;i++)
        {
            a[i]=i;
            x^=i;
        }
        a[n]=x;
        if(x<=n-1)
        {
            a[n-1-(x==n-1)]^=(1<<30);
            a[n]^=(1<<30);
        }
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}