#include <bits/stdc++.h>
using namespace std;

int kol;
bool used1[100005];
bool used2[100005];
int x,y;
int dp[100005];
int n,m;
vector<int> q;
vector<pair<int,int> > v[100005];

void dfs(int x,int z){
    used1[x]=true;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i].first; int y=v[x][i].second;
        if (y<=z && used1[to]==false) dfs(to,z);
    }
    q.push_back(x);
}
inline bool chek(int mid){
    for (int i=1;i<=n;++i){
        used1[i]=false;
        used2[i]=false;
        dp[i]=0;
    }
    for (int i=1;i<=n;++i){
        for (int j=0;j<v[i].size();++j){
            int to=v[i][j].first;
            int x=v[i][j].second;
            if (x<=mid) used2[to]=true;
        }
    }
    int k=-1;
    for (int i=1;i<=n;++i) {
        if (used2[i]==false) {
            k=i;
            break;
        }
    }
    if (k==-1) return false;
    q.clear();
    dfs(k,mid);
    for (int i=q.size()-1;i>=0;--i) {
        int x=q[i];
        for (int j=0;j<v[x].size();++j) {
            int to=v[x][j].first;
            if (v[x][j].second>mid) continue;
            dp[to]=max(dp[to],dp[x]+1);
        }
        if (dp[x]==n-1) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(make_pair(y,i));
    }
    int l=1;
    int r=m;
    while (l<r-1) {
        int mid=(l+r)/2;
        if (chek(mid)) r=mid;
        else l=mid;
    }
    if (chek(l)) cout<<l;
    else if (chek(r)) cout<<r;
    else cout<<"-1";
}