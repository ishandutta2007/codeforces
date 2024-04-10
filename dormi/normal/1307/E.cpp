#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5001;
lli mod=1e9+7;
int arr[MAXN];
int pre[MAXN][MAXN];
pii cow[MAXN];
vector<int> cows[MAXN];
map<int,lli> ans;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=1;j<=n;j++)pre[i][j]=pre[i-1][j];
        pre[i][arr[i]]++;
    }
    for(int i=0;i<m;i++){
        cin>>cow[i].first>>cow[i].second;
        cows[cow[i].first].push_back(cow[i].second);
    }
    for(int i=1;i<=n;i++)sort(cows[i].begin(),cows[i].end());
    for(int i=0;i<=n;i++){
        int lneed=pre[i][arr[i]];
        lli ways=1;
        lli am=0;
        for(int j=1;j<=n;j++){
            if(j!=arr[i]||lneed==0) {
                lli bothcnt = 0;
                lli onecnt = 0;
                for (int x:cows[j]) {
                    int cnt = 0;
                    if (pre[i][j] >= x)cnt++;
                    if (pre[n][j] - pre[i][j] >= x)cnt++;
                    if (cnt == 2)bothcnt++;
                    else if (cnt == 1)onecnt++;
                }
                if (bothcnt >= 2){
                    am += 2;
                    ways = ways * (((onecnt * bothcnt % mod) + (bothcnt * (bothcnt - 1) % mod)) % mod) % mod;
                }
                else if (bothcnt == 1 && onecnt >= 1){
                    am += 2;
                    ways = ways * (((onecnt * bothcnt % mod) + (bothcnt * (bothcnt - 1) % mod)) % mod) % mod;
                }
                else if(bothcnt==1&&onecnt==0){
                    am += 1;
                    ways = ways * (2) % mod;
                }
                else if (bothcnt == 0 && onecnt >= 1){
                    am += 1;
                    ways = ways * (onecnt) % mod;
                }
            }
            else{
                lli cnt=0;
                bool work=false;
                for (int x:cows[j]) {
                    if(x!=lneed) {
                        if (pre[n][j] - pre[i][j] >= x)cnt++;
                    }
                    else{
                        work=true;
                    }
                }
                if(work){
                    if(cnt>=1){
                        am+=2;
                        ways=ways*(cnt)%mod;
                    }
                    else am+=1;
                }
                else{
                    ways=0;
                }
            }
        }
        if(ways)ans[am]=(ans[am]+ways)%mod;
    }
    ans[0]=1;
    printf("%d %lli\n",ans.rbegin()->first,ans.rbegin()->second);
    return 0;
}