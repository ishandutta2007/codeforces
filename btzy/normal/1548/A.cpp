#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=200000;
int numhigher[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int ans=n;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        int sm=min(u,v);
        --sm;
        if(numhigher[sm]++==0){
            --ans;
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int tc,u,v;
        cin>>tc;
        switch(tc){
        case 1:{
            cin>>u>>v;
            int sm=min(u,v);
            --sm;
            if(numhigher[sm]++==0){
                --ans;
            }
            break;
        }
        case 2:{
            cin>>u>>v;
            int sm=min(u,v);
            --sm;
            if(--numhigher[sm]==0){
                ++ans;
            }
            break;
        }
        case 3:
            cout<<ans<<'\n';
            break;
        }
    }
}