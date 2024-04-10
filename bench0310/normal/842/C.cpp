#include <bits/stdc++.h>

using namespace std;

const int N=200000;
vector<int> v[N+1];
vector<int> depth(N+1,0);
vector<int> x(N+1,0);
vector<int> cnt(N+1,0);
vector<int> res(N+1,0);
vector<int> t(N+1,0);
vector<int> z;

void dfs(int a,int p=0)
{
    depth[a]=depth[p]+1;
    if(a!=1) t[a]=gcd(t[p],x[a]);
    for(int d:z) if((x[a]%d)==0) cnt[d]++;
    for(int d:z) if(cnt[d]>=depth[a]-1) res[a]=d;
    res[a]=max(res[a],t[a]);
    for(int to:v[a]) if(to!=p) dfs(to,a);
    for(int d:z) if((x[a]%d)==0) cnt[d]--;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=x[1];i++) if((x[1]%i)==0) z.push_back(i);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    res[1]=x[1];
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}