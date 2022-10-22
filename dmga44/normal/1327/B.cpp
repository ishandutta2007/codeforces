#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

int k[MAXN],mk1[MAXN],mk2[MAXN];
vector<int> g[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> k[i];
            g[i].clear();
            for(int j=0;j<k[i];j++)
            {
                int u;
                cin >> u;
                u--;
                g[i].push_back(u);
            }
        }

        for(int i=0;i<n;i++)
        {
            sort(all(g[i]));
            mk1[i]=mk2[i]=0;
        }

        int sum=0;
        for(int i=0;i<n;i++)
        {
            int res=-1;
            for(auto y : g[i])
                if(!mk2[y] && res==-1)
                    res=y;
            if(res!=-1)
            {
                mk2[res]=1;
                mk1[i]=1;
                sum++;
            }
        }

        if(sum==n)
            db("OPTIMAL")
        else
        {
            db("IMPROVE")
            int a=-1;
            for(int i=0;i<n;i++)
                if(!mk1[i])
                    a=i+1;
            int b=-1;
            for(int i=0;i<n;i++)
                if(!mk2[i])
                    b=i+1;
            cout << a << ' ' << b << '\n';
        }
    }

    return 0;
}