#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=100000+5;

ll f(ll r,ll c)
{
    return r*N+c;
}

unordered_set<ll>s;

bool is(int r,int c)
{
    ll h=f(r,c);
    if(s.count(h))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

vector<int>R[N];
vector<int>C[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    s.rehash(n);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int r,c;
        cin>>r>>c;
        if(R[r].size()<C[c].size())
        {
            for(auto &c2:R[r])
            {
                int l=abs(c2-c);
                if(is(r+l,c) && is(r+l,c2)) res++;
                if(is(r-l,c) && is(r-l,c2)) res++;
            }
        }
        else
        {
            for(auto &r2:C[c])
            {
                int l=abs(r-r2);
                if(is(r,c+l) && is(r2,c+l)) res++;
                if(is(r,c-l) && is(r2,c-l)) res++;
            }
        }
        s.insert(f(r,c));
        R[r].push_back(c);
        C[c].push_back(r);
    }
    cout<<res<<"\n";
    return 0;
}
/**

**/