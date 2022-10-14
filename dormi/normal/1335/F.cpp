#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<vector<char>> col;
vector<vector<char>> arr;
vector<vector<pii>> identity;
int curind=0;
vector<vector<vector<pii>>> paths;
vector<pii> path;
pii nxts(pii a){
    if(arr[a.first][a.second]=='U')return {a.first-1,a.second};
    if(arr[a.first][a.second]=='R')return {a.first,a.second+1};
    if(arr[a.first][a.second]=='D')return {a.first+1,a.second};
    if(arr[a.first][a.second]=='L')return {a.first,a.second-1};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        paths.clear();
        curind=0;
        col.resize(n),arr.resize(n),identity.resize(n);
        for(int i=0;i<n;i++)col[i].resize(m),arr[i].resize(m),identity[i].resize(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>col[i][j];
                identity[i][j]={-1,-1};
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<n;i++) {
            for (int j = 0; j < m; j++) {
                if(identity[i][j].first==-1){
                    pii ne={i,j};
                    int dep=0;
                    path.clear();
                    while(identity[ne.first][ne.second].first==-1){
                        identity[ne.first][ne.second]={curind,dep};
                        path.push_back(ne);
                        ne=nxts(ne);
                        dep++;
                    }
                    int id=identity[ne.first][ne.second].first;
                    int ind=identity[ne.first][ne.second].second;
                    if(id==curind){
                        curind++;
                        int len=dep-ind;
                        paths.push_back({});
                        paths[id].resize(len);
                        for(int i=sz(path)-1;i>=ind;i--){
                            identity[path[i].first][path[i].second]={id,identity[path[i].first][path[i].second].second-ind};
                            paths[id][identity[path[i].first][path[i].second].second].push_back(path[i]);
                        }
                        int teind=0;
                        for(int i=ind-1;i>=0;i--){
                            teind=(teind-1+len)%len;
                            identity[path[i].first][path[i].second]={id,teind};
                            paths[id][teind].push_back(path[i]);
                        }
                    }
                    else{
                        int len=sz(paths[id]);
                        for(int i=sz(path)-1;i>=0;i--){
                            ind=(ind-1+len)%len;
                            identity[path[i].first][path[i].second]={id,ind};
                            paths[id][ind].push_back(path[i]);
                        }
                    }
                }
            }
        }
        int totam=0;
        int blam=0;
        for(auto x:paths){
            totam+=sz(x);
            for(auto y:x){
                for(auto cur:y){
                    if(col[cur.first][cur.second]=='0'){
                        blam++;
                        break;
                    }
                }
            }
        }
        printf("%d %d\n",totam,blam);
    }
    return 0;
}