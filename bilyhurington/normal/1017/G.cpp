#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
pair<int,int> operator + (pair<int,int> p1,pair<int,int> p2){
    return make_pair(p1.first+p2.first,max(p2.second,p2.first+p1.second));
}
namespace Segment_Tree{
    int tag[400010];
    pair<int,int> sum[400010];
    void Build(int k,int l,int r){
        if(l==r){
            sum[k]=make_pair(-1,-1);
            return;
        }
        int mid=(l+r)>>1;
        Build(k<<1,l,mid);
        Build(k<<1|1,mid+1,r);
        sum[k]=sum[k<<1]+sum[k<<1|1];
    }
    void Push_Down(int k,int l,int r){
        if(!tag[k]) return;
        int mid=(l+r)>>1;
        sum[k<<1]=make_pair(-(mid-l+1),-1);
        sum[k<<1|1]=make_pair(-(r-mid),-1);
        tag[k]=0;tag[k<<1]=tag[k<<1|1]=-1;
    }
    void Modify(int k,int l,int r,int x,int ad){
        if(l==r){
            sum[k]=make_pair(sum[k].first+ad,sum[k].second+ad);
            return;
        }
        int mid=(l+r)>>1;
        Push_Down(k,l,r);
        if(x<=mid) Modify(k<<1,l,mid,x,ad);
        else Modify(k<<1|1,mid+1,r,x,ad);
        sum[k]=sum[k<<1]+sum[k<<1|1];
    }
    void Modify2(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y){
            tag[k]=-1;
            sum[k]=make_pair(-(r-l+1),-1);
            return;
        }
        int mid=(l+r)>>1;
        Push_Down(k,l,r);
        if(x<=mid) Modify2(k<<1,l,mid,x,y);
        if(mid<y) Modify2(k<<1|1,mid+1,r,x,y);
        sum[k]=sum[k<<1]+sum[k<<1|1];
    }
    pair<int,int> Query(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y) return sum[k];
        int mid=(l+r)>>1;Push_Down(k,l,r);
        if(x<=mid&&mid<y) return Query(k<<1,l,mid,x,y)+Query(k<<1|1,mid+1,r,x,y);
        if(x<=mid) return Query(k<<1,l,mid,x,y);
        else return Query(k<<1|1,mid+1,r,x,y);
    }
}
using Segment_Tree::Build;
using Segment_Tree::Modify;
using Segment_Tree::Modify2;
using Segment_Tree::Query;
int n,m,fa[100010],son[100010],dep[100010],siz[100010];
vector<int> T[100010];
void dfs1(int x,int F){
    fa[x]=F;dep[x]=dep[F]+1;siz[x]=1;
    for(auto to:T[x]){
        if(to==F) continue;
        dfs1(to,x);siz[x]+=siz[to];
        if(siz[to]>siz[son[x]]) son[x]=to;
    }
}
int top[100010],dfn[100010],dfn_tot;
void dfs2(int x,int tp){
    top[x]=tp;dfn[x]=++dfn_tot;
    if(son[x]) dfs2(son[x],tp);
    for(auto to:T[x]){
        if(to==fa[x]||to==son[x]) continue;
        dfs2(to,to);
    }
}
int Query(int x){
    pair<int,int> ans=make_pair(0,-n-1);
    while(x){
        ans=Query(1,1,n,dfn[top[x]],dfn[x])+ans;
        x=fa[top[x]];
    }
    return ans.second;
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&m);
    for(int i=2,x;i<=n;i++){
        scanf("%d",&x);
        T[x].push_back(i);
    }
    dfs1(1,0);dfs2(1,1);Build(1,1,n);
    for(int ti=1,opt,x;ti<=m;ti++){
        scanf("%d %d",&opt,&x);
        if(opt==1) Modify(1,1,n,dfn[x],1);
        if(opt==2){
            // printf("2 %d %d\n",dfn[x],siz[x]);
            Modify2(1,1,n,dfn[x],dfn[x]+siz[x]-1);
            Modify(1,1,n,dfn[x],-Query(x)-1);
        }
        if(opt==3){
            if(Query(x)>=0) puts("black");
            else puts("white");
        }
        // for(int i=1;i<=n;i++) printf("%d ",Query(1,1,n,dfn[i],dfn[i]));puts("");
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
// 10 15
// 1 1 1 4 2 6 6 4 6
// 2 3
// 1 5
// 2 4
// 2 10
// 1 3
// 3 5