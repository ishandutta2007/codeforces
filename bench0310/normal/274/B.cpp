#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> v[N];
vector<long long> val(N,0);

long long add(int a,int p=-1)
{
    long long res=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        res=max(res,add(to,a));
        res=max(res,val[to]-val[a]);
    }
    if(res<-val[a]) res=-val[a];
    val[a]+=res;
    return res;
}

long long rm(int a,int p=-1)
{
    long long res=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        res=max(res,rm(to,a));
    }
    if(res<val[a]) res=val[a];
    val[a]-=res;
    return res;
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
    for(int i=1;i<=n;i++) scanf("%I64d",&val[i]);
    printf("%I64d\n",add(1)+rm(1));
    return 0;
}