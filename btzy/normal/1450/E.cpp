#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=200;
vector<pair<int,int>> adjlist[MAXN]; // index, dir (0 if don't know)
int height[MAXN];
int n;
bool dfs(int index){
    if(height[index]>0)return false;
    for(auto [i,d] : adjlist[index]) {
        int newd=height[index];
        if(d==0)--newd;
        else newd+=d;
        if(newd>height[i]){
            height[i]=newd;
            if(!dfs(i))return false;
        }
        else if(newd<height[i]){
            if(height[index]>=height[i])return false;
            int newheight=height[i];
            if(d==0)--newheight;
            else newheight-=d;
            if(height[index]<newheight){
                height[index]=newheight;
                if(!dfs(index))return false;
            }
            /*if(height[index]<height[i]-1){
                height[index]=height[i]-1;
                if(!dfs(index))return false;
            }*/
        }
    }
    return true;
}
int simulate(int index){
    fill_n(height,n,-1000);
    height[index]=0;
    if (!dfs(index)) {
        return INT_MAX;
    }
    return *min_element(height,height+n);
}
int main(){
    ios_base::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    for(int e=0;e<m;++e){
        int i,j,b;
        cin>>i>>j>>b;
        --i;--j;
        if (b==0){
            adjlist[i].emplace_back(j,0);
            adjlist[j].emplace_back(i,0);
        }
        else {
            adjlist[i].emplace_back(j,1);
            adjlist[j].emplace_back(i,-1);
        }
    }
    int best=INT_MAX;
    int bestidx=-1;
    for(int i=0;i<n;++i){
        int res=simulate(i);
        if(res<best){
            best=res;
            bestidx=i;
        }
    }
    if(best==INT_MAX){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n"<<-best<<'\n';
        simulate(bestidx);
        for(int i=0;i<n;++i){
            if(i>0)cout<<' ';
            cout<<1000000+height[i];
        }
        cout<<'\n';
    }
}