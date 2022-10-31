#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


long long dp[200005][2];
long long dp2[200005][2];
long long ans;
long long a[200005];
long long n;
vector<int> v[200005];



void dfs1(int x,int y) {
    dp[x][1]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs1(to,x);
        dp[x][1]+=dp[to][0];
        dp[x][0]+=dp[to][1];
        if (dp[x][1]>=md) dp[x][1]-=md;
        if (dp[x][0]>=md) dp[x][0]-=md;
    }
}

void dfs2(int x,int y) {
    dp2[x][0]=dp[x][0];
    dp2[x][1]=dp[x][1];
    if (y!=-1) {
        dp2[x][0]+=dp2[y][1];
        dp2[x][1]+=dp2[y][0];
        if (dp2[x][0]>=md) dp2[x][0]-=md;
        if (dp2[x][1]>=md) dp2[x][1]-=md;
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dp2[x][0]-=dp[to][1];
        if (dp2[x][0]<0) dp2[x][0]+=md;
        dp2[x][1]-=dp[to][0];
        if (dp2[x][1]<0) dp2[x][1]+=md;
        dfs2(to,x);
        dp2[x][0]+=dp[to][1];
        if (dp2[x][0]>=md) dp2[x][0]-=md;
        dp2[x][1]+=dp[to][0];
        if (dp2[x][1]>=md) dp2[x][1]-=md;
    }
    long long s1=dp[x][0];
    if (y!=-1) {
        s1+=dp2[y][1];
        if (s1>=md) s1-=md;
    }
    long long s2=dp[x][1];
    if (y!=-1) {
        s2+=dp2[y][0];
        if (s2>=md) s2-=md;
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        long long s3,s4;
        if (to==y) s3=dp2[y][1],s4=dp2[y][0];
        else s3=dp[to][1],s4=dp[to][0];
        long long ss1=s1-s3;
        if (ss1<0) ss1+=md;
        long long ss2=s2-s4;
        if (ss2<0) ss2+=md;
        long long res=(ss1+ss2);
        if (res>=md) res-=md;
        res=(res*s4)%md;
        res=(res*a[x])%md;
        ans+=res;
        if (ans>=md) ans-=md;
        res=(ss1+ss2);
        if (res>=md) res-=md;
        res=(res*s3)%md;
        res=(res*a[x])%md;
        ans-=res;
        if (ans<0) ans+=md;
    }
    long long res=n;
    res=(res*a[x])%md;
    ans+=res;
    if (ans>=md) ans-=md;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]<0) a[i]+=md;
    }
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    cout<<ans;
}