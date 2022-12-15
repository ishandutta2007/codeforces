#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
char s[2005][2005];
int pre[2][2005][2005],cnt[2005][2005];
int main() {
    int T = 1;
    //cin >> T;
    while(T--) {
        int n,k,ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                pre[0][i][j]=pre[0][i][j-1]+(s[i][j]=='B');
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                pre[1][i][j]=pre[1][i-1][j]+(s[i][j]=='B');
        for(int i=1;i<=n-k+1;i++){
            int temp=0;
            for(int j=1;j<=k;j++){
                if(pre[1][i-1][j]+pre[1][n][j]-pre[1][i+k-1][j]==0&&pre[1][n][j]) temp++;
            }
            cnt[i][1]+=temp;
            for(int j=k+1;j<=n;j++){
                if(pre[1][i-1][j]+pre[1][n][j]-pre[1][i+k-1][j]==0&&pre[1][n][j]) temp++;
                if(pre[1][i-1][j-k]+pre[1][n][j-k]-pre[1][i+k-1][j-k]==0&&pre[1][n][j-k]) temp--;
                cnt[i][j-k+1]+=temp;
            }
        }
        for(int i=1;i<=n-k+1;i++){
            int temp=0;
            for(int j=1;j<=k;j++){
                if(pre[0][j][i-1]+pre[0][j][n]-pre[0][j][i+k-1]==0&&pre[0][j][n]) temp++;
            }
            cnt[1][i]+=temp;
            ans=max(ans,cnt[1][i]);
            for(int j=k+1;j<=n;j++){
                if(pre[0][j][i-1]+pre[0][j][n]-pre[0][j][i+k-1]==0&&pre[0][j][n]) temp++;
                if(pre[0][j-k][i-1]+pre[0][j-k][n]-pre[0][j-k][i+k-1]==0&&pre[0][j-k][n]) temp--;
                cnt[j-k+1][i]+=temp;
                ans=max(ans,cnt[j-k+1][i]);
            }
        }
        /*
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=n;j++)
                cout<<cnt[i][j];
                */
        for(int i=1;i<=n;i++){
            int f=1;
            for(int j=1;j<=n;j++) if(s[i][j]=='B') f=0;
            ans+=f;
            f=1;
            for(int j=1;j<=n;j++) if(s[j][i]=='B') f=0;
            ans+=f;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//