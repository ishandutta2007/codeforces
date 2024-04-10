#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(2e9+99);
const ll mod2=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll h[MAXN],po[MAXN];
ll h2[MAXN],po2[MAXN];

pii hs(int i,int j)
{
    ll h11=h[j+1];
    ll h21=(h[i]*po[j-i+1])%mod;
    ll h12=h2[j+1];
    ll h22=(h2[i]*po2[j-i+1])%mod2;
    return pii((h11-h21+mod)%mod,(h12-h22+mod2)%mod2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    po[0]=po2[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        po[i]=(po[i-1]*331ll)%mod;
        po2[i]=(po2[i-1]*997ll)%mod2;
    }

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n);
    for(int i=1;i<n;i++)
    {
        if(s[i-1]=='1')
            pre[i]=pre[i-1]+1;
        else    
            pre[i]=0;
    }
    int q;
    cin >> q;
    vector<pip> qs;
    set<int> to_q[n];
    for(int i=0;i<q;i++)
    {
        int l,r,len;
        cin >> l >> r >> len;
        l--,r--;
        // if(i==35)
        // {
        //     cout << l << ' ' << r << ' ' << len << ' ' << s.substr(l,len) << ' ' << s.substr(r,len) << '\n';
        // }
        to_q[l+len-1].insert(l);
        to_q[r+len-1].insert(r);
        qs.push_back(pip(len,pii(l,r)));
    }

    map<pii,pii> mem;
    vector<pii> act;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1' && act.size() && act.back().second=='1')
            act.pop_back();
        else
        {
            act.push_back(pii(i,s[i]));
            h[act.size()]=(h[act.size()-1]*331ll+s[i])%mod;
            h2[act.size()]=(h2[act.size()-1]*997ll+s[i])%mod2;
        }
        // cout << "el string es:";
        // for(auto p : act)
        //     cout << (char)(p.second);
        // cout << '\n';
        // cout << act.size() << '\n';
        for(auto l : to_q[i])
        {
            int pos=lower_bound(all(act),pii(l,0))-act.begin();
            ll add=0,mul1=1,mul2=1;
            if((pre[l]&1) && s[l]=='1')
            {
                if(pos<act.size() && act[pos].second=='1')
                    pos++;
                else
                {
                    add='1';
                    mul1=331;
                    mul2=997ll;
                }
            }
            pii x=hs(pos,(int)(act.size())-1);
            // x.first=(x.first*mul1+add)%mod;
            // x.second=(x.second*mul2+add)%mod2;
            x.first=(x.first+add*po[act.size()-pos])%mod;
            x.second=(x.second+add*po2[act.size()-pos])%mod2;
            // if((l==16 && i==17) || (l==98 && i==99))
            // {
            //     cout << l << ' ' << i << '\n';
            //     cout << add << ' ' << mul1 << ' '<< mul2 << '\n';
            //     cout << pos<< ' ' << (int)(act.size())-1 << '\n';
            //     cout << x.first << ' ' << x.second << '\n';
            //     cout <<'\n';
            // }
            mem[pii(l,i)]=x;
        }
    }
    
    for(int i=0;i<q;i++)
    {
        int len=qs[i].first;
        int l=qs[i].second.first;
        int r=qs[i].second.second;
        if(mem[pii(l,l+len-1)]==mem[pii(r,r+len-1)])
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;   
}