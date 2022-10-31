#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
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
const int INF=0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int cnts[30],cntt[30];
        memset(cnts,0,sizeof(cnts));
        memset(cntt,0,sizeof(cntt));
        for(int i=0;i<n;i++)
        {
            cnts[s[i]-'a']++;
            cntt[t[i]-'a']++;
        }
        bool ok=1,one=1;
        for(int i=0;i<26;i++)
        {
            if(cnts[i]!=cntt[i]) ok=0;
            if(cnts[i]>1) one=0;
        }
        if(!ok)
            cout<<"NO\n";
        else{
            if(!one) cout<<"YES\n";
            else{
                int tmp[30];
                memset(tmp,0,sizeof(tmp));
                int rs=0,rt=0;
                for(int i=0;i<n;i++)
                {
                    for(int j=s[i]-'a'+1;j<26;j++)
                        rs+=tmp[j];
                    tmp[s[i]-'a']++;
                }
                memset(tmp,0,sizeof(tmp));
                for(int i=0;i<n;i++)
                {
                    for(int j=t[i]-'a'+1;j<26;j++)
                        rt+=tmp[j];
                    tmp[t[i]-'a']++;
                }
                if((rs&1)!=(rt&1)) cout<<"NO\n";
                else cout<<"YES\n";
            }
        }
    }
}