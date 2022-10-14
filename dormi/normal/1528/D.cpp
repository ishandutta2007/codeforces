#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=601;
int dist[MN];
bool used[MN];
int arr[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)arr[i][j]=INT_MAX;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        arr[a][b]=c;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)dist[j]=INT_MAX,used[j]=false;
        dist[i]=0;
        for(int level=1;level<n;level++){
            int cur=-1;
            for(int j=0;j<n;j++){
                if(!used[j]&&(cur==-1||dist[j]<dist[cur]))cur=j;
            }
            used[cur]=true;
            int mi=INT_MAX;
            for(int j=0;j<n;j++)if(arr[cur][(j-dist[cur]%n+n)%n]!=INT_MAX)mi=min(mi,arr[cur][(j-dist[cur]%n+n)%n]+n-1-j);
            for(int j=0;j<n;j++){
                mi=min(mi+1,arr[cur][(j-dist[cur]%n+n)%n]);
                dist[j]=min(dist[j],dist[cur]+mi);
            }
        }
        for(int j=0;j<n;j++)printf("%d%c",dist[j]," \n"[j==n-1]);
    }
    return 0;
}