#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1000005

int f[MAXN],g[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=0;i<n;i++)
        scanf("%d",&f[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&g[i]);

    int p1=0;
    while(f[p1]%p==0)
        p1++;
    int p2=0;
    while(g[p2]%p==0)
        p2++;
    db(p1+p2)


    return 0;
}