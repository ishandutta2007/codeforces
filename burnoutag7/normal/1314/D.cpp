#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int d[85][85];
vector<pair<int,int>> pre[85][85];
int spec[10],tsp;
int u[85];

int check(){
    int res=0;
    for(int i=1;i<tsp;i++){
        vector<pair<int,int>> &cur=pre[spec[i]][spec[i+1]];
        bool fail=1;
        for(int j=0;j<cur.size();j++){
            if(!u[cur[j].second]){
                res+=cur[j].first;
                fail=0;
                break;
            }
        }
        if(fail)return 1e9;
    }
    return res;
}

void gen(int dep){
    if(dep==tsp){
        ans=min(ans,check());
        return;
    }
    for(int i=1;i<=n;i++){
        u[i]++;
        spec[dep]=i;
        gen(dep+1);
        u[i]--;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;tsp=(k>>1)+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i!=k&&j!=k)pre[i][j].emplace_back(d[i][k]+d[k][j],k);
            }
            sort(pre[i][j].begin(),pre[i][j].end());
        }
    }
    u[1]=2;
    spec[1]=spec[tsp]=1;
    ans=1e9;
    gen(2);
    cout<<ans<<endl;

    return 0;
}