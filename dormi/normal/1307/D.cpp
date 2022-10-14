#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> spec;
vector<int> matrix[MAXN];
int dist[2][MAXN];
vector<pii> spd[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        spec.push_back(a);
    }
    for(int i=1;i<=n;i++){
        dist[0][i]=INT_MAX;
        dist[1][i]=INT_MAX;
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    int ans=0;
    for(int t=0;t<2;t++){
        int f=(t==0?1:n);
        dist[t][f]=0;
        queue<int> q;
        q.push(f);
        while(sz(q)){
            int cur=q.front();
            q.pop();
            for(int x:matrix[cur]){
                if(dist[t][cur]+1<dist[t][x]){
                    dist[t][x]=dist[t][cur]+1;
                    q.push(x);
                }
            }
        }
    }
    sort(spec.begin(),spec.end(),[&](int lhs, int rhs){
       if(dist[0][lhs]==dist[0][rhs])return lhs<rhs;
       return dist[0][lhs]<dist[0][rhs];
    });

    set<pii> final;
    for(int x:spec){
        final.insert({dist[1][x],x});
    }
    for(int x:spec){
        final.erase({dist[1][x],x});
        if(sz(final))ans=max(ans,dist[0][x]+1+final.rbegin()->first);
    }
    ans=min(ans,dist[0][n]);
//    if(spd[0][0].second==spd[1][0].second){
//        printf("%d\n",min(ans,max(spd[0][0].first+spd[1][1].first+1,spd[0][1].first+spd[1][0].first+1)));
//    }
//    else{
        printf("%d\n",ans);
  //  }
    return 0;
}