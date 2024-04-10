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
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
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
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int mk[2][MAXN];
int nex[2][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            mk[0][i]=1;
            mk[1][i]=1;
        }
        else
            mk[s[i]-'0'][i]=1;
    }

    nex[0][n]=nex[1][n]=n;
    for(int i=n-1;i>=0;i--)
    {
        nex[0][i]=nex[0][i+1];
        nex[1][i]=nex[1][i+1];
        if(!mk[0][i])
            nex[0][i]=i;
        if(!mk[1][i])
            nex[1][i]=i;
    }

    vector<int> pos[2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
            if(mk[i][j] && (!j || !mk[i][j-1]))
                pos[i].push_back(j);
        reverse(all(pos[i]));
    }
    for(int i=1;i<=n;i++)
    {
//        db(i)
        vector<int> np[2];
        for(int j=0;j<2;j++)
            for(auto y : pos[j])
                if(mk[j][y+1])
                    np[j].push_back(y+1);
//        db("xxx")
        int res=0;
        int ap=0;
        while(ap<n)
        {
            int p[2];
            p[0]=p[1]=MAXN;
            for(int j=0;j<2;j++)
            {
                while(!pos[j].empty() && pos[j].back()<ap+i-1)
                    pos[j].pop_back();
                if(nex[j][ap]>ap+i-1)
                    p[j]=ap+i-1;
                if(!pos[j].empty())
                    p[j]=min(p[j],pos[j].back());
            }

            ap=min(p[0],p[1]);
            if(ap<n)
                res++;
            ap++;
        }
//        db("xxx")

        cout << res << ' ';

        pos[0]=np[0];
        pos[1]=np[1];
    }
    cout << '\n';

    return 0;
}
/**
6
11?000
5
01?01
12
???1??????1?
**/