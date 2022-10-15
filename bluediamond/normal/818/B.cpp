#include <bits/stdc++.h>

using namespace std;

const int N=100+5;

int n,m;
int val[N];
int v[N];
int f[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>val[i];
    }
    for(int i=1;i<=n;i++)
    {
        v[i]=-1;
    }
    for(int i=2;i<=m;i++)
    {
        int x=val[i-1];
        int y=val[i];
        int d;
        if(y>x)
        {
            d=y-x;
        }
        else
        {
            d=n-x+y;
        }
        if(v[x]==-1)
        {
            v[x]=d;
        }
        if(v[x]!=d)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=-1)
        {
            f[v[i]]++;
            if(f[v[i]]==2)
            {
                cout<<"-1\n";
                return 0;
            }
        }
    }
    vector<int>kek;
    for(int i=1;i<=n;i++)
    {
        if(f[i]==0)
        {
            kek.push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==-1)
        {
            v[i]=kek.back();
            kek.pop_back();
            f[v[i]]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]==0)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}