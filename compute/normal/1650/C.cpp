#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        vc<pair<pi,int>> pt(m);
        for(int i=0,x,y;i<m;i++)
        {
            cin>>x>>y;
            pt[i]=make_pair(pi(x,y),i);
        }
        sort(pt.begin(),pt.end());
        vc<ll> pre(m,1e18);
        multiset<int> st;
        ll val=0;
        for(int i=0;i<m;i++)
        {
            st.insert(pt[i].first.second);
            val+=pt[i].first.second;
            if(st.size()>n)
            {
                val-=*st.rbegin();
                st.erase(st.find(*st.rbegin()));
            }
            if(st.size()==n)
                pre[i]=val;
        }
        st.clear();
        val=0;
        ll ans=1e18;
        int tpos=-1;
        for(int i=m-1;i>=0;i--)
        {
            st.insert(pt[i].first.second);
            val+=pt[i].first.second;
            if(st.size()>n)
            {
                val-=*st.rbegin();
                st.erase(st.find(*st.rbegin()));
            }
            if(st.size()==n&&i)
            {
                //ans=min(ans,val+pre[i-1]);
                if(val+pre[i-1]<ans)
                {
                    ans=val+pre[i-1];
                    tpos=i;
                }
            }
        }
        vc<pair<pi,int>> a,b;
        for(int i=0;i<tpos;i++)
            a.push_back(pt[i]);
        for(int i=tpos;i<m;i++)
            b.push_back(pt[i]);
        sort(a.begin(),a.end(),[&](pair<pi,int> x, pair<pi,int> y){
            return x.first.second<y.first.second;
        });
        sort(b.begin(),b.end(),[&](pair<pi,int> x, pair<pi,int> y){
            return x.first.second<y.first.second;
        });
        vc<pi> pa, pb;
        for(int i=0;i<n;i++)
        {
            pa.push_back(pi(a[i].first.first,a[i].second));
            pb.push_back(pi(b[i].first.first,b[i].second));
        }
        sort(pa.begin(),pa.end());
        sort(pb.begin(),pb.end());
        reverse(pb.begin(),pb.end());
        print(ans);
        for(int i=0;i<n;i++)
            cout<<pa[i].second+1<<" "<<pb[i].second+1<<'\n';

    }
}