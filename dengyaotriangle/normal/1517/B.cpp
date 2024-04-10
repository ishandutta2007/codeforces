#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=105;

int a[maxn][maxn];
int n,m;
vector<int> v2[maxn];
int ans[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<pair<int,pair<int,int> > > vec;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>a[i][j],vec.push_back({a[i][j],{i,j}});
        }
        sort(vec.begin(),vec.end());
        for(int i=1;i<=n;i++)v2[i].clear();
        for(int i=m;i<m*n;i++){
            v2[vec[i].second.first].push_back(vec[i].first);
        }
        for(int i=0;i<m;i++){
            int cx=vec[i].second.first,cy=vec[i].second.second;
            for(int j=1;j<=n;j++){
                if(j!=cx){
                    ans[i][j]=v2[j].back();v2[j].pop_back();
                }else ans[i][j]=vec[i].first;
            }
        }
        for(int i=1;i<=n;i++)for(int j=0;j<m;j++)cout<<ans[j][i]<<" \n"[j==m-1];
    }
    return 0;
}