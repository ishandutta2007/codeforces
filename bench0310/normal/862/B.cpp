#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> v[N];
vector<bool> c(N,0);
vector<long long> cnt(2,0);

void dfs(int a,int p=-1)
{
    c[a]=(p==-1?0:(!c[p]));
    cnt[c[a]]++;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    printf("%I64d\n",cnt[0]*cnt[1]-(n-1));
    return 0;
}