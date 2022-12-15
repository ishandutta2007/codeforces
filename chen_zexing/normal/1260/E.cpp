#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[300005];
struct fhq_treap{
    int val[300005],fix[300005],ls[300005],rs[300005],sz[300005];
    int cnt,rt;
    void update(int node){
        sz[node]=sz[ls[node]]+sz[rs[node]]+1;
    }
    void new_node(int v){
        val[++cnt]=v;
        sz[cnt]=1;
        fix[cnt]=rand();
    }
    void split(int node,int v,int &x,int &y){
        if(!node){
            x=y=0;
            return;
        }
        if(val[node]<=v){
            x=node;
            split(rs[node],v,rs[node],y);
        }
        else{
            y=node;
            split(ls[node],v,x,ls[node]);
        }
        update(node);
    }
    int merge(int x,int y){
        if(!x||!y) return x+y;
        if(fix[x]<fix[y]){
            rs[x]=merge(rs[x],y);
            update(x);
            return x;
        }
        else{
            ls[y]=merge(x,ls[y]);
            update(y);
            return y;
        }
    }
    int rank(int v){
        int x,y,ans;
        split(rt,v-1,x,y);
        ans=sz[x]+1;
        merge(x,y);
        return ans;
    }
    int find_kth(int node,int k){
        if(k<=sz[ls[node]]) return find_kth(ls[node],k);
        else if(k==sz[ls[node]]+1) return val[node];
        else return find_kth(rs[node],k-sz[ls[node]]-1);
    }
    void insert(int v){
        int x,y;
        split(rt,v,x,y);
        new_node(v);
        rt=merge(merge(x,cnt),y);
    }
    void del(int v){
        int x,y,z;
        split(rt,v,x,y);
        split(x,v-1,x,z);
        z=merge(ls[z],rs[z]);
        rt=merge(merge(x,z),y);
    }
    int pre(int v){
        int x,y,ans;
        split(rt,v-1,x,y);
        ans=find_kth(x,sz[x]);
        merge(x,y);
        return ans;
    }
    int suc(int v){
        int x,y,ans;
        split(rt,v,x,y);
        ans=find_kth(y,1);
        merge(x,y);
        return ans;
    }
}treap;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int now=n/2,p=n,av=0,t;
    long long ans=0;
    while(a[p]!=-1){
        treap.insert(a[p]);
        if(av==0) t=treap.find_kth(treap.rt,1),ans+=t,treap.del(t),av+=now-1,now/=2;
        else av--;
        p--;
    }
    cout<<ans<<endl;
    return 0;
}