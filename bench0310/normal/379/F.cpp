#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
int depth[N];
int p[N][20];

void add(int a,int b)
{
    depth[a]=depth[b]+1;
    p[a][0]=b;
    for(int i=1;i<20;i++) p[a][i]=p[p[a][i-1]][i-1];
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=19;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=19;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

int dist(int a,int b)
{
    return (depth[a]+depth[b]-2*depth[lca(a,b)]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    add(1,0);
    for(int i=2;i<=4;i++) add(i,1);
    int n=4;
    int mx=2;
    int now=2;
    for(int i=1;i<=q;i++)
    {
        int b;
        cin >> b;
        add(++n,b);
        add(++n,b);
        int a=n-1;
        if(depth[a]>depth[mx])
        {
            now++;
            mx=a;
        }
        else now=max(now,dist(a,mx));
        cout << now << "\n";
    }
    return 0;
}