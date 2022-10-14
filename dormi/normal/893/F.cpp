#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
int arr[MAXN],depth[MAXN],st[MAXN],en[MAXN];
vector<int> matrix[MAXN];
vector<int> et;
void dfs(int loc, int parent, int dep){
    depth[loc]=dep;
    st[loc]=sz(et);
    et.push_back(loc);
    for(auto x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc,dep+1);
            et.push_back(loc);
        }
    }
    en[loc]=sz(et)-1;
}
struct seg{
    struct node{
        vector<int> mi;
        int stdep;
        node(){
            mi={},stdep=0;
        }
    }t[4*MAXN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].mi={arr[et[le]]},t[ind].stdep=depth[et[le]];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        int curmi=INT_MAX;
        int maval=max(t[left].stdep+sz(t[left].mi)-1,t[right].stdep+sz(t[right].mi)-1),mival=min(t[left].stdep,t[right].stdep);
        t[ind].mi.resize(maval-mival+1);
        t[ind].stdep=mival;
        for(int i=mival;i<=maval;i++)t[ind].mi[i-mival]=curmi=min({curmi,((i-t[left].stdep>=0&&i-t[left].stdep<sz(t[left].mi))?t[left].mi[i-t[left].stdep]:INT_MAX),((i-t[right].stdep>=0&&i-t[right].stdep<sz(t[right].mi))?t[right].mi[i-t[right].stdep]:INT_MAX)});
    }
    int query(int ind, int le, int ri, int l, int r, int dep){
        if(r<le||l>ri)return INT_MAX;
        if(le>=l&&ri<=r)return (dep>=t[ind].stdep?t[ind].mi[min(sz(t[ind].mi)-1,dep-t[ind].stdep)]:INT_MAX);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r,dep),query(right,mid+1,ri,l,r,dep));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,r;
    cin>>n>>r;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(r,0,1);
    tree.mt(0,0,sz(et)-1);
    int m;
    cin>>m;
    int last=0;
    int x,k;
    while(m--){
        cin>>x>>k;
        x=((x+last)%n)+1,k=(k+last)%n;
        printf("%d\n",last=tree.query(0,0,sz(et)-1,st[x],en[x],depth[x]+k));
    }
    return 0;
}