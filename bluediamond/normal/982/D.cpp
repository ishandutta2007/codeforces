#include <bits/stdc++.h>

using namespace std;

const int N=100000+5;

int n;
int v[N];
pair<int,int>a[N];

int t[N];
int h[N];
int l[N];

inline int dad(int nod)
{
   /// cout<<nod<<"\n";
    if(t[nod]==nod)
    {
        return nod;
    }
    else
    {
        t[nod]=dad(t[nod]);
        return t[nod];
    }
}

int cnt=0;
int f[N];

inline void uni(int a,int b)
{
    a=dad(a);
    b=dad(b);
    if(a==b)
    {
        return;
    }
    cnt--;
    f[l[a]]--;
    f[l[b]]--;
    if(h[a]<h[b])
    {
        t[a]=b;
        l[b]+=l[a];
        f[l[b]]++;
    }
    else
    {
        t[b]=a;
        if(h[a]==h[b])
        {
            h[a]++;
        }
        l[a]+=l[b];
        f[l[a]]++;
    }
}

bool seen[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        t[i]=i;
        h[i]=1;
        l[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        a[i]={v[i],i};
    }
    sort(a+1,a+n+1);
    int k=-1;
    int id=-1;
    for(int it=1;it<=n;it++)
    {
        int i=a[it].second;
        f[1]++;
        cnt++;
        seen[i]=1;
        if(seen[i-1])
        {
            uni(i,i-1);
        }
        if(seen[i+1])
        {
            uni(i,i+1);
        }
        if(f[l[dad(i)]]==cnt)
        {
            if(cnt>k)
            {
                k=cnt;
                id=v[i]+1;
            }
        }
        continue;
        cout<<cnt<<" "<<l[dad(i)]<<"\t"<<f[l[dad(i)]]<<"\t\t";
        for(int i=1;i<=n;i++)
        {
            cout<<seen[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<id<<"\n";
    return 0;
}
/**

**/