#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=(1<<30);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+2,0);
        a[0]=a[n+1]=inf;
        int m=0;
        int res=-1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            m=max(m,a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==m&&a[i]>min(a[i-1],a[i+1])) res=i;
        }
        cout << res << "\n";
    }
    return 0;
}