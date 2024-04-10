#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N;
struct segment{
    const int dim=1<<20;
    struct node{
        int ma,pos;
        node(){
            ma=pos=-1e9;
        }
    };
    node merge(node a,node b){
        if(a.ma>b.ma)return a;
        return b;
    }
    vector<node> seg=vector<node>(2*dim);
    void upd(int pos,int l,int r,int p,int val){
        if(l>p || r<p)return;
        if(l==r){
            seg[pos].ma=val;
            seg[pos].pos=p;
            return;
        }
        int m=(l+r)/2;
        upd(2*pos,l,m,p,val);
        upd(2*pos+1,m+1,r,p,val);
        seg[pos]=merge(seg[2*pos],seg[2*pos+1]);
    }
    void upd(int p,int val){
        upd(1,0,dim-1,p,val);
    }
    node query(int pos,int l,int r,int a,int b){
        if(b<l || r<a)return node();
        if(a<=l && r<=b)return seg[pos];
        int m=(l+r)/2;
        return merge(query(2*pos,l,m,a,b),query(2*pos+1,m+1,r,a,b));
    }
    node query(int a,int b){
        return query(1,0,dim-1,a,b);
    }
}seg;
int solve(int a,int b){
    if(b<a)return 0;
    auto pos=seg.query(a,b);
    int ans=solve(a,pos.pos-1)+solve(pos.pos+1,b);
    ans+=pos.ma*(pos.pos-a+1)*(b-pos.pos+1);
    return ans;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        seg.upd(i,a);
        v.pb(a);
    }
    int ans=0;
    ans+=solve(0,N-1);
    for(int i=0;i<N;i++)seg.upd(i,-v[i]);
    ans+=solve(0,N-1);
    cout<<ans<<endl;
}