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
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        vector<int> b(n+1,0);
        vector<int> c;
        for(int i=1;i<=n;i++)
        {
            cin >> b[i];
            if(b[i]==0) c.push_back(a[i]);
        }
        sort(c.begin(),c.end());
        int idx=0;
        for(int i=n;i>=1;i--) if(b[i]==0) a[i]=c[idx++];
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}