#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    const int d=20;
    vector<int> basis(d,0);
    vector<int> t(d,0);
    vector<int> sz(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        sz[i]=sz[i-1];
        for(int j=0;j<d;j++)
        {
            if((a&(1<<j))==0) continue;
            if(basis[j]!=0) a^=basis[j];
            else
            {
                basis[j]=a;
                t[j]=i;
                sz[i]++;
                break;
            }
        }
    }
    const int mod=1000000007;
    vector<int> p(n+1,1);
    for(int i=1;i<=n;i++) p[i]=(2*p[i-1])%mod;
    while(q--)
    {
        int l,x;
        cin >> l >> x;
        bool ok=1;
        for(int j=0;j<d;j++)
        {
            if((x&(1<<j))==0) continue;
            if(basis[j]!=0&&t[j]<=l) x^=basis[j];
            else
            {
                ok=0;
                break;
            }
        }
        cout << ok*p[l-sz[l]] << "\n";
    }
    return 0;
}