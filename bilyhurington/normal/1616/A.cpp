#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<=100;i++) cnt[i]=0;
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            cnt[abs(x)]++;
        }int ans=0;if(cnt[0]) ans++;
        for(int i=1;i<=100;i++) ans+=min(2,cnt[i]);
        printf("%d\n",ans);
    }
    return 0;
}