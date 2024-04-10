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
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int fs[MAXN];
int n;
pii waiting[MAXN];

bool solve(int x)
{
//    db(x)
    priority_queue<pii,vector<pii>,less<pii>> pq;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        waiting[i]=pii(0,0);
        sum+=fs[i];
        if(fs[i])
            pq.push(pii(fs[i],i));
    }

    for(int i=0;i<n;i++)
    {
        if(waiting[i].f)
            pq.push(waiting[i]);
        if(pq.empty())
            return 0;
        pii t=pq.top();
        pq.pop();
        t.first--;
        waiting[i+x+1]=t;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            x--;
            fs[x]++;
        }

        int res=0;
        for(int po=(1<<17);po;po>>=1)
            if(solve(res+po))
                res+=po;

        db(res)

        for(int i=0;i<n;i++)
            fs[i]=0;
    }

    return 0;
}
/**
4
7
1 7 1 6 4 4 6
8
1 1 4 6 4 6 4 7
3
3 3 3
6
2 5 2 3 1 4

1
7
1 7 1 6 4 4 6
**/