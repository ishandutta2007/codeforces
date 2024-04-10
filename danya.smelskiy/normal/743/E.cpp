#include <bits/stdc++.h>
using namespace std;


int n;
int a[1005];
bool used[1005];
int dp[1005][(1<<8)+5];
int res1;
int l[1005];
vector<int> v[1005];
inline int f(int mid){
    if (mid==0) return res1;
    for (int i=0;i<=n;++i)
        for (int j=0;j<(1<<8);++j)
            dp[i][j]=-1;
    for (int i=0;i<8;++i)
        l[i]=0;
    int res=-1;
    dp[0][0]=0;
    for (int i=0;i<=n;++i) {
        for (int j=0;j<8;++j) {
            while (l[j]<v[j].size() && (l[j]<mid-1 || v[j][l[j]-mid+1]<=i)) ++l[j];
        }
        for (int j=0;j<(1<<8);++j) if (dp[i][j]!=-1) {
            for (int k=0;k<8;++k) if ((j&(1<<k))==0) {
                int mask=(j|(1<<k));
                if (l[k]<v[k].size()) dp[v[k][l[k]]][mask]=max(dp[v[k][l[k]]][mask],dp[i][j]+mid);
                if (l[k]+1<v[k].size()) dp[v[k][l[k]+1]][mask]=max(dp[v[k][l[k]+1]][mask],dp[i][j]+mid+1);
            }
        }
        res=max(res,dp[i][((1<<8)-1)]);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (used[a[i]]==false) {
            used[a[i]]=true;
            ++res1;
        }
        v[a[i]-1].push_back(i);
    }
    int ll=0;
    int r=n;
    while (ll<r-1) {
        int mid=(ll+r)>>1;
        if (f(mid)!=-1) ll=mid;
        else r=mid;
    }
    if (f(r)!=-1) cout<<f(r)<<'\n';
    else cout<<f(ll)<<'\n';
}