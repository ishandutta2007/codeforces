#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r) {return uniform_int_distribution<int>(l,r)(gen);}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000000;
    int n,q;
    cin >> n >> q;
    array<ll,2> mod={1000000007,rng(1000000008,2000000000)};
    const ll p=31;
    string s,t;
    cin >> s >> t;
    int m=s.size();
    s="$"+s;
    t="$"+t;
    vector<array<ll,2>> hs(m+1,{0,0});
    for(int i=1;i<=m;i++) for(int j=0;j<2;j++) hs[i][j]=(p*hs[i-1][j]+(s[i]-'a'))%mod[j];
    vector<array<ll,2>> pw(N+1,{1,1});
    for(int i=1;i<=N;i++) for(int j=0;j<2;j++) pw[i][j]=(pw[i-1][j]*p)%mod[j];
    auto h=[&](int l,int r,vector<array<ll,2>> &hh)->array<ll,2>
    {
        array<ll,2> res={0,0};
        for(int j=0;j<2;j++)
        {
            ll &now=res[j];
            now=hh[r][j];
            now=(now-pw[r-(l-1)][j]*hh[l-1][j])%mod[j];
            if(now<0) now+=mod[j];
        }
        return res;
    };
    vector<ll> two(n+1,1);
    for(int i=1;i<=n;i++) two[i]=(two[i-1]*2)%mod[0];
    vector<ll> inv(n+1,1);
    inv[1]=(mod[0]+1)/2;
    for(int i=2;i<=n;i++) inv[i]=(inv[i-1]*inv[1])%mod[0];
    auto bad=[&](int cnt,int lvl)->ll
    {
        assert(lvl<=21);
        if(two[lvl-1]>cnt) return 0;
        return (((cnt-two[lvl-1])/two[lvl])+1)%mod[0];
    };
    vector<vector<ll>> pre(n+2,vector<ll>(26,0));
    for(int i=n;i>=0;i--)
    {
        for(int j=0;j<26;j++)
        {
            pre[i][j]=(pre[i+1][j]+two[n-i]*(j==(t[i]-'a')))%mod[0];
        }
    }
    function<ll(vector<pair<char,int>>,int,int,int)> solve=[&](vector<pair<char,int>> v,int lvl,int lim,int len)->ll
    {
        if(lvl>lim) return 0;
        if(v.size()==1)
        {
            char c=v[0].first;
            int idx=v[0].second;
            if(lvl>21)
            {
                ll res=(pre[lvl][c-'a']-pre[lim+1][c-'a']+mod[0])%mod[0];
                if(n-lvl<=lim-lvl) res=(res*two[lim-lvl-(n-lvl)])%mod[0];
                else res=(res*inv[n-lvl-(lim-lvl)])%mod[0];
                return res;
            }
            else
            {
                ll res=two[lim-lvl];
                res-=(bad(idx-1,lvl)+bad(len-idx,lvl));
                return ((v[0].first==t[lvl]?(res%mod[0]):0)+solve(v,lvl+1,lim,len))%mod[0];
            }
        }
        else
        {
            ll res=0;
            for(int i=0;i<2;i++)
            {
                bool ok=1;
                for(int j=i;j<(int)v.size();j+=2) ok&=(v[j].first==t[lvl]);
                if(ok)
                {
                    vector<pair<char,int>> nxt;
                    for(int j=(i^1);j<(int)v.size();j+=2) nxt.push_back(v[j]);
                    res=(res+solve(nxt,lvl+1,lim,len))%mod[0];
                }
            }
            return res;
        }
    };
    while(q--)
    {
        int lvl;
        string a;
        cin >> lvl >> a;
        int sz=a.size();
        a="$"+a;
        vector<array<ll,2>> ha(sz+1,{0,0});
        for(int i=1;i<=sz;i++) for(int j=0;j<2;j++) ha[i][j]=(p*ha[i-1][j]+(a[i]-'a'))%mod[j];
        ll res=0;
        for(int c=1;c<=min(m+1,sz);c++)
        {
            bool ok=1;
            if(c>1) ok&=(h(m-(c-1)+1,m,hs)==h(1,c-1,ha));
            for(int d=c+1;d+m-1<=sz;d+=(m+1)) ok&=(h(1,m,hs)==h(d,d+m-1,ha));
            int k=((sz-c)/(m+1));
            int d=((m+1)*k+c)+1;
            int len=sz-d+1;
            if(d<=sz) ok&=(h(1,len,hs)==h(d,sz,ha));
            if(ok)
            {
                vector<pair<char,int>> v;
                int id=1;
                for(int i=c;i<=sz;i+=(m+1)) v.push_back({a[i],id++});
                if(!v.empty()&&(lvl>20||(int)v.size()<=two[lvl]-1)) res=(res+solve(v,1,lvl,v.size()))%mod[0];
            }
        }
        if(sz<=m)
        {
            ll c=0;
            for(int i=1;i+sz-1<=m;i++) c+=(h(i,i+sz-1,hs)==h(1,sz,ha));
            res=(res+((c*two[lvl])%mod[0]))%mod[0];
        }
        cout << res << "\n";
    }
    return 0;
}