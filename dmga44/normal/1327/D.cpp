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
#define MAXN 200005

int p[MAXN],c[MAXN],mk[MAXN];
vector<int> cycle;

void dfs(int u)
{
    mk[u]=1;
    cycle.push_back(u);

    if(!mk[p[u]])
        dfs(p[u]);
}

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
            mk[i]=0;
            cin >> p[i];
            p[i]--;
        }
        for(int i=0;i<n;i++)
            cin >> c[i];

        int res=n;
        for(int i=0;i<n;i++)
            if(!mk[i])
            {
                dfs(i);
                int sz=cycle.size();
                for(int i=1;i<=sz;i++)
                    if(sz%i==0)
                    {
                        bool ok[i];
                        for(int j=0;j<i;j++)
                            ok[j]=1;
                        for(int j=0;j<sz;j++)
                            if(c[cycle[j]]!=c[cycle[j%i]])
                                ok[j%i]=0;
                        for(int j=0;j<i;j++)
                            if(ok[j])
                                res=min(res,i);
                    }

                cycle.clear();
            }
        db(res)
    }

    return 0;
}
/**
1
5
2 3 4 5 1
1 2 3 4 5
**/