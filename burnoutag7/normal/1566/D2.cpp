#include<bits/stdc++.h>
using namespace std;

int n,m,a[305][305],val[305][305],ass[305][305];
map<int,int> mp;
map<int,set<pair<int,pair<int,int>>>> st;

void mian(){
    cin>>n>>m;
    mp.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            mp[a[i][j]]++;
            val[i][j]=m-j;
        }
    }
    st.clear();
    {
        int cx=1,cy=1;
        for(auto [x,y]:mp){
            while(y--){
                if(!y||cy==m)st[x].emplace(val[cx][cy],make_pair(cx,cy));
                ass[cx][cy]=x;
                cy++;
                if(cy>m){
                    cy=1;
                    cx++;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=st[a[i][j]].begin()->second.first,y=st[a[i][j]].begin()->second.second;
            st[a[i][j]].erase(st[a[i][j]].begin());
            for(int k=1;k<y;k++){
                val[x][k]--;
            }
            if(ass[x][y-1]==a[i][j]){
                st[a[i][j]].emplace(val[x][y-1],make_pair(x,y-1));
            }
            ans+=val[x][y];
        }
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}