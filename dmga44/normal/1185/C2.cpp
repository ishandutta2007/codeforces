#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
typedef pair<char,int> pci;
#define MAXT 105

int f[MAXT];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,t;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        int sum=0,s2=0;
        for(int j=1;j<=100;j++)
            if(sum+(f[j]*j)+t<=m)
            {
                sum+=f[j]*j;
                s2+=f[j];
            }
            else
            {
                s2+=(m-sum-t)/j;
                break;
            }
        cout << i-s2 << ' ';
        f[t]++;
    }
    cout << '\n';

    return 0;
}