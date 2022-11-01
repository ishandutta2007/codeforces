#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> depth(N,0);
int k;

void dfs(int a,int p=0)
{
    depth[a]=depth[p]+1;
    for(int to:v[a]) if(to!=p) dfs(to,a);
}

int solve(int a,int p=0)
{
    if(a==1)
    {
        int one=0;
        for(int to:v[a])
        {
            if(to==p) continue;
            int b=solve(to,a);
            if(b==-1) return -1;
            if(depth[b]-depth[a]==k) one++;
            else if(depth[b]-depth[a]>k) return -1;
        }
        if(one>1) return -1;
        else return 0;
    }
    else
    {
        if(v[a].size()==1) return a;
        int m=-1;
        for(int to:v[a])
        {
            if(to==p) continue;
            int b=solve(to,a);
            if(b==-1||depth[b]-depth[a]+1>k) return -1;
            if(m==-1||depth[b]<depth[m]) m=b;
        }
        return m;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        int l=0,r=n;
        while(l<r-1)
        {
            k=(l+r)/2;
            if(solve(1)!=-1) r=k;
            else l=k;
        }
        cout << r << "\n";
        for(int i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}