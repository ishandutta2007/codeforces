#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
ll arr[MAXN];
struct seg{
    struct node{
        ll data,mi,lazy;
        node(){data=0,mi=0,lazy=0;}
        void apply(ll val, ll range){
            data=val*range;
            mi=val;
            lazy=val;
        }
    }t[2*MAXN];
    void mt(int ind, int le, int ri){
        if(le==ri){t[ind].data=t[ind].mi=arr[le];return;}
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind].data=t[left].data+t[right].data,t[ind].mi=t[right].mi;
    }
    void prop(int ind, int le, int ri){
        if(t[ind].lazy==0)return;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,mid-le+1),t[right].apply(t[ind].lazy,ri-mid);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll val){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){t[ind].apply(val,ri-le+1);return;}
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=t[left].data+t[right].data,t[ind].mi=t[right].mi;
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r)+query(right,mid+1,ri,l,r);
    }
    int smallerbound(int ind, int le, int ri, ll val){
        if(le==ri)return le+(val<t[ind].mi);
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(t[left].mi>val)return smallerbound(right,mid+1,ri,val);
        return smallerbound(left,le,mid,val);
    }
    int mostright(int ind, int le, int ri, ll val){
        if(le==ri)return ri-(val<t[ind].mi);
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(t[left].data>=val)return mostright(left,le,mid,val);
        return mostright(right,mid+1,ri,val-t[left].data);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    tree.mt(0,1,n);
    int a,b;
    ll c;
    while(q--){
        cin>>a>>b>>c;
        if(a==1)tree.update(0,1,n,tree.smallerbound(0,1,n,c),b,c);
        else{
            int am=0,l;
            while((l=tree.smallerbound(0,1,n,c))<=n){
                l=max(l,b);
                int r=tree.mostright(0,1,n,tree.query(0,1,n,1,l-1)+c);
                c-=tree.query(0,1,n,l,r);
                am+=r-l+1;
                if(r==n)break;
            }
            printf("%d\n",am);
        }
    }
    return 0;
}