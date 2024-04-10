#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[1005][1005];
int ans[1005][1005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ans[i][j]=0;
        for(int i=1;i<=n;i++) ans[i][i]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(s[i][j]=='1')
                    ans[j][i]=1;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=n;j++) cnt+=ans[i][j];
            printf("%d ",cnt);
            for(int j=1;j<=n;j++) if(ans[i][j]) printf("%d ",j);
            puts("");
        }
    }
    return 0;
}