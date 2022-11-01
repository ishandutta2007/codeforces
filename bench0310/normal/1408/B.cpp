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
        int res=0;
        if(k==1)
        {
            if(a[1]==a[n]) res=1;
            else res=-1;
        }
        else
        {
            int c=1;
            for(int i=2;i<=n;i++) c+=(a[i]!=a[i-1]);
            if(c==1) res=1;
            else res=(c-1+k-2)/(k-1);
        }
        cout << res << "\n";
    }
    return 0;
}