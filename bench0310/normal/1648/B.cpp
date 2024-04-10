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
        int n,c;
        cin >> n >> c;
        vector<int> a(c+1,0);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            a[x]=1;
        }
        vector<int> sum(c+1,0);
        for(int i=1;i<=c;i++) sum[i]=sum[i-1]+a[i];
        auto s=[&](int l,int r)->int{return (sum[r]-sum[l-1]);};
        bool ok=1;
        for(int i=1;i<=c;i++)
        {
            for(int y=1;i*y<=c;y++)
            {
                ok&=(!(a[i]==0&&a[y]==1&&s(i*y,min(c,i*y+y-1))>0));
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}