#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n;
long long dp[100][2][2][2];
long long sum[100][2][2][2];

inline long long solve(int x,int y,int k){
    if (x<0 || y<0 || k<0) return 0;
    vector<int> v1,v2,v3;
    for (int i=0;i<31;++i) {
        v1.push_back(x%2); x>>=1;
        v2.push_back(y%2); y>>=1;
        v3.push_back(k%2); k>>=1;
    }
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    reverse(v3.begin(),v3.end());
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    dp[0][1][1][1]=1;
    for (int i=0;i<31;++i)
        for (int a=0;a<2;++a)
            for (int b=0;b<2;++b)
                for (int c=0;c<2;++c)
                    for (int x=0;x<2;++x)
                        for (int y=0;y<2;++y) {
                            int q=(x^y);
                            if (a && !(v1[i]) && x) continue;
                            if (b && !(v2[i]) && y) continue;
                            if (c && !(v3[i]) && q) continue;
                            int a1=(a&(v1[i]==x));
                            int a2=(b&(v2[i]==y));
                            int a3=(c&(v3[i]==q));
                            dp[i+1][a1][a2][a3]+=dp[i][a][b][c];
                            if (dp[i+1][a1][a2][a3]>=md) dp[i+1][a1][a2][a3]-=md;
                            sum[i+1][a1][a2][a3]+=sum[i][a][b][c];
                            if (sum[i+1][a1][a2][a3]>=md) sum[i+1][a1][a2][a3]-=md;
                            if (q) {
                                sum[i+1][a1][a2][a3]+=((long long)(1<<30-i)*dp[i][a][b][c])%md;
                                if (sum[i+1][a1][a2][a3]>=md) sum[i+1][a1][a2][a3]-=md;
                            }
                        }
    long long res=0;
    for (int i=0;i<2;++i)
        for (int j=0;j<2;++j)
    for (int z=0;z<2;++z){
        res=(res+dp[31][i][j][z]+sum[31][i][j][z])%md;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x,y,xx,yy,k;
        cin>>x>>y>>xx>>yy>>k;
        --x; --y; --xx; --yy; --k;
        long long ans=(((solve(xx,yy,k))+solve(x-1,y-1,k))%md)-((solve(x-1,yy,k)+solve(xx,y-1,k))%md);
        if (ans<0) ans+=md;
        cout<<ans<<'\n';
    }
}