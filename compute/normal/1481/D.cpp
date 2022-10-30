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
const int maxn=1e3+7;
string e[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>e[i];
        int s=-1,t=-1;
        vi ina(n),inb(n),outa(n),outb(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(e[i][j]==e[j][i])
                {
                    s=i;
                    t=j;
                    break;
                }
                if(e[i][j]=='a')
                {
                    ina[j]=1;
                    outa[i]=1;
                }
                else{
                    inb[j]=1;
                    outb[i]=1;
                }
                if(e[j][i]=='a')
                {
                    ina[i]=1;
                    outa[j]=1;
                }
                else{
                    inb[i]=1;
                    outb[j]=1;
                }
            }
            if(s!=-1) break;
        }
        if(m&1) s=0,t=1;
        if(s!=-1)
        {
            cout<<"YES\n";
            cout<<s+1<<" ";
            for(int i=0;i<m;i++)
            {
                if(i&1) cout<<s+1;
                else cout<<t+1;
                cout<<" \n"[i==m-1];
            }
        }
        else{
            int tar=-1,kd=-1;
            for(int i=0;i<n;i++)
            {
                if(ina[i]&&outa[i])
                {
                    kd=0;
                    tar=i;
                    break;
                }
                if(inb[i]&&outb[i])
                {
                    kd=1;
                    tar=i;
                    break;
                }
            }
            if(tar==-1)
                cout<<"NO\n";
            else {
                cout<<"YES\n";
                int from=-1,to=-1;
                for(int i=0;i<n;i++)
                {
                    if(e[i][tar]==kd+'a')
                        from=i;
                    if(e[tar][i]==kd+'a')
                        to=i;
                }
                int len=m/2;
                assert(from!=-1&&to!=-1);
                vi ans;
                if(len&1)
                {
                    ans.push_back(from);
                    for(int i=0;i<len;i++)
                    {
                        if(i&1) ans.push_back(from);
                        else ans.push_back(tar);
                    }
                    for(int i=0;i<len;i++)
                    {
                        if(i&1) ans.push_back(tar);
                        else ans.push_back(to);
                    }
                }
                else{
                    ans.push_back(tar);
                    for(int i=0;i<len;i++)
                    {
                        if(i&1) ans.push_back(tar);
                        else ans.push_back(from);
                    }
                    for(int i=0;i<len;i++)
                    {
                        if(i&1) ans.push_back(tar);
                        else ans.push_back(to);
                    }
                }
                for(auto &u:ans) u++;
                print(ans);
            }
        }
    }
}