#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN (ll)(35)

int a[MAXN][MAXN];
int fs[2*MAXN],tot[2*MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
                int c=min(n+m-2-(i+j),i+j);
                tot[c]++;
                fs[c]+=a[i][j];
            }
        int res=0;
        for(int i=0;i<(n+m-1)/2;i++)
            res+=min(fs[i],tot[i]-fs[i]);
        db(res)

        for(int i=0;i<2*MAXN;i++)
            tot[i]=fs[i]=0;
    }

    return 0;
}
/**
1
2 2
1 1
0 1
**/