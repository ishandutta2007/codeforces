#include <bits/stdc++.h>
using namespace std;


int sz[200005];
int bd[200005];
int mn,res;
int n,k;

int a[200005];
vector<int> v[200005];

void dfs(int x,int y){
    sz[x]=1;
    bd[x]=(a[x]<mn ? 1 : 0);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        sz[x]+=sz[to];
        bd[x]+=bd[to];
    }
}
int solve(int x,int y){
    int kolgood=0;
    int mx1=0,mx2=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int q=solve(to,x);
        if (bd[to]==0) kolgood+=q;
        else {
            if (q>mx2) {
                mx2=q;
                if (mx2>mx1) swap(mx1,mx2);
            }
        }
    }
    if (a[x]<mn) return 0;
    int res2=1+kolgood+mx1+mx2+(bd[1]-bd[x]==0 ? sz[1]-sz[x] : 0);
    res=max(res,res2);
    return kolgood+mx1+1;
}

inline bool f(int mid){
    mn=mid;
    dfs(1,-1);
    res=0;
    solve(1,-1);
    return (res>=k);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int l=0;
    int r=1e9;
    while (l<r) {
        int mid=(l+r+1)>>1;
        if (f(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
}