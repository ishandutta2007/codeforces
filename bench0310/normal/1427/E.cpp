#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    const int d=40;
    const ll lim=(ll(1)<<d);
    vector<ll> basis(d,0);
    vector<ll> v;
    int sz=0;
    vector<array<ll,3>> res;
    auto op=[&](ll a,ll b,char c){res.push_back({a,b,(c=='+')});};
    auto add=[&](ll m,bool t=1)->bool
    {
        for(int i=0;i<d;i++)
        {
            if((m&(ll(1)<<i))==0) continue;
            if(basis[i]!=0)
            {
                if(t) op(m,basis[i],'^');
                m^=basis[i];
            }
            else
            {
                if(t)
                {
                    basis[i]=m;
                    v.push_back(m);
                    sz++;
                }
                return 0;
            }
        }
        return 1;
    };
    add(x);
    mt19937_64 gen(135);
    auto rng=[&](ll l,ll r)->ll{return uniform_int_distribution<ll>(l,r)(gen);};
    auto go=[&](ll m,bool t=0)->ll
    {
        ll r=0;
        for(int i=0;i<d;i++)
        {
            if(m&(ll(1)<<i))
            {
                if(r>0&&basis[i]>0&&t) op(r,basis[i],'^');
                r^=basis[i];
            }
        }
        return r;
    };
    while(add(1,0)==0)
    {
        while(1)
        {
            ll l=rng(1,lim-1);
            ll r=rng(1,lim-1);
            ll a=go(l);
            ll b=go(r);
            if(a+b<lim&&add(a+b,0)==0)
            {
                go(l,1);
                go(r,1);
                op(a,b,'+');
                add(a+b);
                break;
            }
        }
    }
    ll m=basis[0];
    for(int i=1;i<d;i++)
    {
        if((m&(ll(1)<<i))==0) continue;
        op(m,basis[i],'^');
        m^=basis[i];
    }
    assert(m==1);
    cout << res.size() << "\n";
    for(auto [a,b,c]:res) cout << a << " " << "^+"[c] << " " << b << "\n";
    return 0;
}