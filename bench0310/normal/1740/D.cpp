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
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> a(k+1,0);
        for(int i=1;i<=k;i++) cin >> a[i];
        int cnt=n*m-4;
        bool ok=1;
        vector<int> now(k+1,0);
        int x=k;
        for(int i=1;i<=k;i++)
        {
            if(a[i]==x) x--;
            else
            {
                ok&=(cnt>=1);
                cnt--;
                now[a[i]]=1;
            }
            while(now[x]==1)
            {
                now[x]=0;
                cnt++;
                x--;
            }
        }
        if(ok) cout << "YA\n";
        else cout << "TIDAK\n";
    }
    return 0;
}