#include<bits/stdc++.h>
using namespace std;
int T,n,val[10010];bool vis[10010];
void solve(){
    scanf("%d",&n);int tot=0;
    for(int i=1;i<=n;i++) val[i]=-1,vis[i]=0;
    for(int i=1;i<=n;i++){
        if(val[i]!=-1) continue;
        vector<int> vec;int x;
        do{
            printf("? %d\n",i);
            fflush(stdout);scanf("%d",&x);
            if(vis[x]) break;
            vec.push_back(x);vis[x]=1;
        }while(1);val[vec.back()]=vec[0];
        for(int i=1;i<vec.size();i++) val[vec[i-1]]=vec[i];
    }printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",val[i]);puts("");fflush(stdout);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}