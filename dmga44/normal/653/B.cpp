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

    int n,q;
    cin >> n >> q;
    vector<pair<string,string>> vq;
    for(int i=0;i<q;i++)
    {
        string a,b;
        cin >> a >> b;
        vq.push_back(make_pair(a,b));
    }

    vector<string> vs;
    vs.push_back("");
    for(int i=0;i<n;i++)
    {
        vector<string> nn;
        for(auto y : vs)
            for(int j=0;j<6;j++)
            {
                string x=y;
                x.push_back(j+'a');
                nn.push_back(x);
            }
        vs=nn;
    }

    int res=0;
//    vs.clear();
//    vs.push_back("abb");
//    vs.push_back("cab");
//    vs.push_back("cca");
//    vs.push_back("eea");
    for(auto y : vs)
    {
        map<string,bool> mk;
        queue<string> q;
        q.push(y);
        mk[y]=1;
        while(!q.empty())
        {
            string u=q.front();
            q.pop();

//            db("")
//            db(u)
            if(u.size()<2)
                continue;
            for(auto p : vq)
            {
                string a=p.f;
                string b=p.s;
//                cout << a << ' ' << b << '\n';
                if(u[0]==a[0] && u[1]==a[1])
                {
                    string nn;
                    nn.resize(u.size()-1);
                    nn[0]=b[0];
                    for(int i=2;i<u.size();i++)
                        nn[i-1]=u[i];
//                    db(nn)
                    if(!mk[nn])
                    {
                        mk[nn]=1;
                        q.push(nn);
                    }
                }
            }
        }

        res+=mk["a"];
    }
    db(res)

    return 0;
}
/**
6 2
bb a
ba a

3 5
ab a
cc c
ca a
ee c
ff d
**/