#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
char arr[1001][1001];
int dist[1001][1001];
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            dist[i][j]=-1;
        }
    }
    set<pii> qute;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                pii ne={i+xc[k],j+yc[k]};
                if(ne.first>=0&&ne.first<n&&ne.second>=0&&ne.second<m){
                    if(arr[ne.first][ne.second]==arr[i][j]){
                        qute.insert({i,j});
                        qute.insert(ne);
                        dist[i][j]=0;
                        dist[ne.first][ne.second]=0;
                    }
                }
            }
        }
    }
    queue<pii> q;
    for(auto x:qute)q.push(x);
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            pii ne={cur.first+xc[k],cur.second+yc[k]};
            if(ne.first>=0&&ne.first<n&&ne.second>=0&&ne.second<m) {
                if(dist[ne.first][ne.second]==-1){
                    dist[ne.first][ne.second]=dist[cur.first][cur.second]+1;
                    q.push(ne);
                }
            }
        }
    }
    int a,b;
    ll c;
    while(t--){
        cin>>a>>b>>c;
        a-=1,b-=1;
        if(dist[a][b]<c&&dist[a][b]!=-1){
            if((c-dist[a][b])%2){
                if(arr[a][b]=='1')printf("0\n");
                else printf("1\n");
            }
            else printf("%c\n",arr[a][b]);
        }
        else printf("%c\n",arr[a][b]);
    }
    return 0;
}