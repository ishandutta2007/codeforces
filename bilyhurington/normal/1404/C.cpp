/*
 * @Author: BilyHurington
 * @Date: 2020-09-06 22:35:02
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-06 23:47:54
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,q,a[300010];
struct Query{int L,R,id,ans;}Q[300010];
bool cmp1(Query Q1,Query Q2){return Q1.L>Q2.L;}
bool cmp2(Query Q1,Query Q2){return Q1.id<Q2.id;}
namespace seg1{
    int sum[1200010];
    void modify(int k,int l,int r,int x,int ad){
        if(l==r){sum[k]+=ad;return;}
        int mid=(l+r)>>1;
        if(x<=mid) modify(k<<1,l,mid,x,ad);
        else modify(k<<1|1,mid+1,r,x,ad);
        sum[k]=sum[k<<1]+sum[k<<1|1];
    }
    int query(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y) return sum[k];
        int mid=(l+r)>>1,ans=0;
        if(x<=mid) ans+=query(k<<1,l,mid,x,y);
        if(mid<y) ans+=query(k<<1|1,mid+1,r,x,y);
        return ans;
    }
}
namespace seg2{
    int minn[1200010],tag[1200010];
    void build(int k,int l,int r){
        if(l==r){
            if(a[l]>l) minn[k]=1e9;
            else minn[k]=l-a[l];
            // printf("%d %d\n",l,minn[k]);
            return;
        }
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        minn[k]=min(minn[k<<1],minn[k<<1|1]);
    }
    void add(int k,int ad){
        minn[k]+=ad;
        tag[k]+=ad;
    }
    void push_down(int k){
        if(!tag[k]) return;
        add(k<<1,tag[k]);
        add(k<<1|1,tag[k]);
        tag[k]=0;
    }
    void modify(int k,int l,int r,int x,int y,int ad){
        if(x<=l&&r<=y){add(k,ad);return;}
        int mid=(l+r)>>1;push_down(k);
        if(x<=mid) modify(k<<1,l,mid,x,y,ad);
        if(mid<y) modify(k<<1|1,mid+1,r,x,y,ad);
        minn[k]=min(minn[k<<1],minn[k<<1|1]);
    }
    int query_min(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y) return minn[k];
        int mid=(l+r)>>1,mn=2e9;push_down(k);
        if(x<=mid) mn=min(mn,query_min(k<<1,l,mid,x,y));
        if(mid<y) mn=min(mn,query_min(k<<1|1,mid+1,r,x,y));
        return mn;
    }
    int query(int k,int l,int r){
        if(l==r){minn[k]=1e9;return l;}
        int mid=(l+r)>>1,ans;push_down(k);
        if(!minn[k<<1|1]) ans=query(k<<1|1,mid+1,r);
        else ans=query(k<<1,l,mid);
        minn[k]=min(minn[k<<1],minn[k<<1|1]);
        return ans;
    }
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg2::build(1,1,n);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&Q[i].L,&Q[i].R),Q[i].id=i;
        Q[i].L++;Q[i].R=n-Q[i].R;
        // printf("%d %d\n",Q[i].L,Q[i].R);
    }
    sort(Q+1,Q+q+1,cmp1);int tot=1;
    for(int i=n;i>=1;i--){
        // printf("POS: %d\n",i);
        while(!seg2::query_min(1,1,n,i,n)){
            int x=seg2::query(1,1,n);
            // printf("%d\n",x);
            seg1::modify(1,1,n,x,1);
            seg2::modify(1,1,n,x,n,-1);
        }
        while(tot<=q&&Q[tot].L==i){
            Q[tot].ans=seg1::query(1,1,n,i,Q[tot].R);
            // printf("%d %d\n",Q[tot].id,Q[tot].ans);
            tot++;
        }
    }
    sort(Q+1,Q+q+1,cmp2);
    for(int i=1;i<=q;i++) printf("%d\n",Q[i].ans);
    return 0;
}