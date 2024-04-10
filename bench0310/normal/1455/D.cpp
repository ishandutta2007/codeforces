#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=500;
    const int inf=N+1;
    auto mn=[](int &a,int b){a=min(a,b);};
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<vector<int>> nxt(N+1,vector<int>(N+1,0));
        for(int i=n;i>=1;i--)
        {
            vector<vector<int>> now(N+1,vector<int>(N+1,inf));
            for(int j=0;j<=N;j++)
            {
                for(int k=0;k<=N;k++)
                {
                    if(j<=a[i]) mn(now[j][k],nxt[a[i]][k]);
                    if(j<=k&&k<a[i]) mn(now[j][k],nxt[k][a[i]]+1);
                }
            }
            nxt=now;
        }
        if(nxt[0][x]<inf) cout << nxt[0][x] << "\n";
        else cout << "-1\n";
    }
    return 0;
}