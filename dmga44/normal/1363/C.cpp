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
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 1005

int cant[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x,u,v;
        cin >> n >> x;
        x--;
        for(int i=0;i<n;i++)
            cant[i]=0;
        for(int i=0;i<n-1;i++)
        {
            cin >> u >> v;
            u--,v--;
            cant[u]++;
            cant[v]++;
        }

        if(cant[x]<2)
            db("Ayush")
        else
        {
            int nodes=n-2;
            if(nodes&1)
                db("Ashish")
            else
                db("Ayush")
        }
    }

    return 0;
}