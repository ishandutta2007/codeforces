#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[1005][1005];
int nowx[1005],nowy[1005];
int ans[1005][1005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k,fl=1;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ans[i][j]=1;
        for(int i=1;i<=n;i++) nowx[i]=nowy[i]=0;
        for(int i=1;i<=n-k+1&&fl;i++){
            while(nowx[1]<=n&&(nowx[1]<=max(nowx[2],nowy[2])||s[nowx[1]][nowx[1]]=='0')) nowx[1]++;
            if(nowx[1]>n){
                fl=0;
                break;
            }
            nowy[1]=nowx[1];
            ans[nowx[1]][nowx[1]]=0;
            for(int j=2;j<=n-k+1-i+1;j++){
                while(nowx[j]<=n-j+1&&(nowx[j]<nowx[j-1]||nowx[j]<=nowx[j+1]||s[nowx[j]][nowx[j]+j-1]=='0')) nowx[j]++;
                if(nowx[j]>n-j+1){
                    fl=0;
                    break;
                }
                ans[nowx[j]][nowx[j]+j-1]=0;
            }
            if(!fl) break;
            for(int j=2;j<=n-k+1-i+1;j++){
                while(nowy[j]<=n-j+1&&(nowy[j]<nowy[j-1]||nowy[j]<=nowy[j+1]||s[nowy[j]+j-1][nowy[j]]=='0')) nowy[j]++;
                if(nowy[j]>n-j+1){
                    fl=0;
                    break;
                }
                ans[nowy[j]+j-1][nowy[j]]=0;
            }
        }
        if(!fl) puts("NO");
        else{
            puts("YES");
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=n;j++)
                    printf("%d",ans[i][j]);
        }
    }
    return 0;
}