#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int n;
int l[200005],r[200005],c[200005];
int b[400005];
struct seg_tree{
    long long tree[1600005],lz[1600005];
    void clear(){
        for(int i=1;i<=n*8;i++) tree[i]=lz[i]=0;
    }
    void pushdown(int node,int l,int r){
        if(lz[node]){
            int mid=(l+r)>>1;
            tree[node*2]+=lz[node]*(mid-l+1),tree[node*2+1]+=lz[node]*(r-mid);
            lz[node*2]+=lz[node],lz[node*2+1]+=lz[node],lz[node]=0;
        }
    }
    void update(int node,int l,int r,int L,int R,int v){
        if(l>=L&&r<=R){
            tree[node]+=(r-l+1)*v,lz[node]+=v;
            return;
        }
        pushdown(node,l,r);
        int mid=(l+r)>>1;
        if(mid>=L) update(node*2,l,mid,L,R,v);
        if(mid<R) update(node*2+1,mid+1,r,L,R,v);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
    int nxt(int node,int l,int r,int pos){
        if(l>=pos){
            if(!tree[node]) return -1;
            if(l!=r) pushdown(node,l,r);
            int mid=(l+r)>>1;
            if(l==r) return l;
            else if(tree[node*2]) return nxt(node*2,l,mid,pos);
            else return nxt(node*2+1,mid+1,r,pos);
        }
        pushdown(node,l,r);
        int mid=(l+r)>>1;
        if(pos<=mid){
            int temp=nxt(node*2,l,mid,pos);
            if(temp==-1) return nxt(node*2+1,mid+1,r,pos);
            else return temp;
        }
        else return nxt(node*2+1,mid+1,r,pos);
    }
    int pre(int node,int l,int r,int pos){
        if(r<=pos){
            if(!tree[node]) return -1;
            if(l!=r) pushdown(node,l,r);
            int mid=(l+r)>>1;
            if(l==r) return l;
            else if(tree[node*2+1]) return pre(node*2+1,mid+1,r,pos);
            else return pre(node*2,l,mid,pos);
        }
        pushdown(node,l,r);
        int mid=(l+r)>>1;
        if(pos>mid){
            int temp=pre(node*2+1,mid+1,r,pos);
            if(temp==-1) return pre(node*2,l,mid,pos);
            else return temp;
        }
        else return pre(node*2,l,mid,pos);
    }
}Tr;
vector <int> v[200005];
int ans[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear();
        int x=0;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&l[i],&r[i],&c[i]),v[c[i]].push_back(i),b[++x]=l[i],b[++x]=r[i];
        sort(b+1,b+x+1);
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(b+1,b+x+1,l[i])-b;
            r[i]=lower_bound(b+1,b+x+1,r[i])-b;
        }
        Tr.clear();
        for(int i=1;i<=n;i++) Tr.update(1,1,n*2,l[i],r[i],1);
        for(int i=1;i<=n;i++){
            for(auto t:v[i]) Tr.update(1,1,n*2,l[t],r[t],-1);
            for(auto t:v[i]){
                int mn=INT_MAX,p1=Tr.nxt(1,1,n*2,l[t]),p2=Tr.pre(1,1,n*2,r[t]);
                if(p1!=-1) mn=min(mn,max(0,b[p1]-b[r[t]]));
                if(p2!=-1) mn=min(mn,max(0,b[l[t]]-b[p2]));
                ans[t]=mn;
            }
            for(auto t:v[i]) Tr.update(1,1,n*2,l[t],r[t],1);
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}