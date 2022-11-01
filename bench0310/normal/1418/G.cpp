#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r) {return uniform_int_distribution<int>(l,r)(gen);}
const array<ll,2> mod={rng(900000000,2000000000),rng(900000000,2000000000)};
const int N=500005;
vector<int> a(N,0);
vector<int> c(N,0);
vector<array<ll,2>> v(N,{0,0});
vector<int> one(N,0);
vector<vector<ll>> pw(N,vector<ll>(2,1));
ll res=0;

void add(ll &x,ll y,int j){x=(x+y)%mod[j];}
void sub(ll &x,ll y,int j){x=(x-(y%mod[j])+mod[j])%mod[j];}

void solve(int l,int r)
{
    if(r-l+1<3) return;
    int m=(l+r)/2;
    map<array<ll,2>,int> cnt;
    array<ll,2> now={0,0};
    int idx=0;
    for(int i=m+1;i<=r;i++)
    {
        c[a[i]]++;
        if(one[a[i]]==0) one[a[i]]=i;
        if(c[a[i]]==4) break;
        for(int j=0;j<2;j++) add(now[j],pw[a[i]][j],j);
        if(c[a[i]]==3) for(int j=0;j<2;j++) sub(now[j],3*pw[a[i]][j],j);
        v[i]=now;
        idx=i;
        cnt[now]++;
    }
    for(int i=m+1;i<=r;i++) c[a[i]]=0;
    now={0,0};
    for(int i=m;i>=l;i--)
    {
        c[a[i]]++;
        if(c[a[i]]==4) break;
        if(c[a[i]]==3&&one[a[i]]>0)
        {
            while(idx>=one[a[i]]) cnt[v[idx--]]--;
        }
        if(c[a[i]]==1) for(int j=0;j<2;j++) add(now[j],2*pw[a[i]][j],j);
        else for(int j=0;j<2;j++) sub(now[j],pw[a[i]][j],j);
        res+=cnt[now];
    }
    for(int i=l;i<=m;i++) c[a[i]]=0;
    for(int i=m+1;i<=r;i++) one[a[i]]=0;
    solve(l,m);
    solve(m+1,r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=0;j<2;j++) pw[i][j]=(3*pw[i-1][j])%mod[j];
    for(int i=1;i<=n;i++) cin >> a[i];
    solve(1,n);
    cout << res << "\n";
    return 0;
}