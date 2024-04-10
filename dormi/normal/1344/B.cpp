#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
char arr[1001][1001];
bool gone[1001][1001];
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int rc=0;
    for(int i=0;i<n;i++){
        char last='.';
        int am=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]=='#'&&last=='.')am++;
            last=arr[i][j];
        }
        if(am>1){
            printf("-1\n");
            return 0;
        }
        if(am==0){
            rc++;
        }
    }
    int cc=0;
    for(int i=0;i<m;i++){
        char last='.';
        int am=0;
        for(int j=0;j<n;j++){
            if(arr[j][i]=='#'&&last=='.')am++;
            last=arr[j][i];
        }
        if(am>1){
            printf("-1\n");
            return 0;
        }
        if(am==0){
            cc++;
        }
    }
    if((rc>0&&cc==0)||(cc>0&&rc==0)){
        printf("-1\n");
        return 0;
    }
    int need=0;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j]=='#'&&!gone[i][j]){
                need++;
                queue<pii> q;
                q.push({i,j});
                gone[i][j]=true;
                while(sz(q)){
                    auto cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        pii ne={cur.first+xc[k],cur.second+yc[k]};
                        if(ne.first>=0&&ne.first<n&&ne.second>=0&&ne.second<m){
                            if(!gone[ne.first][ne.second]&&arr[ne.first][ne.second]=='#'){
                                gone[ne.first][ne.second]=true;
                                q.push(ne);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",need);
    return 0;
}