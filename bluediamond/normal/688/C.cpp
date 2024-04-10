#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000000+5;

int n,m;
vector<int>g[N];
int col[N];

void go(int nod)
{
    for(auto &nou:g[nod])
    {
        if(col[nou]==-1)
        {
            col[nou]=3-col[nod];
            go(nou);
        }
        else
        {
            if(col[nou]!=3-col[nod])
            {
                cout<<"-1\n";
                exit(0);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++) col[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==-1)
        {
            col[i]=1;
            go(i);
        }
    }
    int c1=0,c2=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    cout<<c1<<"\n";
    for(int i=1;i<=n;i++) if(col[i]==1) cout<<i<<" ";
    cout<<"\n"<<c2<<"\n";
    for(int i=1;i<=n;i++) if(col[i]==2) cout<<i<<" ";
    cout<<"\n";
    return 0;
}
/**



**/