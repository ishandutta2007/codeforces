#include <bits/stdc++.h>
using namespace std;



int dp2[505][505];
bool dp[505][505][10][20];
int n,m,ans;
string s[505];

inline bool f1(int x,int y,int z){
    int xx=x-z+1;
    int yy=y-z+1;
    swap(x,xx);
    swap(y,yy);
    int res=dp2[xx][yy]+dp2[x-1][y-1]-dp2[xx][y-1]-dp2[x-1][yy];
    return res==(xx-x+1)*(yy-y+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        for (int j=1;j<=m;++j) {
            dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1]+(s[i][j-1]=='*' ?  1  : 0);
        }
    }
    for (int i=2;i<=n;++i) {
        for (int j=2;j<=m;++j) {
            int msk=0;
            if (s[i-1][j-2]=='*') msk|=1;
            if (s[i-1][j-1]=='*') msk|=2;
            if (s[i][j-2]=='*') msk|=4;
            if (s[i][j-1]=='*') msk|=8;
            dp[i][j][1][msk]=true;
        }
    }
    for (int len=2;(1<<len)<=min(n,m);++len) {
        for (int i=(1<<len);i<=n;++i) {
            for (int j=(1<<len);j<=m;++j) {
                for (int msk=0;msk<16;++msk) {
                    int k=(1<<(len-1));
                    bool q[5];
                    for (int z=0;z<4;++z)
                        q[z]=0;
                    q[0]=f1(i-k,j-k,k);
                    q[1]=f1(i-k,j,k);
                    q[2]=f1(i,j-k,k);
                    q[3]=f1(i,j,k);
                    if ((msk&1)) {
                        if (!q[0]) continue;
                    } else {
                        if (!dp[i-k][j-k][len-1][msk]) continue;
                    }

                    if ((msk&2)) {
                        if (!q[1]) continue;
                    } else {
                        if (!dp[i-k][j][len-1][msk]) continue;
                    }

                    if ((msk&4)) {
                        if (!q[2]) continue;
                    } else {
                        if (!dp[i][j-k][len-1][msk]) continue;
                    }

                    if ((msk&8)) {
                        if (!q[3]) continue;
                    } else {
                        if (!dp[i][j][len-1][msk]) continue;
                    }
                    ++ans;
                    dp[i][j][len][msk]=true;
                }
            }
        }
    }
    cout<<ans;
}