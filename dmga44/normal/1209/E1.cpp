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
typedef long double ld;
typedef pair<int,int> pii;
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
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

int a[12][MAXN];
int dp[(1<<12)];
int sum[(1<<12)];
int mk[(1<<12)];
vector<int> ns[(1<<12)];
int n,m;

int solve()
{
    for(int i=0;i<(1<<n);i++)
    {
        mk[i]=0;
        dp[i]=0;
        ns[i].clear();
    }

    for(int i=1;i<(1<<n);i++)
    {
        if(mk[i])
            continue;
        vector<int> bs;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                bs.push_back(j);
        for(int j=0;j<n;j++)
        {
            int x=0;
            for(auto b : bs)
                x+=(1<<((b+j)%n));
            if(!mk[x])
            {
                mk[x]=1;
                ns[i].push_back(x);
            }
        }
    }

//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<m;j++)
//            cout << a[i][j] << ' ';

    for(int i=0;i<m;i++)
    {
        for(int j=1;j<(1<<n);j++)
            sum[j]=sum[j-(j&-j)]+a[(int)log2(j&-j)][i];
//        db("")
//        db(i)
        int dp_prev[(1<<n)];
        for(int k=0;k<(1<<n);k++)
            dp_prev[k]=dp[k];
        for(int j=1;j<(1<<n);j++)
        {
            if(!ns[j].size())
                continue;
            int v=0;
            for(auto x : ns[j])
                v=max(sum[x],v);

//            cout << j << ' ' << v << '\n';
            for(auto mask : ns[j])
                for(int k=(1<<n)-1-mask;1;k=(k-1)&((1<<n)-1-mask))
                {
                    dp[k|mask]=max(dp[k|mask],dp_prev[k]+v);
                    if(!k)
                        break;
                }
        }
    }

    return dp[(1<<n)-1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    int t;
//    cin >> t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
//        cin >> n >> m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        int x=min(n,m);
        vector<pii> mp;
        for(int i=0;i<m;i++)
        {
            int ma=0;
            for(int j=0;j<n;j++)
                ma=max(ma,a[j][i]);
            mp.push_back(pii(ma,i));
        }

        sort(allr(mp));

        vector<vector<int> > aa(n,vector<int>(x));
        for(int i=0;i<x;i++)
            for(int j=0;j<n;j++)
                aa[j][i]=a[j][mp[i].s];

//        for(int i=0;i<n;i++,cout << '\n')
//            for(int j=0;j<x;j++)
//                cout << aa[i][j] << ' ';

        for(int i=0;i<x;i++)
            for(int j=0;j<n;j++)
                a[j][i]=aa[j][i];
        m=x;

//                cin >> a[i][j];
//        printf("\n");
//        printf("%d %d\n",n,m);
//        for(int i=0;i<n;i++,printf("\n"))
//            for(int j=0;j<m;j++)
//                printf("%d ",a[i][j]);
        printf("%d\n",solve());
    }

    return 0;
}
/**
1
3 2
2 1
1 1
1 1

1
2 3
2 5 7
4 2 4

3 6
4 1 5 2 10 4
8 6 6 4 9 10
5 4 9 5 8 7
3 3
9 9 9
1 1 1
1 1 1
**/