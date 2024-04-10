#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

vector<pii> dp[MAXN][MAXN][6];
pii dp0[MAXN][MAXN][6];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> k;
        vector<int> a(7);
        vector<int> add(8);
        vector<int> pdd(8);
        for(int i=0;i<7;i++)
            cin >> a[i];
        for(int i=1;i<8;i++)
            add[i]=pdd[i]=i*1e4;
        int sum=0;
        for(int i=0;i<7;i++)
            if(a[i])
            {
                sum++;
                add[sum]=i+1;
            }
        sum=0;
        for(int i=0;i<7;i++)
            if(a[6-i])
            {
                sum++;
                pdd[sum]=i+1;
            }
        int res=1e9;
        if(k<=sum)
            for(int i=1;i+k-1<8;i++)
                res=min(res,add[i+k-1]-add[i]+1);
        for(int i=1;i<8;i++)
            for(int j=1;j<8;j++)
                if(i+j<=k && (k-(i+j))%sum==0)
                    res=min(res,add[j]+pdd[i]+7*((k-(i+j))/sum));
        db(res)
    }

    return 0;
}
/**
3
2
0           1           0           0           0           0           0
100000000
1           0           0           0           1           0           1
1
1           0           0           0           0           0           0

1
2
1 0 0 0 1 0 1
**/