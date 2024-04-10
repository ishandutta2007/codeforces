#include<bits/stdc++.h>
using namespace std;
int n,m;bool rev;
vector<pair<int,int> > G1[200010],G2[200010];
bool cmp(pair<int,int> p1,pair<int,int> p2){return p1.second<p2.second;}
int col1[200010],siz1[200010],tot1;
void dfs1(int x,int c){
    col1[x]=c;
    if(x<=n) siz1[c]++;
    for(auto pr:G1[x]){
        int to=pr.first;
        if(col1[to]) continue;
        dfs1(to,c);
    }
}
int col2[200010],siz2[200010],tot2;
void dfs2(int x,int c){
    col2[x]=c;
    if(x<=n) siz2[c]++;
    for(auto pr:G2[x]){
        int to=pr.first;
        if(col2[to]) continue;
        dfs2(to,c);
    }
}
int pp[200010],ppi[200010];//G1 x G2 pp[x]
bool Vis1[200010],Vis2[200010];
vector<int> nd1,nd2;
bool matching(int x1,int x2){
    // printf("M %d %d\n",x1,x2);
    nd1.push_back(x1);Vis1[x1]=1;pp[x1]=x2;
    nd2.push_back(x2);Vis2[x2]=1;ppi[x2]=x1;
    if(G1[x1].size()!=G2[x2].size()) return 0;
    for(int i=0;i<G1[x1].size();i++){
        if(G1[x1][i].second!=G2[x2][i].second) return 0;
        if(Vis1[G1[x1][i].first]^Vis2[G2[x2][i].first]) continue;
        if(Vis1[G1[x1][i].first]){
            if(pp[G1[x1][i].first]!=G2[x2][i].first) return 0;
            else continue;
        }
        if(!matching(G1[x1][i].first,G2[x2][i].first)) return 0;
    }return 1;
}
vector<array<int,3> > Ans;
int main(){
    scanf("%d %d",&n,&m);
    if(n>m) rev=1;
    for(int i=1;i<=n;i++){
        for(int j=1,c;j<=m;j++){
            scanf("%d",&c);
            if(!c) continue;
            if(rev){
                G1[j].push_back({i+m,c});
                G1[i+m].push_back({j,c});
            }else{
                G1[i].push_back({j+n,c});
                G1[j+n].push_back({i,c});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1,c;j<=m;j++){
            scanf("%d",&c);
            if(!c) continue;
            if(rev){
                G2[j].push_back({i+m,c});
                G2[i+m].push_back({j,c});
            }else{
                G2[i].push_back({j+n,c});
                G2[j+n].push_back({i,c});
            }
        }
    }
    if(rev) swap(n,m);
    for(int i=1;i<=n+m;i++){
        sort(G1[i].begin(),G1[i].end(),cmp);
        sort(G2[i].begin(),G2[i].end(),cmp);
    }
    vector<int> v1,v2;
    for(int i=1;i<=n+m;i++){
        if(col1[i]) continue;
        dfs1(i,++tot1);
        if(!siz1[tot1]) v1.push_back(i);
    }
    for(int i=1;i<=n+m;i++){
        if(col2[i]) continue;
        dfs2(i,++tot2);
        if(!siz2[tot2]) v2.push_back(i);
    }
    if(v1.size()!=v2.size()){puts("-1");return 0;}
    // for(int i=1;i<=n+m;i++) printf("%d ",col1[i]);puts("");
    // for(int i=1;i<=n+m;i++) printf("%d ",col2[i]);puts("");
    for(int i=0;i<v1.size();i++) pp[v1[i]]=v2[i],ppi[v2[i]]=v1[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // printf("%d %d %d %d %d %d\n",i,pp[i],j,ppi[j],siz1[col1[i]],siz2[col2[j]]);
            if(pp[i]||ppi[j]||siz1[col1[i]]!=siz2[col2[j]]) continue;
            nd1.clear();nd2.clear();
            // printf("%d %d\n",i,j);
            if(!matching(i,j)){
                // printf("%d %d\n",i,j);
                for(auto x:nd1) Vis1[x]=pp[x]=0;
                for(auto x:nd2) Vis2[x]=ppi[x]=0;
            }
        }
    }
    for(int i=1;i<=n+m;i++) if(!pp[i]){puts("-1");return 0;}
    for(int i=1;i<=n+m;i++){
        while(i!=pp[i]){
            if(i<=n) Ans.push_back({1,i,pp[i]});
            else Ans.push_back({2,i-n,pp[i]-n});
            swap(pp[i],pp[pp[i]]);
        }
    }
    if(rev){
        printf("%d\n",(int)Ans.size());
        for(auto v:Ans) printf("%d %d %d\n",3-v[0],v[1],v[2]);
    }else{
        printf("%d\n",(int)Ans.size());
        for(auto v:Ans) printf("%d %d %d\n",v[0],v[1],v[2]);
    }
    return 0;
}