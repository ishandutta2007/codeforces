#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,vector<int> > P[100010];
namespace Trie{
    map<int,int> mp[3200010];
    int cnt[3200010],tot=1;
    int nxtnd(int x,int t){
        if(mp[x].find(t)==mp[x].end()){
            mp[x][t]=++tot;
            return tot;
        }else return mp[x][t];
    }
    void Add(const vector<int> &V,int ad,int x=1,int dep=0){
        if(dep==m){cnt[x]+=ad;return;}
        Add(V,ad,x,dep+1);
        Add(V,ad,nxtnd(x,V[dep]),dep+1);
    }
    int Count(const vector<int> &V,int x=1,int dep=0){
        if(dep==m) return cnt[x];
        int ans=Count(V,x,dep+1);
        if(mp[x].find(V[dep])!=mp[x].end()){
            ans-=Count(V,mp[x][V[dep]],dep+1);
        }return ans;
    }
}
using Trie::Add;
using Trie::Count;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        P[i].second.resize(m);
        for(int j=0;j<m;j++) scanf("%d",&P[i].second[j]);
        scanf("%d",&P[i].first);
        sort(P[i].second.begin(),P[i].second.end());
    }sort(P+1,P+n+1);
    int L,R=1;
    while(R<=n&&!Count(P[R].second)){
        Add(P[R].second,1);
        R++;
    }
    if(R==n+1){puts("-1");return 0;}
    L=R;
    while(Count(P[R].second)>0){
        L--;
        Add(P[L].second,-1);
    }
    int ans=P[L].first+P[R].first;
    for(++R;R<=n;R++){
        while(Count(P[R].second)>0){
            L--;
            Add(P[L].second,-1);
        }
        if(!L) break;
        ans=min(ans,P[L].first+P[R].first);
    }printf("%d\n",ans);
    return 0;
}