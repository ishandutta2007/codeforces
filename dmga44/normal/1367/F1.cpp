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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> s;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        map<int,int> m;
        int cont=0;
        for(auto y : s)
        {
            m[y]=cont;
            cont++;
        }

        vector<int> pos[cont];
        for(int i=0;i<n;i++)
        {
            a[i]=m[a[i]];
            pos[a[i]].push_back(i);
        }

        int res=0;
        vector<pii> ant;
        for(int i=0;i<cont;i++)
        {
            vector<pii> cant;
            int v=0;
            for(int j=0;j<pos[i].size();j++)
            {
                int p=lower_bound(all(ant),pii(pos[i][j],-1))-ant.begin();
                int add=0;
                if(p)
                {
                    p--;
                    add=ant[p].s;
                }
                res=max(res,add+((int)pos[i].size()-j));
                if(!j)
                    v=add+pos[i].size();
                if(j<pos[i].size()-1)
                    cant.push_back(pii(pos[i][j],j+1));
                else
                    cant.push_back(pii(pos[i][j],v));
            }
            ant=cant;
        }
        db(n-res)
    }
    return 0;
}
/**
9
5
4 7 2 2 9
5
3 5 8 1 7
5
1 2 2 4 5
2
0 1
3
0 1 0
4
0 1 0 0
4
0 1 0 1
4
0 1 0 2
20
16 15 1 10 0 14 0 10 3 9 2 5 4 5 17 9 10 20 0 9
**/