#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

vector<string> ss[25];

struct aho_corasick{
    vector<ll> f,ok;
    vector<vector<ll>> g;
    int k;
    int n=0;

    #define ALPHA 9
    int cv(char c)
    {
        return c-'1';
    }

    aho_corasick(vector<string> vs) : k(vs.size())
    {
        for(int i=0;i<k;i++)
            n+=vs[i].size();

        for(int i=0;i<=n;i++)
        {
            f.push_back(0);
            ok.push_back(0);
            g.push_back(vector<ll>(ALPHA,-1));
        }

        int cont=1;
        for(int i=0;i<k;i++)
        {
            int pos=0;
            for(int j=0;j<vs[i].size();j++)
            {
                int v=cv(vs[i][j]);
                if(g[pos][v]==-1)
                {
                    g[pos][v]=cont;
                    cont++;
                }
                pos=g[pos][v];
            }

            ok[pos]=1;
        }

        for(int i=0;i<ALPHA;i++)
            if(g[0][i]==-1)
                g[0][i]=0;

        queue<int> q;
        for(int i=0;i<ALPHA;i++)
            if(g[0][i])
            {
                f[g[0][i]]=0;
                q.push(g[0][i]);
            }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(int i=0;i<ALPHA;i++)
                if(g[u][i]!=-1)
                {
                    int fail=f[u];
                    while(g[fail][i]==-1)
                        fail=f[fail];

                    fail=g[fail][i];
                    f[g[u][i]]=fail;

                    if(!ok[g[u][i]])
                        ok[g[u][i]]=ok[fail];

                    q.push(g[u][i]);
                }
        }
        n=cont;
    }

    int next(int current,int ch)
    {
        while(g[current][ch]==-1)
            current=f[current];
        return g[current][ch];
    }
};

int dp[MAXN][5*MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<psi> q;
    q.push(psi("",0));
    while(!q.empty())
    {
        psi x=q.front();
        q.pop();

        string s=x.f;
        int sum=x.s;
        int n=s.size();
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            int ss=0;
            for(int j=i;j<n;j++)
            {
                ss+=s[j]-'0';
                if(ss!=sum && (sum%ss)==0)
                    ok=0;
            }
        }

        if(ok)
            ss[sum].push_back(s);
        for(int i=1;i<10;i++)
        {
            if(sum+i>20)
                break;
            string snew=s;
            snew.push_back('0'+i);
            q.push(psi(snew,sum+i));
        }
    }

//    for(int i=0;i<=20;i++)
//    {
//        db("")
//        db(i)
//        db(ss[i].size())
//        int ma=0,sum=0;
//        for(auto s : ss[i])
//        {
//            ma=max(ma,(int)s.size());
//            sum+=s.size();
//        }
//        db(ma)
//        db(sum)
//    }

    string s;
    cin >> s;
    int x;
    cin >> x;
    aho_corasick ac(ss[x]);
    int tam=ac.n;
    int n=s.size();
    for(int i=0;i<=n;i++)
        for(int j=0;j<tam;j++)
            dp[i][j]=oo;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<tam;j++)
        {
            int ns=ac.next(j,s[i]-'1');
            dp[i+1][ns]=min(dp[i+1][ns],dp[i][j]);
        }

        for(int j=0;j<tam;j++)
        {
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            if(ac.ok[j])
                dp[i+1][j]=oo;
        }
    }

    int res=oo;
    for(int i=0;i<tam;i++)
        res=min(res,dp[n][i]);
    db(res)

    return 0;
}