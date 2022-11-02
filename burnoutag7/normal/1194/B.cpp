#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int sr[50005];
int sc[50005];
vector<int> g[50005];
int mr,mc,rp,cp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n>>m;
        memset(sr,0,sizeof(sr));
        memset(sc,0,sizeof(sc));
        mr=0;mc=0;
        for(int i=1;i<=n;i++){
            g[i].clear();
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='*'){
                    sr[i]++;
                    sc[j]++;
                    mr=max(mr,sr[i]);
                    mc=max(mc,sc[j]);
                }else{
                    g[i].push_back(j);
                }
            }
        }
        int ans=n-mr+m-mc;
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();j++){
                ans=min(ans,n-sr[i]+m-sc[g[i][j]]-1);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}