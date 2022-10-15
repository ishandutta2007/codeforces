#include <bits/stdc++.h>

using namespace std;

const int N=200+5;
const int L=N*(N-1)/2;

int n;

int t[N],h[N];

vector<int>where[N];
bool have[L][N];

int egale[N],cnt=0;

bool used[N];

/// bag seturi

inline int dad(int a)
{
    if(a==t[a])
        return a;
    t[a]=dad(t[a]);
    return t[a];
}

inline void unite(int a,int b)
{
    a=dad(a);
    b=dad(b);
    if(a==b)
        return;
    if(h[a]>h[b])
        t[b]=a;
    else
    {
        t[a]=b;
        if(h[a]==h[b])
            h[a]++;
    }
}

int grup[N][N],len[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=1;i<N;i++)
    {
        t[i]=i;
        h[i]=1;
    }

    cin>>n;

    for(int i=1;i<=n*(n-1)/2;i++)
    {
        int l,x;
        cin>>l;
        for(int j=1;j<=l;j++)
        {
            cin>>x;
            used[x]=1;
            where[x].push_back(i);
            have[i][x]=1;
        }
    }

    if(n==2)
    {
        vector<int>var;
        for(int i=1;i<N;i++)
            if(used[i])
                var.push_back(i);
        cout<<"1 "<<var[0]<<"\n";
        cout<<var.size()-1<<" ";
        for(int j=1;j<var.size();j++)
            cout<<var[j]<<" ";
        cout<<"\n";
        return 0;
    }

    for(int i=1;i<N;i++)
    {
        if(where[i].size()<2)
            continue;
        int f=where[i][0];
        int s=where[i][1];
        cnt=0;
        for(int x=1;x<N;x++)
            if(have[f][x] && have[s][x])
                egale[++cnt]=x;
        for(int j=1;j<cnt;j++)
            unite(egale[j],egale[j+1]);
    }

    for(int i=1;i<N;i++)
    {
        int bb=dad(i);
        grup[bb][++len[bb]]=i;
    }

    for(int i=1;i<N;i++)
    {
        bool ok=0;
        for(int j=1;j<=len[i];j++)
            if(used[grup[i][j]])
            {
                ok=1;
                break;
            }
        if(ok)
        {
            cout<<len[i]<<" ";
            for(int j=1;j<=len[i];j++)
                cout<<grup[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
/**


**/