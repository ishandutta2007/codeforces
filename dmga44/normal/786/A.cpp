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
typedef long double ld;
typedef pair<int,int> pii;
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
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(7e3+5)

int sol[2][MAXN];
int cant[2][MAXN];
vector<int> ks[2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<2;i++)
    {
        int k,x;
        cin >> k;
        for(int j=0;j<k;j++)
        {
            cin >> x;
            ks[i].push_back(x);
        }
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<n;j++)
        {
            sol[i][j]=-1;
            cant[i][j]=ks[i].size();
        }

    queue<pip> q;
    q.push(pip(0,pii(0,0)));
    q.push(pip(0,pii(1,0)));

    while(!q.empty())
    {
        pip x=q.front();
        q.pop();
        int pos=x.first;
        int ty=x.s.f;
        int val=x.s.s;

        sol[ty][pos]=val;
        if(!val)
        {
            for(auto y : ks[1-ty])
                if(sol[1-ty][(pos-y+n)%n]==-1)
                    q.push(pip((pos-y+n)%n,pii(1-ty,1)));
        }
        else
        {
            for(auto y : ks[1-ty])
            {
                int pp=(pos-y+n)%n;
                cant[1-ty][pp]--;
                if(!cant[1-ty][pp] && sol[1-ty][pp]==-1)
                    q.push(pip(pp,pii(1-ty,0)));
            }
        }
    }

    for(int tt=0;tt<2;tt++)
    {
        for(int i=1;i<n;i++)
        {
            if(!sol[tt][i])
                cout << "Lose ";
            if(sol[tt][i]==1)
                cout << "Win ";
            if(sol[tt][i]==-1)
                cout << "Loop ";
        }
        cout << '\n';
    }

    return 0;
}
/**
5
2 3 2
3 1 2 3

8
4 6 2 3 4
2 3 6
**/