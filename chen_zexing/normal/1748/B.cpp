#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            int cnt[10]={},tot=0,mx=0;
            for(int j=i;j<=min(n,i+105);j++){
                if(!cnt[s[j]-'0']) tot++;
                cnt[s[j]-'0']++,mx=max(mx,cnt[s[j]-'0']);
                if(mx<=tot) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}