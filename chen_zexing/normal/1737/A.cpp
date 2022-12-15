#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[205];
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        int cnt[26]={};
        for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
        for(int i=1;i<=k;i++){
            int f=1;
            for(int j=1,now=0;j<=min(n/k,25);j++){
                if(!cnt[now]){
                    printf("%c",now+'a'),f=0;
                    break;
                }
                else cnt[now]--,now++;
            }
            if(f) printf("%c",n/k+'a');
        }
        puts("");
    }
    return 0;
}