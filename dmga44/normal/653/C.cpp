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
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n+2);
    v[0]=2e5;
    v[n+1]=2e5;
    if((n+1)&1)
        v[n+1]=0;
    vector<int> cant(n+2);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> v[i];
        if(i&1)
        {
            if(v[i]>=v[i-1])
            {
                sum++;
                cant[i-1]++;
                cant[i]++;
            }
        }
        else
        {
            if(v[i]<=v[i-1])
            {
                sum++;
                cant[i-1]++;
                cant[i]++;
            }
        }
    }

    if(sum>4)
    {
        db(0)
        return 0;
    }
    vector<int> p1;
    vector<int> p2;
    for(int i=1;i<=n;i++)
        if(sum==cant[i])
            p1.push_back(i);
    for(int i=1;i<=n;i++)
        if(cant[i] && cant[i]!=sum)
            p2.push_back(i);
    ll res=0;
    for(auto y : p1)
    {
//        db(y)
        for(int i=1;i<=n;i++)
        {
            if(i==y)
                continue;
            if(cant[i]==sum && i<y)
                continue;
            swap(v[i],v[y]);

            bool ok=1;
            if(i&1)
                ok&=(v[i]<(min(v[i-1],v[i+1])));
            else
                ok&=(v[i]>(max(v[i-1],v[i+1])));
            if(y&1)
                ok&=(v[y]<(min(v[y-1],v[y+1])));
            else
                ok&=(v[y]>(max(v[y-1],v[y+1])));
            res+=ok;

            swap(v[i],v[y]);
        }
    }
//    db("xxx")

    for(auto y1 : p2)
    {
//        db(y1)
        for(auto y2 : p2)
        {
            if(y1>=y2)
                continue;
            swap(v[y1],v[y2]);

            int sum=0;
            for(int i=1;i<=n;i++)
            {
                if(i&1)
                {
                    if(v[i]>=v[i-1])
                    {
                        sum++;
                        cant[i-1]++;
                        cant[i]++;
                    }
                }
                else
                {
                    if(v[i]<=v[i-1])
                    {
                        sum++;
                        cant[i-1]++;
                        cant[i]++;
                    }
                }
            }
            res+=(sum==0);

            swap(v[y1],v[y2]);
        }
    }

    db(res)
    return 0;
}
/**
5
2 8 4 7 7
4
200 150 100 50
10
3 2 1 4 1 4 1 4 1 4
9
1 2 3 4 5 6 7 8 9
**/