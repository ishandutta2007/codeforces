#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define dbg(x) cout << #x << " : " << (x) << '\n';
#define mn(a, b) (a < b ? a : b)
#define mx(a, b) (a > b ? a : b)
#define all(v)  (v).begin(), (v).end()
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 32

int cant[MAXN],cant2[MAXN];
map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    m[1]=0;
    int p=1;
    for(int i=1;i<MAXN;i++)
    {
        p*=2;
        m[p]=i;
    }

    int n,q,x;
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        cant[m[x]]++;
    }

    while(q--)
    {
        cin >> x;
        for(int i=0;i<MAXN;i++)
            cant2[i]=cant[i];
        bool ok=1;
        for(int i=MAXN-1;i>=0 && ok;i--)
            if(x&(1<<i))
            {
                int y=(1<<i);
                for(int j=MAXN-1;j>=0;j--)
                    if(y && cant2[j] && j<=i)
                    {
                        int xxx=min(cant2[j],(y/(1<<j)));
                        cant2[j]-=xxx;
                        y-=(xxx*(1<<j));
                    }
                if(y)
                    ok=0;
            }
        if(!ok)
            db(-1)
        else
        {
            int res=n;
            for(int i=0;i<MAXN;i++)
                res-=cant2[i];
            db(res)
        }
    }

    return 0;
}