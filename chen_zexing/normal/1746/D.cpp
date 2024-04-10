#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
unordered_map <int,long long> dp[200005];
int a[200005];
vector <int> v[200005];
long long solve(int x,int cnt){
    //cout<<x<<" "<<cnt<<endl;
    if(!cnt) return 0;
    if(dp[x].count(cnt)) return dp[x][cnt];
    vector <long long> bonus;
    long long ans=1LL*a[x]*cnt;
    if(!v[x].size()) return dp[x][cnt]=ans;
    if(v[x].size()==1){
        return dp[x][cnt]=ans+solve(v[x][0],cnt);
    }
    for(auto t:v[x]){
        bonus.push_back(solve(t,cnt/int(v[x].size())+1)-solve(t,cnt/int(v[x].size())));
        ans+=solve(t,cnt/int(v[x].size()));
    }
    sort(bonus.begin(),bonus.end(),greater<long long>());
    for(int i=0;i<cnt%int(v[x].size());i++) ans+=bonus[i];
    //cout<<x<<" "<<cnt<<" "<<ans<<endl;
    return dp[x][cnt]=ans;
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=2,x;i<=n;i++){
            scanf("%d",&x),v[x].push_back(i);
        }
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i].clear();
        printf("%lld\n",solve(1,k));
    }
    return 0;
}