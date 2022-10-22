#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)
#define F (ll)(125)

int trans[F][F];
int id[MAXN];
int last[MAXN][F];
bool mk[F];

int index(vector<int> per)
{
    int k=per.size();
    int res=0;
    int f=1;
    for(int i=2;i<=k;i++)
        f*=i;
    set<int> s;
    for(int i=0;i<k;i++)
        s.insert(i);
    for(int i=0;i<k;i++)
    {
        f/=(k-i);
        auto it=s.find(per[i]);
        int p=0;
        while(it!=s.begin())
        {
            p++;
            it--;
        }
        res+=p*f;
        s.erase(per[i]);
    }
    return res;
}

vector<int> per(int index,int k)
{
    vector<int> res(k);
    int f=1;
    for(int i=2;i<=k;i++)
        f*=i;
    set<int> s;
    for(int i=0;i<k;i++)
        s.insert(i);
    for(int i=0;i<k;i++)
    {
        f/=(k-i);
        int p=index/f;
        index%=f;
        auto it=s.begin();
        for(int j=0;j<p;j++)
            it++;
        res[i]=(*it);
        s.erase(res[i]);
    }
    return res;
}

void process(int k)
{
    int f=1;
    for(int i=2;i<=k;i++)
        f*=i;
    for(int i=0;i<f;i++)
        for(int j=0;j<f;j++)
        {
            vector<int> p1=per(i,k);
            vector<int> p2=per(j,k);
            vector<int> res(k);
            for(int u=0;u<k;u++)
                res[u]=p1[p2[u]];

            trans[i][j]=index(res);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    process(k);
    int f=1;
    for(int i=2;i<=k;i++)
        f*=i;
    for(int i=0;i<n;i++)
    {
        vector<int> per(k);
        for(int j=0;j<k;j++)
        {
            cin >> per[j];
            per[j]--;
        }
        id[i]=index(per);
    }

    for(int i=0;i<f;i++)
        last[n][i]=n;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<f;j++)
            last[i][j]=last[i+1][j];
        last[i][id[i]]=i;
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
        vector<pii> vp;
        for(int j=0;j<f;j++)
            vp.push_back(pii(last[i][j],j));

        sort(all(vp));

        for(int j=0;j<f;j++)
            mk[j]=0;

        int cant=1;
        int pant=i;
        mk[0]=1;
        vector<int> edges;
        for(auto y : vp)
        {
            int pos=y.f;
            int p=y.s;
            if(mk[p])
                continue;

            edges.push_back(p);
            queue<int> q;
            for(int j=0;j<f;j++)
                if(mk[j])
                    q.push(j);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();

                for(auto y : edges)
                {
                    int v=trans[u][y];
                    if(mk[v])
                        continue;
                    mk[v]=1;
                    q.push(v);
                }
            }

            int c2=0;
            for(int j=0;j<f;j++)
                c2+=mk[j];
            res+=cant*(pos-pant);
            pant=pos;
            cant=c2;
        }
        res+=cant*(n-pant);
    }
    db(res)

    return 0;
}
/**
3 3
2 1 3
3 1 2
1 3 2
2 4
4 1 3 2
4 3 1 2
**/