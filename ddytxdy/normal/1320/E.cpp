    #include<bits/stdc++.h>
    #define pb push_back
    using namespace std;
    const int N=4e5+50,inf=0x3f3f3f3f;
    int n,q,f[N],sz[N],tp[N],d[N],dfn[N],clk,k,m,vir[N],spd[N],cit[N],c[N],tt,st[N],tpp,ss[N],pp;
    int id[N],tim[N],rem[N];
    vector<int>e[N];
    int rd(){
        int x=0,c;
        while(!isdigit(c=getchar()));
        while(isdigit(c))x=x*10+c-48,c=getchar();
        return x;
    }
    void dfs1(int x){
        if(f[x])e[x].erase(find(e[x].begin(),e[x].end(),f[x]));
        sz[x]=1;
        for(int i=0,y;i<e[x].size();i++){
            f[y=e[x][i]]=x;d[y]=d[x]+1;dfs1(y),sz[x]+=sz[y];
            sz[y]>sz[e[x][0]]?swap(e[x][i],e[x][0]),0:0;
        }
    }
    void dfs2(int x){
        dfn[x]=++clk;
        for(int i=0;i<e[x].size();i++)
            tp[e[x][i]]=i?e[x][i]:tp[x],
            dfs2(e[x][i]);
    }
    int lca(int x,int y){
        for(;tp[x]!=tp[y];x=f[tp[x]])
            if(d[tp[x]]<d[tp[y]])swap(x,y);
        return d[x]<d[y]?x:y;
    }
    bool cmp(int x,int y){return dfn[x]<dfn[y];}
    void extend(int x){
        int y=lca(x,st[tpp]);
        while(tpp>1&&d[st[tpp-1]]>=d[y]){
            e[st[tpp]].pb(st[tpp-1]);
            e[st[tpp-1]].pb(st[tpp]);
            tpp--;
        }
        if(st[tpp]!=y)
            e[y].pb(st[tpp]),e[st[tpp]].pb(y),st[tpp]=y;
        st[++tpp]=x;
    }
    void update(int x,int y){
        if(tim[y]>tim[x]||tim[y]==inf)return;
        int dis=abs(d[y]-d[x]),t=tim[y]+(rem[y]<dis?(dis-rem[y]+spd[id[y]]-1)/spd[id[y]]:0);
        if(t<tim[x]||id[y]<id[x]&&t==tim[x]){
            tim[x]=t;id[x]=id[y];
            rem[x]=t>tim[y]?(t-tim[y])*spd[id[y]]-(dis-rem[y]):rem[y]-dis;
        }
    }
    void up(int x,int ff){
        ss[++pp]=x;
        if(ff)e[x].erase(find(e[x].begin(),e[x].end(),ff));
        for(int i=0,y;i<e[x].size();i++)up(y=e[x][i],x),update(x,y);
    }
    void down(int x){
        for(int i=0,y;i<e[x].size();i++)update(y=e[x][i],x),down(y);
    }
    int main(){
        n=rd();
        for(int i=1,x,y;i<n;i++)x=rd(),y=rd(),e[x].pb(y),e[y].pb(x);
        dfs1(1);tp[1]=1;dfs2(1);q=rd();
        for(int i=1;i<=n;i++)e[i].clear();
        memset(tim,0x3f,sizeof(tim));
        for(int i=1;i<=q;i++){
            k=rd();m=rd();c[tt=1]=1;
            for(int j=1;j<=k;j++)
                c[++tt]=vir[j]=rd(),spd[j]=rd();
            for(int j=1;j<=m;j++)c[++tt]=cit[j]=rd();
            sort(c+1,c+tt+1,cmp);tt=unique(c+1,c+tt+1)-c-1;
            st[tpp=1]=1;for(int j=2;j<=tt;j++)extend(c[j]);
            while(tpp>1)e[st[tpp]].pb(st[tpp-1]),e[st[tpp-1]].pb(st[tpp]),tpp--;
            for(int j=1;j<=k;j++)tim[vir[j]]=0,id[vir[j]]=j,rem[vir[j]]=0;
            up(1,0);down(1);
            for(int j=1;j<=m;j++)printf("%d%c",id[cit[j]]," \n"[j==m]);
            while(pp)e[ss[pp]].clear(),tim[ss[pp--]]=inf;
        }
        return 0;  
    }