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
struct node{
	int l,r;
	mutable int val;
	bool operator<(const node &a)const{
		return r<a.r;
	}
};
set<node> st;
void split(int p)
{
	auto it = st.lower_bound({p, p, 0});
	if(it -> l == p) return;
	int l = it -> l, r = it -> r; int val = it -> val;
	st.erase(it);
	st.insert({l, p-1, val});
	st.insert({p, r, val});
}
bool suc=1;
void update(int l, int r)
{
	split(l), split(r + 1);
    auto cur=st.lower_bound({l, l, 0});
    int cnt0=0,cnt1=0;
    while(cur->r <= r)
    {
        auto tmp = cur;
        if(tmp->val) cnt1+=((tmp->r)-(tmp->l)+1);
        else cnt0+=((tmp->r)-(tmp->l)+1);
        cur++;
        st.erase(tmp);
    }
    //cout<<l<<" "<<r<<" :" <<cnt0<<" "<<cnt1<<endl;
    if(cnt0==cnt1) suc=0;
    else if(cnt0>cnt1)
        st.insert({l, r, 0});
    else st.insert({l,r,1});
}
void update(int l, int r, int v)
{
	split(l), split(r + 1);
    auto cur=st.lower_bound({l, l, 0});
    while(cur->r <= r)
    {
        auto tmp = cur;
        cur++;
        st.erase(tmp);
    }
    st.insert({l, r, v});
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        st.clear();
        suc=1;
        int n,q;
        cin>>n>>q;
        string s,f;
        cin>>s>>f;
        st.insert({0,n,0});
        {
            int val=0;
            int pre=0;
            for(int i=0;i<n;i++)
            {
                if(f[i]-'0'!=val)
                {
                    if(pre<i) update(pre,i-1,val);
                    val=f[i]-'0';
                    pre=i;
                }
            }
            update(pre,n-1,f.back()-'0');
        }
        vc<pi> seg(q);
        for(int i=0,l,r;i<q;i++)
        {
            cin>>l>>r;
            l--,r--;
            seg[i]={l,r};
        }
        for(int i=q-1;i>=0;i--)
        {
            update(seg[i].first,seg[i].second);
            if(!suc) break;
        }
        string tar;
        for(auto u:st)
        {
            for(int i=0;i<u.r-u.l+1;i++)
                tar+='0'+u.val;
        }
            tar.pop_back();
            //cout<<tar<<endl;
            if(tar!=s) suc=0;
        if(suc) cout<<"YES\n";
        else cout<<"NO\n";
    }
}