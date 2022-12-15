#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[2005],pre[2005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        int mx=n;
        for(int i=1;i<=n;i++){
            int s=0,cnt=0,len=0,lst=0;
            for(int j=1;j<=i;j++) s+=a[j];
            for(int j=1;j<=n;j++) if(pre[j]%s==0) cnt++,len=max(len,j-lst),lst=j;
            if(pre[n]%s==0&&cnt==pre[n]/s){
                mx=min(len,mx);
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}