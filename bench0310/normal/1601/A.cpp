#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=200000;
    vector<int> d[N+1];
    for(int i=1;i<=N;i++) for(int j=i;j<=N;j+=i) d[j].push_back(i);
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> ok(n+1,0);
        int r=30;
        for(int i=0;i<30;i++)
        {
            int c=0;
            for(int j=1;j<=n;j++) c+=((a[j]>>i)&1);
            if(c>0)
            {
                for(int x:d[c]) ok[x]++;
            }
            else r--;
        }
        for(int i=1;i<=n;i++) if(ok[i]==r) cout << i << " ";
        cout << "\n";
    }
    return 0;
}