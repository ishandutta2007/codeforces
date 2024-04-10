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
        vector<int> last(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            last[a[i]]=i;
        }
        int p=0;
        for(int i=1;i<n;i++) if(a[i]>a[i+1]) p=i;
        for(int i=1;i<=p;i++) p=max(p,last[a[i]]);
        vector<int> d(n+1,0);
        for(int i=1;i<=p;i++) d[a[i]]=1;
        int res=0;
        for(int i=1;i<=n;i++) res+=d[i];
        cout << res << "\n";
    }
    return 0;
}