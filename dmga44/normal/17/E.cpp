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
#define mod (ll)(51123987)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e6+5)

//vector<int> g[MAXN];
//struct info{
//    pii ss;
//    pii p1;
//    pii p2;
//    bool operator<(info b) { return (*this).ss<b.ss; }
//};
//vector<info> cc;
//
//struct dpv{
//    pii p;
//    int len;
//    int com;
//    bool operator<(dpv b)
//    {
//        dpv a=(*this);
//        if(a.p.s==-1 && a.p.s==-1)
//            return a.len<b.len;
//        if(a.p.s!=-1 && b.p.s!=-1)
//            return pii(a.com,a.len)<pii(b.com,b.len);
//        return a.p.s>b.p.s;
//    }
//};
//dpv dp[MAXN];
//bool mk[MAXN];
//
//dpv merge(dpv a,dpv b)
//{
//    dpv res;
//    res.p=pii(a.p.f,b.p.f);
//    res.com=-1;
//    res.len=a.len+b.len-1;
//    return res;
//}
//
//info mix(dpv a,dpv b)
//{
//    info res;
//    res.p1=a.p;
//    res.p2=b.p;
//    res.ss.f=a.com+b.com-1;
//    res.ss.s=a.len+b.len-2;
//    return res;
//}
//
//void dfs(int u)
//{
//    db("")
//    db(u)
//    mk[u]=1;
//    dp[u].p=pii(u,-1);
//    dp[u].com=0;
//    dp[u].len=1;
//    vector<dpv> sons;
//    for(auto v : g[u])
//    {
//        if(mk[v])
//            continue;
//        dfs(v);
//        sons.push_back(dp[v]);
//    }
//    db(u)
//    db("tamano")
//    db(sons.size())
//    if(sons.size())
//    {
//        for(auto y : sons)
//        {
//            db("yy")
//            cout << y.len << ' ' << y.com << '\n';
//            cout << y.p.f << ' ' << y.p.s << '\n';
//        }
//        sort(all(sons));
//        vector<dpv> nv;
//        int lim=0;
//        for(int i=0;i<sons.size();i++)
//        {
//            cout << "i " << i << '\n';
//            auto y=sons[i];
//            if(y.p.s!=-1)
//                nv.push_back(y);
//            else
//            {
////                db("xxx")
//                if(!i || sons[i-1].p.s!=-1)
//                    lim=i+1;
////                db("xxx")
//                if(i>=lim && !((i-lim)&1))
//                    nv.push_back(merge(sons[i-1],sons[i]));
//                else if(i==sons.size()-1)
//                    nv.push_back(sons.back());
//            }
//        }
////        db("xxx")
//        for(int i=0;i<nv.size();i++)
//        {
//            if(nv[i].p.s!=-1)
//            {
//                nv[i].len+=2;
//                nv[i].com+=1;
//            }
//            else
//                nv[i].len++;
//        }
//
//        sort(all(nv));
//
//        dp[u]=nv[0];
//
//        if(nv.size()<2)
//            return ;
//        if(nv[0].p.s!=-1 && nv[1].p.s!=-1)
//            cc.push_back(mix(nv[0],nv[1]));
//    }
//    cout << "terminar: " << u << '\n';
//}

vector<int> manacher(const string &s)
{
	int n = 2 * s.length();
	vector<int> rad(n);

	for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
	{
		for (; i >= j && i + j + 1 < n
			&& s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);
		rad[i] = j;
		for (k = 1; i >= k &&
			rad[i] >= k && rad[i - k] != rad[i] - k; ++k)
			rad[i + k] = min(rad[i - k], rad[i] - k);
	}

	return rad;
}

ll a[MAXN],b[MAXN];
ll ac[MAXN];
ll n;
char c[MAXN];

int solve(string &s)
{
    vector<int> man=manacher(s);
    for(int i=0;i<n;i++)
    {
        int v=man[2*i]/2;
        a[i-v]++;
        a[i+1]--;
        ac[i-v]++;
        ac[i+1]-=2;
        ac[i+v+2]++;
    }
    for(int i=1;i<n;i++)
    {
        int v=man[2*i-1]/2;
        a[i-v]++;
        a[i]--;
        ac[i-v]++;
        ac[i]--;
        ac[i+1]--;
        ac[i+v+1]++;
    }

    for(int i=0;i<n;i++)
    {
        if(i)
        {
            a[i]=(a[i-1]+a[i])%mod;
            ac[i]=(ac[i-1]+ac[i])%mod;
            b[i]=(b[i-1]+ac[i])%mod;
        }
        else
            b[i]=ac[i];
    }


//    for(int i=0;i<n;i++)
//        cout << a[i] << ' ' << b[i] << '\n';
    ll res=0;
    for(int i=0;i<n;i++)
    {
        res+=(a[i]*(b[i]-a[i]+mod))%mod;
        res+=((a[i]*(a[i]-1))/2)%mod;
        res%=mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    scanf("%lld",&n);
    scanf("%s",c);
    string s;
    s.resize(n);
    for(int i=0;i<n;i++)
        s[i]=c[i];

    printf("%d\n",solve(s));

//    int n,u,v;
//    cin >> n;
//    for(int i=0;i<n-1;i++)
//    {
//        cin >> u >> v;
//        u--,v--;
//        g[u].push_back(v);
//        g[v].push_back(u);
//    }
//
//    for(int i=0;i<n;i++)
//    {
//        if(g[i].size()<2)
//            continue;
//        dfs(i);
//        sort(all(cc));
//        db(cc.size())
//        info res=cc.back();
//        cout << res.p1.f+1 << ' ' << res.p2.f+1 << '\n';
//        cout << res.p1.s+1 << ' ' << res.p2.s+1 << '\n';
//        break;
//    }

    return 0;
}
/**
4
babb
5
aaaaa
**/