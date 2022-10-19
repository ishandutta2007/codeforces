#include<bits/stdc++.h>
using namespace std;
int T,n,d[1010];
int col[1010],tot;
void solve(){
    scanf("%d",&n);tot=0;
    for(int i=1;i<=n;i++) col[i]=0;
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    while(1){
        int maxx=0;d[0]=-1;
        for(int i=1;i<=n;i++){
            if(col[i]) continue;
            if(d[i]>d[maxx]) maxx=i;
        }
        if(!maxx) break;
        vector<int> nd;
        nd.push_back(maxx);
        for(int i=1;i<=d[maxx];i++){
            printf("? %d\n",maxx);
            fflush(stdout);
            int x;scanf("%d",&x);
            if(col[x]){col[maxx]=col[x];break;}
            else nd.push_back(x);
        }
        if(col[maxx]){
            for(auto x:nd) col[x]=col[maxx];
        }else{
            ++tot;
            for(auto x:nd) col[x]=tot;
        }
    }
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",col[i]);
    puts("");fflush(stdout);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}