#include<bits/stdc++.h>
using namespace std;
int T,n,X,a[200010],C[40];
void solve(){
    map<int,vector<int> > mp;
    scanf("%d %d",&n,&X);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int cnt=0;
        while(a[i]%X==0) a[i]/=X,cnt++;
        mp[a[i]].push_back(cnt);
    }
    int ans=n;
    for(auto vec:mp){
        memset(C,0,sizeof(C));
        for(auto t:vec.second) C[t]++;
        while(1){
            int maxn=0,maxx=-1;
            for(int i=0;i<=35;i++){
                if(min(C[i],C[i+1])>maxn){
                    maxn=min(C[i],C[i+1]);
                    maxx=i;
                }
            }
            if(!maxn) break;
            C[maxx]--;C[maxx+1]--;ans-=2;
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}