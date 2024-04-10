#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 100000;
pair<int,int> arr[MAXN];
struct iffy{
    int ctrl;
    int height;
};
vector<int> adjlist[MAXN];
int score(int target, const vector<int>& points, int totalheight) {
    for(auto x : points) {
        totalheight+=abs(x-target);
    }
    return totalheight;
}
iffy max_iffy(iffy left, iffy right) {
    int llsweep=left.ctrl+left.height;
    int lrsweep=left.ctrl-left.height;
    int rlsweep=right.ctrl+right.height;
    int rrsweep=right.ctrl-right.height;
    int mlsweep=max(llsweep,rlsweep);
    int mrsweep=min(lrsweep,rrsweep);
    return {(mlsweep+mrsweep)/2, (mlsweep-mrsweep)/2};
}
pair<iffy,int> dfs(int index, int prev) {
    vector<int> points;
    int totalheight = 0;
    int pct=0;
    for(int x : adjlist[index]){
        if(x!=prev){
            auto [res, _] = dfs(x, index);
            points.push_back(res.ctrl);
            totalheight+=res.height;
            ++pct;
        }
    }
    /*int i;
    int ileft=pct,iright=pct;
    for(i=0;i<pct;++i){
        if(points[i]>=arr[i].first){
            ileft=i*2-pct;
            break;
        }
    }
    for(;i<pct;++i){
        if(points[i]>=arr[i].second){
            iright=i*2-pct;
            break;
        }
    }*/
    int lscore = score(arr[index].first, points, totalheight);
    int rscore = score(arr[index].second, points, totalheight);
    int ret_lb = max(lscore, rscore);
    iffy ret_iffy = max_iffy({arr[index].first,lscore}, {arr[index].second,rscore});
    //cout<<index<<' '<<ret_iffy.ctrl<<' '<<ret_iffy.height<<' '<<ret_lb<<endl;
    return {ret_iffy, ret_lb};
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i].first>>arr[i].second;
            arr[i].first*=2;
            arr[i].second*=2;
        }
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            --u;
            --v;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        auto [_, lb] = dfs(0, -1);
        cout<<lb/2<<'\n';
        for(int i=0;i<n;++i){
            adjlist[i].clear();
        }
    }
}