#include <bits/stdc++.h>
using namespace std;
const int maxn = 14;
const int maxm = 20;
int a[maxn][2005];
int n,m;
int dp[10000][maxm];
int temp[maxn];
void shift(){
    int t = temp[1];
    for (int i=1;i<n;i++){
        temp[i] = temp[i+1];
    }
    temp[n] = t;
}
void Max(int & tar,int x){
    tar = max(tar,x);
}
int calc(int mask){
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (mask & 1)ans += temp[i];
        mask >>= 1;
    }
    return ans;
}
void solve(){
    // cerr<<n<<" "<<m<<endl;
    for (int j=1;j<=m;j++){
        for (int mask = 0;mask < (1 << n);mask ++){
            dp[mask][j] = dp[mask][j-1];
        }
        for (int i=1;i<=n;i++)temp[i] = a[i][j];
        vector<int> maxvalue((1<<n) + 1,0);
        for (int o=0;o<=n;o++){
            for (int mask = 0;mask < (1<<n);mask++){
                int value = calc(mask);
                Max(maxvalue[mask],value);
            }
            shift();
        }
        for (int mask = 0;mask < (1<<n);mask ++){
            int mmm = (1 << (n)) - 1  - mask;
            int value = maxvalue[mask];
            //                for (int maskp = 0;maskp < (1<<n);maskp++){
            for (int maskp = mmm;maskp;maskp = (maskp-1) & mmm){
                //    cerr<<mmm<<" "<<maskp<<endl;
                if (mask & maskp)continue;
                Max(dp[mask | maskp][j],dp[maskp][j-1] + value);
            }
            Max(dp[mask | 0][j],dp[0][j-1] + value);
        }
    }
    int ans = -1;
    for (int mask = 0;mask < (1<<n);mask ++){
        Max(ans,dp[mask][m]);
    }
    cout<<ans<<endl;
}
int aa[maxn][maxm];
int maxx[2005];
void presolve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    vector<int> id(0);
    for (int i=1;i<=m;i++){
        id.push_back(i);
        maxx[i] = a[1][i];
        for (int j=2;j<=n;j++){
            maxx[i] = max(maxx[i],a[j][i]);
        }
    }
    sort(id.begin(),id.end(),[](int x,int y){
        return maxx[x] > maxx[y];
    });
    int mm = 0;
    for (int i=1;i<=min(13,m);i++){
        mm ++;
        for (int j=1;j<=n;j++){
            aa[j][mm] = a[j][id[i-1]];
        }
    }
    m = mm;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j] = aa[i][j];
        }
    }
}
int main(){
    int T;
    cin>>T;
    while (T--){
        presolve();
        solve();
    }
    
    return 0;
}