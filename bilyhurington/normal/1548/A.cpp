#include<bits/stdc++.h>
using namespace std;
int n,m,q,cnt[200010];
int main(){
    scanf("%d %d",&n,&m);
    int ans=0;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d %d",&x,&y);
        if(x>y) swap(x,y);
        cnt[x]++;
        if(cnt[x]==1) ans++;
    }
    scanf("%d",&q);
    for(int ti=1,opt,x,y;ti<=q;ti++){
        scanf("%d",&opt);
        if(opt==3){
            printf("%d\n",n-ans);
        }else{
            scanf("%d %d",&x,&y);
            if(x>y) swap(x,y);
            if(opt==1){
                cnt[x]++;
                if(cnt[x]==1) ans++;
            }else{
                cnt[x]--;
                if(!cnt[x]) ans--;
            }
        }
    }
    return 0;
}