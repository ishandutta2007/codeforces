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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll sum[30];
int fs[MAXN];
priority_queue<int,vector<int>,greater<int> > pq[30];
map<int,int> trans;
int itrans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    vector<pii> qs;
    set<int> s;
    while(q--)
    {
        char c;
        int x;
        cin >> c >> x;
        qs.push_back(pii(c=='+',x));
        s.insert(x);
    }
    int cont=0;
    for(auto y : s)
    {
        trans[y]=cont;
        itrans[cont]=y;
        cont++;
    }

    for(int i=0;i<qs.size();i++)
        qs[i].s=trans[qs[i].s];

    int n=0;
    for(int i=0;i<qs.size();i++)
    {
        int ty=qs[i].f;
        int x=itrans[qs[i].s];
        ll v=x;
        int p=0;
        while(x!=1)
        {
            p++;
            x/=2;
        }
        if(ty)
        {
            for(int i=p;i<30;i++)
                sum[i]+=v;
            fs[qs[i].s]++;
            pq[p].push(qs[i].s);
            n++;
        }
        else
        {
            for(int i=p;i<30;i++)
                sum[i]-=v;
            fs[qs[i].s]--;
            n--;
        }
     //   db("")
    //    cout << p << ' ' << n << '\n';

        ll res=max(n-1,0);
        for(int i=1;i<30;i++)
        {
            while(!pq[i].empty() && !fs[pq[i].top()])
                pq[i].pop();
            if(!sum[i-1])
                continue;
            if(!pq[i].empty() && itrans[pq[i].top()]>sum[i-1]*2)
                res--;
        }
        db(res)
    }

    return 0;
}
/**
2
+ 1
- 1

4
+ 1
+ 3
+ 7
- 3

9
+ 2
+ 2
+ 12
- 2
- 2
+ 4
+ 1
+ 1
- 12
**/