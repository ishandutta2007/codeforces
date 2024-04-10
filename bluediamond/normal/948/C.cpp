#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int nmax=100000;
ll n,v[nmax+5],t[nmax+5],S[nmax+5];
ll gata[nmax+5];
ll sol[nmax+5];
int in[nmax+5];
int out[nmax+5];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        S[i]=S[i-1]+t[i];
    }
    for(int i=1;i<=n;i++)
    {
        int r=i-1,pas=(1<<16);
        while(pas)
        {
            if(r+pas<=n && S[r+pas]-S[i-1]<=v[i])
                r+=pas;
            pas/=2;
        }
        if(r<i)
        {
            gata[i]=-1;
            sol[i]+=min(t[i],v[i]-(S[r]-S[i-1]));
        }
        else
        {
            gata[i]=r;
            sol[r+1]+=min(t[r+1],v[i]-(S[r]-S[i-1]));
            in[i]++;
            out[r+1]++;
        }
    }
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        cur+=in[i]-out[i];
        cout<<sol[i]+cur*t[i]<<" ";
    }
    return 0;
}