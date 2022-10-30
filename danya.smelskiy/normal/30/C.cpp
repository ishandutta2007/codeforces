#include <bits/stdc++.h>
using namespace std;

int n;
struct st{
    long double x,y,t,p;
};
long double dp[1005];
st q[1005];
inline bool cmp(st a,st b){
    return a.t<b.t;
}
inline long double len(int x,int y){
    return sqrt((q[x].x-q[y].x)*(q[x].x-q[y].x)+(q[x].y-q[y].y)*(q[x].y-q[y].y));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        st t;
        cin>>t.x>>t.y>>t.t>>t.p;
        q[i]=t;
    }
    long double ans=0;
    sort(q+1,q+n+1,cmp);
    for (int i=1;i<=n;++i) {
        dp[i]=max(dp[i],q[i].p);
        for (int j=i+1;j<=n;++j){
            if (q[i].t+len(i,j)<=q[j].t) {
                dp[j]=max(dp[j],dp[i]+q[j].p);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<fixed<<setprecision(10)<<ans;
}