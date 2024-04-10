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
        vector<int> a(n+2,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        a[n+1]=1;
        vector<int> res(n+2,0);
        for(int i=0;i<=n;i++)
        {
            if(a[i]==0&&a[i+1]==1)
            {
                for(int j=1;j<=i;j++) res[j]=j;
                res[i+1]=n+1;
                for(int j=i+2;j<=n+1;j++) res[j]=j-1;
                break;
            }
        }
        if(res[1]!=0) for(int i=1;i<=n+1;i++) cout << res[i] << " \n"[i==n+1];
        else cout << "-1\n";
    }
    return 0;
}