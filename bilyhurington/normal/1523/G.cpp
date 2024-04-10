/*
 * @Author: BilyHurington
 * @Date: 2021-07-07 21:43:00
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-07-07 22:24:33
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,m,ans[50010],mp[100010];
struct Query{
    int l,r,id;
    bool operator < (Query x) const {return r-l<x.r-x.l;}
}Q[100010];
namespace Segment_Tree{
    struct node{
        int ls,rs,minn;
        node(){minn=2e9;}
    }N[40000010];
    int tot;
    void Modify(int &k,int l,int r,int x,int v){
        if(!k) k=++tot;
        if(l==r){
            N[k].minn=min(N[k].minn,v);
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid) Modify(N[k].ls,l,mid,x,v);
        else Modify(N[k].rs,mid+1,r,x,v);
        N[k].minn=min(N[N[k].ls].minn,N[N[k].rs].minn);
    }
    int Query(int k,int l,int r,int x,int y){
        if(!k) return 2e9;
        if(x<=l&&r<=y) return N[k].minn;
        int mid=(l+r)>>1,minn=2e9;
        if(x<=mid) minn=min(minn,Query(N[k].ls,l,mid,x,y));
        if(mid<y) minn=min(minn,Query(N[k].rs,mid+1,r,x,y));
        return minn;
    }
}
using Segment_Tree::Modify;
using Segment_Tree::Query;
#define lb(x) (x&-x)
int rt[50010];
void Modify(int L,int R,int v){
    // printf("M %d %d %d\n",L,R,v);
    for(;R<=n;R+=lb(R)) Modify(rt[R],1,n,L,v);
}
int Query(int L,int R){
    // printf("Q %d %d ",L,R);
    int ans=2e9;
    for(;R;R-=lb(R)) ans=min(ans,Query(rt[R],1,n,L,n));
    // printf("%d\n",ans);
    return ans;
}
int solve(int l,int r){
    // printf("S %d %d\n",l,r);
    if(l>r) return 0;
    int id=Query(l,r);
    if(id>1e9) return 0;
    return solve(l,Q[mp[id]].l-1)+Q[mp[id]].r-Q[mp[id]].l+1+solve(Q[mp[id]].r+1,r);
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    sort(Q+1,Q+m+1);
    for(int i=1;i<=m;i++) mp[Q[i].id]=i;
    for(int i=n,j=m;i>=1;i--){
        // printf("FOR %d\n",i);
        while(j>0&&(Q[j].r-Q[j].l+1==i)){
            Modify(Q[j].l,Q[j].r,Q[j].id);
            j--;
        }
        ans[i]=solve(1,n);
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}