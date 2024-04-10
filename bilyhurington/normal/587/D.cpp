/*
 * @Author: BilyHurington
 * @Date: 2020-09-07 19:50:26
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-08 13:52:16
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,ed[50010][4];
vector<pair<int,int> > vec;
vector<int> G[50010];
int node_tot,pre[50010],suf[50010];
void Add_Node_Set(const vector<int> &E){
    if(!E.size()) return;
    for(int i=0;i<E.size();i++) pre[i]=++node_tot;
    for(int i=0;i<E.size();i++) suf[i]=++node_tot;
    vec.push_back(make_pair(pre[0],E[0]+m));
    for(int i=1;i<E.size();i++){
        vec.push_back(make_pair(pre[i],pre[i-1]));
        vec.push_back(make_pair(pre[i],E[i]+m));
    }
    vec.push_back(make_pair(suf[E.size()-1],E.back()+m));
    for(int i=0;i+1<E.size();i++){
        vec.push_back(make_pair(suf[i],suf[i+1]));
        vec.push_back(make_pair(suf[i],E[i]+m));
    }
    for(int i=0;i<E.size();i++){
        if(i>0) vec.push_back(make_pair(E[i],pre[i-1]));
        if(i+1<E.size()) vec.push_back(make_pair(E[i],suf[i+1]));
    }
    // for(int i=0;i<E.size();i++){
    //     for(int j=0;j<E.size();j++){
    //         if(i!=j) vec.push_back(make_pair(E[i],E[j]+m));
    //     }
    // }
}
void Add_Color_Set(const vector<int> &E){
    if(!E.size()) return;
    for(int i=0;i<E.size();i++) pre[i]=++node_tot;
    for(int i=0;i<E.size();i++) suf[i]=++node_tot;
    vec.push_back(make_pair(pre[0],E[0]));
    for(int i=1;i<E.size();i++){
        vec.push_back(make_pair(pre[i],pre[i-1]));
        vec.push_back(make_pair(pre[i],E[i]));
    }
    vec.push_back(make_pair(suf[E.size()-1],E.back()));
    for(int i=0;i+1<E.size();i++){
        vec.push_back(make_pair(suf[i],suf[i+1]));
        vec.push_back(make_pair(suf[i],E[i]));
    }
    for(int i=0;i<E.size();i++){
        if(i>0) vec.push_back(make_pair(E[i]+m,pre[i-1]));
        if(i+1<E.size()) vec.push_back(make_pair(E[i]+m,suf[i+1]));
    }
    // for(int i=0;i<E.size();i++){
    //     for(int j=0;j<E.size();j++){
    //         if(i!=j) vec.push_back(make_pair(E[i]+m,E[j]));
    //     }
    // }
}
vector<int> v[500010];
int dfn[500010],low[500010],col[500010],tot,col_tot;
bool instack[500010];
stack<int> sta;
void Tarjan(int x){
    dfn[x]=low[x]=++tot;
    sta.push(x);instack[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(!dfn[v[x][i]]){
            Tarjan(v[x][i]);
            low[x]=min(low[x],low[v[x][i]]);
        }
        else if(instack[v[x][i]]) low[x]=min(low[x],dfn[v[x][i]]);
    }
    if(dfn[x]==low[x]){
        ++col_tot;
        while(sta.top()!=x){
            col[sta.top()]=col_tot;
            instack[sta.top()]=0;
            sta.pop();
        }
        sta.pop();
        col[x]=col_tot;
        instack[x]=0;
    }
}
bool check(int Mid){
    // printf("CHECK: %d\n",Mid);
    tot=col_tot=0;
    for(int i=1;i<=node_tot;i++){
        v[i].clear();
        dfn[i]=low[i]=col[i]=instack[i]=0;
    }
    for(int i=0;i<vec.size();i++){
        v[vec[i].first].push_back(vec[i].second);
        // printf("%d %d\n",vec[i].first,vec[i].second);
    }
    for(int i=1;i<=m;i++){
        if(ed[i][3]>Mid) v[i].push_back(i+m);//printf("%d %d\n",i,i+m);
    } 
    for(int i=1;i<=node_tot;i++){
        if(!dfn[i]) Tarjan(i);
    }
    // for(int i=1;i<=2*m;i++) printf("%d\n",col[i]);
    for(int i=1;i<=m;i++){
        if(col[i]==col[i+m]) return 0;
    }
    // puts("YES");
    return 1;
}
int main(){
    scanf("%d %d",&n,&m);node_tot=2*m;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&ed[i][0],&ed[i][1],&ed[i][2],&ed[i][3]);
        G[ed[i][0]].push_back(i);
        G[ed[i][1]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        map<int,vector<int> > mp;
        for(int j=0;j<G[i].size();j++){
            mp[ed[G[i][j]][2]].push_back(G[i][j]);
        }
        Add_Node_Set(G[i]);
        for(pair<int,vector<int> > v:mp) Add_Color_Set(v.second);
    }
    int l=0,r=1.01e9,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l>1e9) printf("No");
    else{
        puts("Yes");
        check(l);
        vector<int> Ans;
        for(int i=1;i<=m;i++) if(col[i]<col[i+m]){
            Ans.push_back(i);
        }
        printf("%d %d\n",l,Ans.size());
        for(int i=0;i<Ans.size();i++) printf("%d ",Ans[i]);
    }
    return 0;
}