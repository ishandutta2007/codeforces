#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
bool ans[maxn];
ll dis[maxn][maxn];
void solve(){
    memset(ans,0,sizeof ans);
    int n;
    cin>>n;
    vector<pair<int,int> > a(0);
    for (int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    ll gcd = -1;
    for (int i=0;i<a.size();i++){
        for (int j = 0;j < i;j ++){
            ll dx = a[i].first - a[j].first;
            ll dy = a[j].second - a[i].second;
            dis[i][j] = dis[j][i] = dx * dx + dy * dy;
            if (gcd == -1){
                gcd = dis[i][j];
            }else{
                gcd = __gcd(gcd,dis[i][j]);
            }
        }
    }
    int cnt = 1;
    ans[0] = 1;
    for (int j= 1;j <n;j ++){
        dis[0][j] /= gcd;
        //cerr<<dis[0][j]<<endl;
        if (dis[0][j] % 2 == 0){
            ans[j] = 1;
            cnt ++;
        }
    }
    cout<<cnt<<endl;
    for (int i=0;i<n;i++){
        if (ans[i]){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;


}
int main(){
    solve();
    return 0;
}