#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m;

set<array<int,2>> gen(vector<bool> &a)
{
    int l=0;
    set<array<int,2>> s;
    while(l<n)
    {
        while(l<n&&a[l]==1) l++;
        if(l==n) break;
        int r=l;
        while(r+1<n&&a[r+1]==0) r++;
        s.insert({l,r});
        l=r+1;
    }
    return s;
}

vector<bool> solve(vector<bool> &a,vector<bool> &b)
{
    set<array<int,2>> s=gen(a);
    auto ex=[&](int pos,int d)->array<int,3>
    {
        auto it=s.upper_bound({pos+d+1,n});
        array<int,3> res={-1,n,n};
        if(it!=s.end())
        {
            res[1]=(*it)[0]-d;
            res[2]=(*it)[1]-d;
        }
        if(it!=s.begin())
        {
            it--;
            res[0]=(*it)[1]-d;
        }
        return res;
    };
    int r=n;
    for(int i=0;i<m;i++)
    {
        if(b[i]==0) continue;
        array<int,3> now=ex(-1,i);
        r=min(r,now[1]);
        if(now[0]!=-1) r=0;
    }
    vector<bool> v(n,0);
    for(int i=0;i<n;i++) v[i]=(i+m-1<n);
    if(r==n) return v;
    r--;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;
    for(int i=0;i<m;i++) if(b[i]==1) q.push({0,0,i});
    while(1)
    {
        int x=q.top()[0];
        int d=q.top()[2];
        q.pop();
        if(x==n) break;
        if(r<x) r=x-1;
        array<int,3> now=ex(r,d);
        while(r<now[0]) v[++r]=0;
        q.push({now[1],now[2],d});
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> m >> k;
    string s,t;
    cin >> s >> t;
    string alpha="ACGT";
    auto f=[&](char c){return alpha.find(c);};
    vector<int> r(4,0);
    vector<vector<bool>> a(4,vector<bool>(n,0));
    for(int i=0;i<n;i++)
    {
        int x=f(s[i]);
        r[x]=max(r[x],i-k);
        while(r[x]<=min(n-1,i+k)) a[x][r[x]++]=1;
    }
    vector<bool> res(n,1);
    for(int i=0;i<4;i++)
    {
        vector<bool> b(m,0);
        for(int j=0;j<m;j++) b[j]=(t[j]==alpha[i]);
        vector<bool> ok=solve(a[i],b);
        for(int j=0;j<n;j++) if(ok[j]==0) res[j]=0;
    }
    int c=0;
    for(int i=0;i<n;i++) c+=res[i];
    cout << c << "\n";
    return 0;
}