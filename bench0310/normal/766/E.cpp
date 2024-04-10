#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<int> x(N);
vector<int> val(N,0);
ll res=0;

array<ll,2> operator+(const array<ll,2> &a,const array<ll,2> &b)
{
    return {a[0]+b[0],a[1]+b[1]};
}

void operator+=(array<ll,2> &a,const array<ll,2> &b)
{
    a=a+b;
}

array<ll,2> operator-(const array<ll,2> &a,const array<ll,2> &b)
{
    return {a[0]-b[0],a[1]-b[1]};
}

void operator-=(array<ll,2> &a,const array<ll,2> &b)
{
    a=a-b;
}

void dfs(int a,int p=0)
{
    val[a]=val[p]^x[a];
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
    }
}

array<ll,2> solve(int a,int p,int e)
{
    int b=((val[a]>>e)&1);
    int c=((x[a]>>e)&1);
    array<ll,2> sum={0,0};
    vector<array<ll,2>> z;
    for(int to:v[a])
    {
        if(to==p) continue;
        z.push_back(solve(to,a,e));
        sum+=z.back();
    }
    ll now=0;
    for(array<ll,2> t:z)
    {
        sum-=t;
        for(int i=0;i<2;i++) now+=(t[i]*sum[i^c^1]);
        sum+=t;
    }
    res+=((now/2)*(1ll<<e));
    res+=(sum[b^c^1]*(1ll<<e));
    sum[b]++;
    if(c) res+=(1ll<<e);
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i=0;i<=19;i++) solve(1,0,i);
    cout << res << "\n";
    return 0;
}