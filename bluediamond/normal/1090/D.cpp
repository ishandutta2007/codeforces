#include <bits/stdc++.h>

using namespace std;

const int N=100000+5;

int n,m;
set<int>s[N];

int x[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        s[x].insert(y);
        s[y].insert(x);
    }
    int a=-1;
    int b=-1;
    for(int i=1;i<=n && a==-1 && b==-1;i++)
    {
        if(s[i].size()<n)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(s[i].find(j)==s[i].end())
                {
                    a=i;
                    b=j;
                    break;
                }
            }
        }
    }
    if(a==-1 && b==-1)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    if(a>b)
    {
        swap(a,b);
    }
    x[a]=1;
    x[b]=2;
    int lol=3;
    for(int i=1;i<=n;i++)
    {
        if(x[i]==0)
        {
            x[i]=lol++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(x[i]<=2)
        {
            cout<<"1 ";
        }
        else
        {
            cout<<x[i]<<" ";
        }
    }
    cout<<"\n";
    return 0;
}