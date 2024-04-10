#include<bits/stdc++.h>
using namespace std;
int T,n,f[500010],cnt[110];
char s[500010];
int main(){
    scanf("%d",&T);
    for(int i=1;i<=1000;i++){
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<=i-2;j++){
            cnt[f[j]^f[i-2-j]]=1;
        }
        while(cnt[f[i]]) f[i]++;
        // printf("%d\n",f[i]);
    }
    for(int i=101;i<=500000;i++) f[i]=f[i-34];
    while(T--){int ans=0;
        scanf("%d %s",&n,s+1);
        int cnt0=0;
        for(int i=1;i<=n;i++) if(s[i]=='B') cnt0++;
        if(cnt0*2<n){puts("Alice");continue;}
        if(cnt0*2>n){puts("Bob");continue;}
        for(int i=1,j;i<=n;i=j+1){
            for(j=i;j<n&&s[j+1]!=s[j];j++);
            ans^=f[j-i+1];
        }
        puts(ans?"Alice":"Bob");
    }
    return 0;
}