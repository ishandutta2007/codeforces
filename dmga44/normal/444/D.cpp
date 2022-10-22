#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

map<string,vector<int>> mp;

bool is_substring(string s1,string s2)
{
    if(s1.size()<s2.size())
        return 0;
    for(int i=0;i+s2.size()<=s1.size();i++)
    {
        int ok=1;
        for(int j=0;j<s2.size();j++)
            ok&=(s1[i+j]==s2[j]);
        if(ok)
            return 1;
    }
    return 0;
}

int solve(vector<int>& v1,vector<int>& v2,int sz1,int sz2)
{
    if(v1.size()>v2.size())
        return solve(v2,v1,sz2,sz1);
    if(v1.empty())
        return -1;
    int ans=1e6;
    for(auto x : v1)
    {
        int pos=lower_bound(all(v2),x)-v2.begin();
        if(pos<v2.size())
            ans=min(ans,v2[pos]+sz2-x);
        if(pos)
            ans=min(ans,sz1+x-v2[pos-1]);
    }
    return ans;
}

int aux(string s1,string s2)
{
    if(is_substring(s1,s2))
    {
        if(mp[s1].size())
            return s1.size();
        else
            return -1;
    }
    else if(is_substring(s2,s1))
    {
        if(mp[s2].size())
            return s2.size();
        else
            return -1;
    }
    return solve(mp[s1],mp[s2],s1.size(),s2.size());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n=s.size();
    for(int j=1;j<=4;j++)
        for(int i=0;i+j<=n;i++)
        {
            string x="";
            for(int k=0;k<j;k++)
                x.push_back(s[i+k]);
            mp[x].push_back(i);
        }

    int q;
    cin >> q;
    map<pss,int> ca;
    for(int i=0;i<q;i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        if(s1>s2)
            swap(s1,s2);
        if(!ca[pss(s1,s2)])
            ca[pss(s1,s2)]=aux(s1,s2);
        db(ca[pss(s1,s2)])
    }

    return 0;
}