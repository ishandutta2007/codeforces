#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=4e5+1;
int n,k,m;
struct seg{
    struct node{
        int data,lazy;
        node(){data=0,lazy=0;}
    }t[2*MAXN];
    void start(int ind, int le, int ri){
        if(le==ri)t[ind].data=-(n-le+1);
        else{
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            start(left,le,mid),start(right,mid+1,ri);
            t[ind].data=max(t[left].data,t[right].data);
        }
    }
    void rl(int ind, int le, int ri){
        t[ind].data+=t[ind].lazy;
        if(le!=ri){
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy+=t[ind].lazy,t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        rl(ind,le,ri);
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=val;
            rl(ind,le,ri);
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        rl(ind,le,ri);
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>m;
    tree.start(1,1,2*n);
    int x,y;
    set<pii> pawns;
    multiset<int> highest;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(pawns.count({x,y})){
            pawns.erase({x,y});
            int row=abs(x-k)+y;
            highest.erase(highest.find(row));
            tree.update(1,1,2*n,1,row,-1);
        }
        else{
            pawns.insert({x,y});
            int row=abs(x-k)+y;
            highest.insert(row);
            tree.update(1,1,2*n,1,row,1);
        }
        if(sz(pawns)==0)printf("%d\n",0);
        else printf("%d\n",max(0,tree.query(1,1,2*n,1,*highest.rbegin())));
    }
    return 0;
}