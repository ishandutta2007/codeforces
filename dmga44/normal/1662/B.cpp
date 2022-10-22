#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2.5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    vector<vector<int>> fs(3,vector<int>(26));
    for(int i=0;i<3;i++)
        for(auto c : s[i])
            fs[i][c-'A']++;

    int lim=max({s[0].size(),s[1].size(),s[2].size()});
    vector<pii> ans[3];
    int cant=0;
    for(int i=0;i<26;i++)
    {
        while(cant<lim)
        {
            int pmi=0;
            if(fs[1][i]<fs[0][i])
                pmi=1;
            if(fs[2][i]<fs[pmi][i])
                pmi=2;
            if(pmi==0)
            {
                if(min({fs[1][i],fs[2][i]})==0)
                    break;
                fs[1][i]--;
                fs[2][i]--;
            }
            if(pmi==1)
            {
                if(min({fs[0][i],fs[2][i]})==0)
                    break;
                fs[0][i]--;
                fs[2][i]--;
            }
            if(pmi==2)
            {
                if(min({fs[0][i],fs[1][i]})==0)
                    break;
                fs[0][i]--;
                fs[1][i]--;
            }
            ans[pmi].push_back(pii(i,-1));
            cant++;
        }
    }

    vector<string> s2(3);
    for(int i=0;i<3;i++)
        for(int j=0;j<26;j++)
            for(int k=0;k<fs[i][j];k++)
                s2[i].push_back('A'+j);

    vector<pii> sol;
    for(int i=0;i<3;i++)
    {
        while(!s2[i].empty() && !ans[i].empty())
        {
            pii as=ans[i].back();
            ans[i].pop_back();
            as.second=s2[i].back()-'A';
            s2[i].pop_back();

            sol.push_back(as);
        }
        while(!ans[i].empty())
        {
            pii as=ans[i].back();
            ans[i].pop_back();
            as.second=0;

            sol.push_back(as);
        }
    }

    int sum=0;
    int ma=0;
    for(int i=0;i<3;i++)
    {
        sum+=s2[i].size();
        ma=max(ma,(int)s2[i].size());
    }

    int lim2=sum-ma;
    for(int i=0;i<3;i++)
    {
        if(s2[i].size()==ma)
        {
            while(s2[i].size()>lim2)
            {
                sol.push_back(pii(s2[i].back()-'A',0));
                s2[i].pop_back();
            }
        }
    }

    sum=0;
    ma=0;
    for(int i=0;i<3;i++)
    {
        sum+=s2[i].size();
        ma=max(ma,(int)s2[i].size());
    }

    if(sum&1)
    {
        for(int i=0;i<3;i++)
        {
            if(s2[i].size()==ma)
            {
                sol.push_back(pii(s2[i].back()-'A',0));
                s2[i].pop_back();
                break;
            }
        }
    }

    string last=s2[0]+s2[1]+s2[2];
    for(int i=0;i<last.size()/2;i++)
        sol.push_back(pii(last[i]-'A',last[i+last.size()/2]-'A'));

    cout << sol.size() << '\n';
    for(auto p : sol)
        cout << (char)('A'+p.first) << (char)('A'+p.second) << '\n';

    return 0;   
}