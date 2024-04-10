#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod (ll)(1e9+7)
#define MAXN 1005

int f[MAXN],r,aux[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    f[0]++;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<min(n,2*n-i-1);j++)
            aux[j+1]=f[j];
        for(int j=1;j<=n;j++)
            aux[j-1]=(aux[j-1]+f[j])%mod;
        for(int j=0;j<MAXN;j++)
            f[j]=aux[j],aux[j]=0;
        if(!(i&1))
            for(int j=0;j<MAXN;j++)
                r=(r+f[j])%mod;
//        for(int j=0;j<=n;j++)
//            cout << f[j] << ' ';
//        cout << '\n';
    }
    db(r)

    return 0;
}