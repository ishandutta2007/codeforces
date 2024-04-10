#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char ans[505][505];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,k,r,c;
        scanf("%d%d%d%d",&n,&k,&r,&c);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ans[i][j]='.';
        while(c>k) c-=k;
        for(int i=1;i<=n;i++){
            int st=c-(r-i)%k;
            if(st<=0) st+=k;
            for(int j=1;j<=n;j++) if((j-st)%k==0) ans[i][j]='X';
        }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=n;j++)
                printf("%c",ans[i][j]);
    }
    return 0;
}