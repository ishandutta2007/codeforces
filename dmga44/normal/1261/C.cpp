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
typedef unsigned long long ull;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

string s[MAXN];
vector<bool> mk[MAXN];
vector<int> lvl[MAXN];
vector<int> kk[MAXN];
int n,m;
string ss[MAXN];

bool ok(int x)
{
//    db(x)
    queue<pii> q;
    for(int i=0;i<n;i++)
    {
        ss[i]=s[i];
        kk[i].resize(m);
        for(int j=0;j<m;j++)
        {
            if(s[i][j]!='X')
                continue;
            ss[i][j]='.';
            mk[i][j]=0;
            kk[i][j]=0;
            if(lvl[i][j]>=x)
            {
                q.push(pii(i,j));
                mk[i][j]=1;
                kk[i][j]=x;
            }
        }
    }

    while(!q.empty())
    {
        pii u=q.front();
        q.pop();

        int x=u.f;
        int y=u.s;
//        cout << x << ' ' << y << '\n';
        ss[x][y]='X';
        if(!kk[x][y])
            continue;
        for(int dx=-1;dx<2;dx++)
            for(int dy=-1;dy<2;dy++)
            {
                if(dx+x<0 || dx+x>=n)
                    return 0;
                if(dy+y<0 || dy+y>=m)
                    return 0;
                int i=dx+x;
                int j=dy+y;
                if(mk[i][j])
                    continue;
                if(s[i][j]=='.')
                    return 0;
                mk[i][j]=1;
                kk[i][j]=kk[x][y]-1;
                q.push(pii(i,j));
            }
    }
//    db("xxx")
    bool res=1;
    for(int i=0;i<n;i++)
    {
        res&=(s[i]==ss[i]);
//        db(ss[i])
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        mk[i].resize(m);
        lvl[i].resize(m);
    }

    queue<pii> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(s[i][j]!='X')
                continue;
            if(!i)
            {
                q.push(pii(i,j));
                mk[i][j]=1;
                continue;
            }
            if(i==n-1)
            {
                q.push(pii(i,j));
                mk[i][j]=1;
                continue;
            }
            if(!j)
            {
                q.push(pii(i,j));
                mk[i][j]=1;
                continue;
            }
            if(j==m-1)
            {
                q.push(pii(i,j));
                mk[i][j]=1;
                continue;
            }
            bool kk=0;
            for(int dx=-1;dx<2;dx++)
                for(int dy=-1;dy<2;dy++)
                    kk|=(s[i+dx][j+dy]=='.');
            if(kk)
            {
                mk[i][j]=1;
                q.push(pii(i,j));
            }
        }

    int ma=0;
    while(!q.empty())
    {
        pii u=q.front();
        q.pop();

        int x=u.f;
        int y=u.s;
//        cout << x << ' ' << y << ' ' << lvl[x][y] << '\n';
        for(int dx=-1;dx<2;dx++)
            for(int dy=-1;dy<2;dy++)
            {
                if(dx+x<0 || dx+x>=n)
                    continue;
                if(dy+y<0 || dy+y>=m)
                    continue;
                int i=dx+x;
                int j=dy+y;
                if(mk[i][j] || s[i][j]=='.')
                    continue;
                mk[i][j]=1;
                lvl[i][j]=lvl[x][y]+1;
                ma=max(ma,lvl[i][j]);
                q.push(pii(i,j));
            }
    }

    int res=0;
    for(int po=(1<<19);po;po>>=1)
        if(res+po<=ma && ok(res+po))
            res+=po;

    db(res)
    for(int i=0;i<n;i++,cout << '\n')
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.' || lvl[i][j]<res)
                cout << '.';
            else
                cout << 'X';
        }

    return 0;
}