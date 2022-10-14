#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=1001;
const int MAXV=41;
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
int arr[MAXN][MAXN];
int mi[MAXN][MAXN][MAXV];
int mic[MAXV][MAXV];
int dist[MAXV];
queue<pii> mbfs[MAXV];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        for(int l=1;l<=k;l++)mi[i][j][l]=1000001;
        cin>>arr[i][j];
        mbfs[arr[i][j]].push({i,j});
        mi[i][j][arr[i][j]]=0;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            mic[i][j]=1000001;
        }
        while(!mbfs[i].empty()){
            auto cur=mbfs[i].front();
            mbfs[i].pop();
            for(int j=0;j<4;j++){
                pii ne={cur.first+xc[j],cur.second+yc[j]};
                if(ne.first>=0&&ne.first<n&&ne.second>=0&&ne.second<m){
                    if(mi[cur.first][cur.second][i]+1<mi[ne.first][ne.second][i]){
                        mi[ne.first][ne.second][i]=mi[cur.first][cur.second][i]+1;
                        mbfs[i].push(ne);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int l=1;l<=k;l++){
        mic[arr[i][j]][l]=min(mic[arr[i][j]][l],mi[i][j][l]+1);
    }
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++)dist[j]=1000001;
        priority_queue<pii,vector<pii>,greater<pii>> q;
        q.push({0,i});
        dist[i]=0;
        while(!q.empty()){
            auto cur=q.top();
            q.pop();
            if(cur.first<=dist[cur.second]){
                for(int j=1;j<=k;j++){
                    if(cur.first+mic[cur.second][j]<dist[j]){
                        dist[j]=cur.first+mic[cur.second][j];
                        q.push({dist[j],j});
                    }
                }
            }
        }
        for(int j=1;j<=k;j++)mic[i][j]=min(mic[i][j],dist[j]);
    }
    int q;
    cin>>q;
    int a,b,c,d;
    while(q--){
        cin>>a>>b>>c>>d;
        a-=1,b-=1,c-=1,d-=1;
        int best=abs(c-a)+abs(d-b);
        for(int i=1;i<=k;i++){
            best=min(best,min(mi[a][b][i]+1,mic[arr[a][b]][i]+1)+mi[c][d][i]);
            for(int j=1;j<=k;j++){
                best=min(best,mi[a][b][j]+1+mic[j][i]+mi[c][d][i]);
            }
        }
        printf("%d\n",best);
    }
    return 0;
}