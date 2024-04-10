#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=MN,lazy=0;
        }
        void apply(int val){
            data+=val,lazy+=val;
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(le!=ri){
            t[left].apply(t[ind].lazy);
            t[right].apply(t[ind].lazy);
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int v){
        if(ri<l||le>r||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].data=min(t[left].data,t[right].data);
    }
    void set(int ind, int le, int ri, int loc, int v){
        if(loc<le||loc>ri)return;
        if(le==ri){
            t[ind].data=min(t[ind].data,v);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        set(left,le,mid,loc,v),set(right,mid+1,ri,loc,v);
        t[ind].data=min(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(ri<l||le>r||l>r)return MN;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int last=0;
    tree.set(0,0,n,0,0);
    for(int i=0;i<n;i++){
        cin>>a;
        int lastval=min(tree.query(0,0,n,a,a),min(tree.query(0,0,n,0,a-1),tree.query(0,0,n,a+1,n))+1);
        if(a!=last)tree.update(0,0,n,0,n,1);
        tree.set(0,0,n,last,lastval);
        last=a;
    }
    printf("%d\n",tree.query(0,0,n,0,n));
    return 0;
}