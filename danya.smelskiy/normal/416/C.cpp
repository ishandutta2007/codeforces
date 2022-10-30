#include <bits/stdc++.h>
using namespace std;


int n,m;
struct st{
    int x,y;
    int id;
};
st a[10005];
pair<int,int> b[10005];
vector<pair<int,int> > v;
int last;
long long dp[1005][1005];
bool used[1005][1005];
long long ans;
inline bool cmp(st a,st b){
    return a.x<b.x;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].x;
        cin>>a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(b+1,b+m+1);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j) {
            if (b[j].first>=a[i].x) {
                long long sum=dp[i-1][j-1];
                sum+=a[i].y;
                if (sum>dp[i-1][j]) {
                    used[i][j]=true;
                    dp[i][j]=sum;
                } else {
                    dp[i][j]=dp[i-1][j];
                    used[i][j]=false;
                }
            } else {
                used[i][j]=false;
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for (int i=1;i<=m;++i)
        if (dp[n][i]>ans) { ans=dp[n][i]; last=i;}
    int qq=n;
    while (qq>0) {
        if (used[qq][last]==true) {
            v.push_back(make_pair(a[qq].id,b[last].second));
            --last; --qq;
        } else --qq;
    }
    cout<<v.size()<<" "<<ans<<'\n';
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i)
        cout<<v[i].first<<" "<<v[i].second<<'\n';
}