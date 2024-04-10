#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1000000+5;

int n;
int v[N];

int st[N];
int dr[N];

int stk[N],vf;

inline void Fma()
{
    vf=0; stk[0]=0;
    for(int i=1;i<=n;i++)
    {
        while(vf && v[i]>=v[stk[vf]])
        {
            vf--;
        }
        st[i]=stk[vf];
        stk[++vf]=i;
    }
    vf=0; stk[0]=n+1;
    for(int i=n;i>=1;i--)
    {
        while(vf && v[i]>=v[stk[vf]])
        {
            vf--;
        }
        dr[i]=stk[vf];
        stk[++vf]=i;
    }
    for(int i=1;i<=n;i++)
    {
        st[i]++;
        dr[i]--;
    }
}

inline void Fmi()
{
    vf=0; stk[0]=0;
    for(int i=1;i<=n;i++)
    {
        while(vf && v[i]<=v[stk[vf]])
        {
            vf--;
        }
        st[i]=stk[vf];
        stk[++vf]=i;
    }
    vf=0; stk[0]=n+1;
    for(int i=n;i>=1;i--)
    {
        while(vf && v[i]<=v[stk[vf]])
        {
            vf--;
        }
        dr[i]=stk[vf];
        stk[++vf]=i;
    }
    for(int i=1;i<=n;i++)
    {
        st[i]++;
        dr[i]--;
    }
}

map<pair<int,int>,vector<int>>id;
map<pair<int,int>,int>what;

inline ll f(ll x)
{
    return x*(x+1)/2;
}

inline ll hacker()
{
    id.clear();
    what.clear();
    for(int i=1;i<=n;i++)
    {
        id[{st[i],dr[i]}].push_back(i);
        what[{st[i],dr[i]}]=v[i];
    }
    ll ans=0LL;
    for(auto &it:id)
    {
        int _st=it.first.first;
        int _dr=it.first.second;
        ll val=what[{_st,_dr}];
        int last=_st-1;
        ll cnt=f(_dr-_st+1);
        for(auto &p:it.second)
        {
            cnt-=f(p-last-1);
            last=p;
        }
        cnt-=f(_dr-last);
        ans+=cnt*val;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    Fma();
    ll ans=hacker();
    Fmi();
    ans-=hacker();
    cout<<ans<<"\n";
    return 0;
}