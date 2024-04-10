#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[301][301];
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
int n,m;
bool inbounds(int x, int y){
    if(x>=1&&y>=1&&x<=n&&y<=m)return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool work=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
                int am=0;
                for(int k=0;k<4;k++)if(inbounds(i+xc[k],j+yc[k]))am++;
                if(arr[i][j]>am)work=false;
                arr[i][j]=am;
            }
        }
        if(!work)printf("NO\n");
        else{
            printf("YES\n");
            for(int i=1;i<=n;i++) {
                for (int j = 1; j <= m; j++) {
                    printf("%d\n",arr[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}