/*
 * @Author: BilyHurington
 * @Date: 2020-08-31 21:16:57
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-01 13:24:25
 */
#include<bits/stdc++.h>
using namespace std;
struct Linear_Base{
    int lb[31];
    Linear_Base(){memset(lb,0,sizeof(lb));}
    void insert(int x){
        for(int i=30;i>=0;i--){
            if((x>>i)&1){
                if(!lb[i]){lb[i]=x;break;}
                x^=lb[i];
            }
        }
    }
    int ask(){
        int ans=1;
        for(int i=30;i>=0;i--){
            if(lb[i]) ans*=2;
        }
        return ans;
    }
    Linear_Base operator + (const Linear_Base &L) const& {
        Linear_Base Ans=L;
        for(int i=30;i>=0;i--){
            if(lb[i]) Ans.insert(lb[i]);
        }
        return Ans;
    }
};
int n,q,a[200010],b[200010];
namespace Segment_Tree_A{
    int tag[800010];
    void Build(int k,int l,int r){
        if(l==r){tag[k]=a[l];return;}
        int mid=(l+r)>>1;
        Build(k<<1,l,mid);
        Build(k<<1|1,mid+1,r);
    }
    void Modify(int k,int l,int r,int x,int y,int ad){
        if(x<=l&&r<=y){tag[k]^=ad;return;}
        int mid=(l+r)>>1;
        if(x<=mid) Modify(k<<1,l,mid,x,y,ad);
        if(mid<y) Modify(k<<1|1,mid+1,r,x,y,ad);
    }
    int Query(int k,int l,int r,int x){
        if(l==r) return tag[k];
        int mid=(l+r)>>1;
        if(x<=mid) return Query(k<<1,l,mid,x)^tag[k];
        else return Query(k<<1|1,mid+1,r,x)^tag[k];
    }
}
namespace Segment_Tree_B{
    Linear_Base L[800010];
    void Build(int k,int l,int r){
        if(l==r){L[k].insert(b[l]);return;}
        int mid=(l+r)>>1;
        Build(k<<1,l,mid);
        Build(k<<1|1,mid+1,r);
        L[k]=L[k<<1]+L[k<<1|1];
    }
    void Modify(int k,int l,int r,int x,int nw){
        if(l==r){L[k]=Linear_Base();L[k].insert(nw);return;}
        int mid=(l+r)>>1;
        if(x<=mid) Modify(k<<1,l,mid,x,nw);
        else Modify(k<<1|1,mid+1,r,x,nw);
        L[k]=L[k<<1]+L[k<<1|1];
    }
    Linear_Base Query(int k,int l,int r,int x,int y){
        if(x>y) return Linear_Base();
        if(x<=l&&r<=y) return L[k];
        int mid=(l+r)>>1;
        if(x<=mid&&mid<y) return Query(k<<1,l,mid,x,y)+Query(k<<1|1,mid+1,r,x,y);
        if(x<=mid) return Query(k<<1,l,mid,x,y);
        else return Query(k<<1|1,mid+1,r,x,y);
    }
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) b[i]=a[i-1]^a[i];
    Segment_Tree_A::Build(1,1,n);
    Segment_Tree_B::Build(1,1,n);
    int opt,x,y,z;
    while(q--){
        scanf("%d %d %d",&opt,&x,&y);
        if(opt==1){
            scanf("%d",&z);
            Segment_Tree_A::Modify(1,1,n,x,y,z);
            if(y!=n){
                b[y+1]^=z;
                Segment_Tree_B::Modify(1,1,n,y+1,b[y+1]);
            }
            b[x]^=z;
            Segment_Tree_B::Modify(1,1,n,x,b[x]);
        }
        else{
            Linear_Base LB;LB.insert(Segment_Tree_A::Query(1,1,n,x));
            printf("%d\n",(Segment_Tree_B::Query(1,1,n,x+1,y)+LB).ask());
        }
    }
    return 0;
}