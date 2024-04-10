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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(n%k!=0) print(-1);
        else{
            vi cnt(26);
            for(auto u:s) cnt[u-'a']++;
            int asum=0;
            for(int i=0;i<26;i++)
            {
                cnt[i]%=k;
                asum+=(k-cnt[i])%k;
            }
            if(asum==0) cout<<s<<'\n';
            else{
                int slen=0;
                for(int i=n-1;i>=0;i--)
                {
                    slen++;
                    asum-=(k-cnt[s[i]-'a'])%k;
                    cnt[s[i]-'a']--;
                    cnt[s[i]-'a']+=k;
                    cnt[s[i]-'a']%=k;
                    asum+=(k-cnt[s[i]-'a'])%k;
                    dbg(asum,slen);
                    if(asum<=slen)
                    {
                        int tar=-1;
                        for(int j=s[i]-'a'+1;j<26;j++)
                        {
                            if(cnt[j])
                            {
                                tar=j;
                                break;
                            }
                        }
                        if(tar==-1&&asum==slen) continue;
                        string ans;
                        for(int j=0;j<i;j++) ans+=s[j];
                        if(asum!=slen&&s[i]!='z'){
                            slen--;
                            ans+=s[i]+1;
                            asum-=(k-cnt[s[i]-'a'+1])%k;
                            cnt[s[i]-'a'+1]++;
                            cnt[s[i]-'a'+1]%=k;
                            asum+=(k-cnt[s[i]-'a'+1])%k;
                        }
                        else if(tar!=-1){
                            ans+=tar+'a';
                            cnt[tar]++;
                            cnt[tar]%=k;
                        }
                        else continue;
                        for(int tt=0;tt<slen-asum;tt++) ans+='a';
                        for(int j=0;j<26;j++)
                        {
                            for(int tt=0;tt<(k-cnt[j])%k;tt++) ans+=j+'a';
                        }
                        cout<<ans<<'\n';
                        break;
                    }
                }
            }
        }
    }
}