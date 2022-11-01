#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    int l=1,r=n+1;
    while(l<r-1)
    {
        int m=(l+r)/2;
        map<int,int> b;
        b[0]=0;
        bool ok=0;
        int s=0;
        for(int i=1;i<=n;i++)
        {
            int d=(a[i]<m?1:-1);
            s+=d;
            if(b.find(s)==b.end()) b[s]=i;
            if(s<0) ok|=(i>=k);
            else ok|=(b.find(s+1)!=b.end()&&i-b[s+1]>=k);
        }
        if(ok) l=m;
        else r=m;
    }
    cout << l << "\n";
    return 0;
}