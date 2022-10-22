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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<24)

ll solve(vector<int>& ac,ll w)
{
    vector<int> mi_ini;
    vector<int> ma_ini;
    vector<int> mi_fin;
    vector<int> ma_fin;
    int n=ac.size();
    mi_ini.push_back(0);
    ma_ini.push_back(0);
    mi_fin.push_back(ac.back());
    ma_fin.push_back(ac.back());
    for(int i=1;i<n;i++)
    {
        mi_ini.push_back(min(mi_ini.back(),ac[i]));
        ma_ini.push_back(max(ma_ini.back(),ac[i]));
    }
    for(int i=n-2;i>=0;i--)
    {
        mi_fin.push_back(min(mi_fin.back(),ac[i]));
        ma_fin.push_back(max(ma_fin.back(),ac[i]));
    }

    reverse(all(mi_fin));
    reverse(all(ma_fin));
    int res=ma_ini.back()-mi_ini.back()+1;
    for(int i=1;i<n-1;i++)
    {
//        db(i)
        int ma1=max(ma_ini[i],ma_fin[i+1]+1);
        int mi1=min(mi_ini[i],mi_fin[i+1]+1);
        ma1=max(ma1,ac[i]+1);
//        cout << ma1 << ' ' << mi1 << '\n';
        res=min(res,ma1-mi1+1);
        int ma2=max(ma_ini[i],ma_fin[i+1]-1);
        int mi2=min(mi_ini[i],mi_fin[i+1]-1);
        mi2=min(mi2,ac[i]-1);
//        cout << ma2 << ' ' << mi2 << '\n';
        res=min(res,ma2-mi2+1);
    }
//    db("xxx")
//    db(res)

    return w*res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<int> ach;
        vector<int> acv;
        ach.push_back(0);
        acv.push_back(0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int c=s[i];
            if(c=='W')
                acv.push_back(acv.back()+1);
            if(c=='S')
                acv.push_back(acv.back()-1);
            if(c=='D')
                ach.push_back(ach.back()+1);
            if(c=='A')
                ach.push_back(ach.back()-1);
        }

        int mih=0;
        int mah=0;
        int miv=0;
        int mav=0;
        for(auto v : ach)
        {
            mih=min(mih,v);
            mah=max(mah,v);
        }
        for(auto v : acv)
        {
            miv=min(miv,v);
            mav=max(mav,v);
        }
        ll dh=mah-mih+1;
        ll dv=mav-miv+1;
//        db(dv)
//        db(dh)
        db(min(solve(ach,dv),solve(acv,dh)))
//        db("")
    }

    return 0;
}