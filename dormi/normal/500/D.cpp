#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
pair<pii,double> roads[MAXN];
int depth[MAXN];
int dpdown[MAXN];
int dpup[MAXN];
void dfs(int loc, int parent, int dep){
    depth[loc]=dep;
    dpdown[loc]=1;
    for(int x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc,dep+1);
            dpdown[loc]+=dpdown[x];
        }
    }
}
void dfsu(int loc, int parent){
    if(loc!=1)dpup[loc]=dpup[parent]+dpdown[parent]-dpdown[loc];
    for(int x:matrix[loc]){
        if(x!=parent)dfsu(x,loc);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    double c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        roads[i]={{a,b},c};
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,0);
    dfsu(1,0);
    double ans=0;
    for(int i=1;i<n;i++){
        if(depth[roads[i].first.first]>depth[roads[i].first.second])swap(roads[i].first.first,roads[i].first.second);
        double upth=(dpup[roads[i].first.second]/(double)n)*((dpup[roads[i].first.second]-1)/(double)(n-1))*((dpup[roads[i].first.second]-2)/(double)(n-2));
        double downth=(dpdown[roads[i].first.second]/(double)n)*((dpdown[roads[i].first.second]-1)/(double)(n-1))*((dpdown[roads[i].first.second]-2)/(double)(n-2));
        ans+=(double)2*roads[i].second*((double)1-(upth+downth));
    }
    int q;
    cin>>q;
    while(q--){
        cin>>a>>c;
        double upth=(dpup[roads[a].first.second]/(double)n)*((dpup[roads[a].first.second]-1)/(double)(n-1))*((dpup[roads[a].first.second]-2)/(double)(n-2));
        double downth=(dpdown[roads[a].first.second]/(double)n)*((dpdown[roads[a].first.second]-1)/(double)(n-1))*((dpdown[roads[a].first.second]-2)/(double)(n-2));
        ans-=(double)2*roads[a].second*((double)1-(upth+downth));
        roads[a].second=c;
        upth=(dpup[roads[a].first.second]/(double)n)*((dpup[roads[a].first.second]-1)/(double)(n-1))*((dpup[roads[a].first.second]-2)/(double)(n-2));
        downth=(dpdown[roads[a].first.second]/(double)n)*((dpdown[roads[a].first.second]-1)/(double)(n-1))*((dpdown[roads[a].first.second]-2)/(double)(n-2));
        ans+=(double)2*roads[a].second*((double)1-(upth+downth));
        printf("%.6f\n",ans);
    }
    return 0;
}