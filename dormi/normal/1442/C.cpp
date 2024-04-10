#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const int MAXN=2e5+1;
const int MAXT=31;
ll val[2*MAXN];
int conver(int a){
    if(a<=MAXT)return a;
    if(a%2==0)return MAXT+1;
    return MAXT+2;
}
struct DISTANCE{
    ll dis;
    int trans;
    DISTANCE(){dis=0,trans=0;}
    bool operator<(const DISTANCE &a) const{
        if(trans>MAXT||a.trans>MAXT){
            if(a.trans==trans)return dis<a.dis;
            return trans<a.trans;
        }
        return dis+val[trans]<a.dis+val[a.trans];
    }
};
vector<pii> matrix[MAXN];
DISTANCE dist[MAXN][MAXT+3];
int main(){// idea is that after log(n) transpositions, paths which take more transpositions will always be longer.
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    val[0]=0;
    for(int i=1;i<2*MAXN;i++){
        val[i]=(val[i-1]*2LL+1LL)%mod;//should wa
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<MAXT+3;j++){
            dist[i][j].trans=INT_MAX;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].push_back({b,0});
        matrix[b].push_back({a,1});
    }
    priority_queue<pair<DISTANCE,int>,vector<pair<DISTANCE,int>>,greater<>> q;
    dist[1][0]=DISTANCE();
    q.push({DISTANCE(),1});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(!(dist[cur.second][conver(cur.first.trans)]<cur.first)){
            for(auto x:matrix[cur.second]){
                if(x.second==cur.first.trans%2){
                    DISTANCE ne=cur.first;
                    ne.dis+=1;
                    if(ne<dist[x.first][conver(cur.first.trans)]){
                        dist[x.first][conver(cur.first.trans)]=ne;
                        q.push({ne,x.first});
                    }
                }
            }
            DISTANCE ne=cur.first;
            ne.trans+=1;
            if(ne<dist[cur.second][conver(ne.trans)]){
                dist[cur.second][conver(ne.trans)]=ne;
                q.push({ne,cur.second});
            }
        }
    }
    DISTANCE ans=DISTANCE();
    ans.trans=INT_MAX;
    for(int i=0;i<MAXT+3;i++){
        if(dist[n][i]<ans){
            ans=dist[n][i];
        }
    }
    assert(ans.trans!=INT_MAX);
    printf("%lli\n",(ans.dis+val[ans.trans])%mod);
    return 0;
}