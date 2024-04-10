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
#define MAXN 55

int a[MAXN][MAXN],b[MAXN],c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<MAXN;i++)
        {
            for(int j=0;j<MAXN;j++)
                a[i][j]=0;
            b[i]=c[i]=0;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
                b[i]+=a[i][j];
                c[j]+=a[i][j];
            }
        int cantc=0,cantb=0;
        for(int i=0;i<n;i++)
            if(!b[i])
                cantb++;
        for(int i=0;i<m;i++)
            if(!c[i])
                cantc++;
        int x=min(cantb,cantc);
        if(x&1)
            db("Ashish")
        else
            db("Vivek")
    }
    return 0;
}