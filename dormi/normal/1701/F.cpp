#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
struct seg{
    struct node{
        ll val,sum;
        int lazy,cnt;
        node(){
            val=0,sum=0;
            cnt=0,lazy=0;
        }
        void apply(int v){
            val+=2*ll(sum)*v+ll(v)*(v-1)*cnt;
            sum+=ll(v)*cnt;
            lazy+=v;
        }
    }t[2*MN];
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int v){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].val=t[left].val+t[right].val;
        t[ind].sum=t[left].sum+t[right].sum;
        t[ind].cnt=t[left].cnt+t[right].cnt;
    }
    void update(int ind, int le, int ri, int loc, int am){
        if(loc<le||loc>ri)return;
        if(le==ri){
           if(am==-1){
               t[ind]=node();
           }
           else{
               t[ind].cnt=1;
               t[ind].sum=am;
               t[ind].val=am*ll(am-1);
           }
           return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,am),update(right,mid+1,ri,loc,am);
        t[ind].val=t[left].val+t[right].val;
        t[ind].sum=t[left].sum+t[right].sum;
        t[ind].cnt=t[left].cnt+t[right].cnt;
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].cnt;
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r)+query(right,mid+1,ri,l,r);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q,d;
    cin>>q>>d;
    int a;
    set<int> vals;
    while(q--){
        cin>>a;
        if(vals.count(a)){
            vals.erase(a);
            tree.update(0,1,MN,a,-1);
            tree.update(0,1,MN,a-d,a-1,-1);
        }
        else{
            vals.insert(a);
            tree.update(0,1,MN,a,tree.query(0,1,MN,a+1,a+d));
            tree.update(0,1,MN,a-d,a-1,1);
        }
        printf("%lli\n",tree.t[0].val/2);
    }
    return 0;
}