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
    typedef double ld;
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
    #define mod (ll)(1e9+7)
    #define eps (1e-9)
    #define oo (ll)(1e9)
    #define pi acos(-1)
    #define MAXN (ll)(2e5+5)
     
    int ask(string s)
    {
        cout << s << '\n';
        cout.flush();
        int x;
        cin >> x;
        if(!x)
            exit(0);
        return x;
    }
     
    int32_t main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
     
        int r0=ask("a");
        if(r0==1)
        {
            int r1=ask("b");
            if(r1==1)
            {
                int r2=ask("ab");
                int r3=ask("ba");
            }
            else
                int r3=ask("aa");
            return 0;
        }
/**
        if(r0==2)
        {
            int r1=ask("bb");
            if(r1==3)
                ask("aaa");
            else if(r1==2)
            {
                ask("aab");
                ask("aba");
                ask("baa");
            }
            else
            {
                ask("abb");
                ask("bba");
                ask("bab");
            }
        }
**/
        int n=r0+1;
        if(n==301)
        {
            string res(n-1,'b');
            ask(res);
        }
        vector<int> ans;
        set<int> vs;
        string base(n,'a');
        for(int i=0;i<n-1;i++)
        {
            base[i]='b';
            ans.push_back(ask(base));
            vs.insert(ans.back());
            base[i]='a';
        }
     
        if(vs.size()==1 && (*vs.begin())==n-1)
        {
            string res(n-1,'b');
            ask(res);
        }
        base[n-1]='b';
        ans.push_back(ask(base));
        vs.insert(ans.back());
        base[n-1]='a';
        if(vs.size()==1 && (*vs.begin())==1)
            ask(base);
        for(int i=0;i<n;i++)
            if(ans[i]==(*vs.begin()))
                base[i]='b';
        ask(base);
     
        return 0;
    }