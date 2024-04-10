#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
#define MAXN (ll)(2e3+5)

int tx[MAXN][MAXN][3];
bool mk[MAXN];
bool mkx[MAXN][MAXN];
int szx[MAXN][4];
ll abi[MAXN][MAXN];
ll res[MAXN];

void update(int x,int y,int v)
{
    int yy=y;
    while(x<MAXN)
    {
        y=yy;
        while(y<MAXN)
        {
            abi[x][y]+=v;
            y+=(y&-y);
        }
        x+=(x&-x);
    }
}

ll query(int x,int y)
{
    ll res=0;
    int yy=y;
    while(x)
    {
        y=yy;
        while(y)
        {
            res+=abi[x][y];
            y-=(y&-y);
        }
        x-=(x&-x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
//    cin >> n >> m >> k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        int len;
//        cin >> len;
        scanf("%d",&len);
        tx[i][0][0]=len;
        for(int j=0;j<len;j++)
        {
            int x,y,w;
//            cin >> x >> y >> w;
            scanf("%d%d%d",&x,&y,&w);
            tx[i][j+1][0]=x;
            tx[i][j+1][1]=y;
            tx[i][j+1][2]=w;
        }
    }

    int q,cont=0;
//    cin >> q;
    scanf("%d",&q);
for(int i=0;i<k;i++) mk[i]=1;
    for(int i=0;i<q;i++)
    {
//        string s;
//        cin >> s;
        char s[10];
        scanf("%s",&s);
        if(s[0]=='S')
        {
            int x;
//            cin >> x;
            scanf("%d",&x);
            x--;
            mk[x]^=1;
        }
        else
        {
            int x0,y0;
            int x1,y1;
//            cin >> x0 >> y0 >> x1 >> y1;
            scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
            for(int i=0;i<k;i++)
                mkx[cont][i]=mk[i];
            szx[cont][0]=x0;
            szx[cont][1]=y0;
            szx[cont][2]=x1;
            szx[cont][3]=y1;
            cont++;
        }
    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<tx[i][0][0];j++)
            update(tx[i][j+1][0],tx[i][j+1][1],tx[i][j+1][2]);
        for(int j=0;j<cont;j++)
            if(mkx[j][i])
            {
                res[j]+=query(szx[j][2],szx[j][3]);
                res[j]+=query(szx[j][0]-1,szx[j][1]-1);
                res[j]-=query(szx[j][0]-1,szx[j][3]);
                res[j]-=query(szx[j][2],szx[j][1]-1);
            }
        for(int j=0;j<tx[i][0][0];j++)
            update(tx[i][j+1][0],tx[i][j+1][1],-tx[i][j+1][2]);
    }

    for(int i=0;i<cont;i++)
        cout << res[i] << '\n';

    return 0;
}