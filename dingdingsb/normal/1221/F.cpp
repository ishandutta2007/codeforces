#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct Point{
    int l,r,w;
}P[N];
struct node{
    long long ret;int id;
    long long tag;
    int l,r;
}T[N*8];
#define lson (x<<1)
#define rson (x<<1|1)
void pushup(int x){
    T[x].ret=max(T[lson].ret,T[rson].ret);
    if(T[rson].ret>T[lson].ret)T[x].id=T[rson].id;
    else T[x].id=T[lson].id;
}
void pushdown(int x){
    if(T[x].tag){
        T[lson].tag+=T[x].tag;T[lson].ret+=T[x].tag;
        T[rson].tag+=T[x].tag;T[rson].ret+=T[x].tag;
        T[x].tag=0;
    }
}
vector<int>num;
void build(int x,int l,int r){
    T[x].l=l,T[x].r=r;
    if(l==r){T[x].ret=-num[l],T[x].id=l;return;}
    int mid=l+r>>1;
    build(lson,l,mid);build(rson,mid+1,r);
    pushup(x);
}
pair<long long,int>query(int x,int l,int r){
    if(l<=T[x].l&&T[x].r<=r)return {T[x].ret,T[x].id};
    pushdown(x);
	int mid=T[x].l+T[x].r>>1;
    if(r<=mid)return query(lson,l,r);
    if(mid<l)return query(rson,l,r);
    return max(query(lson,l,r),query(rson,l,r));
}
void upd(int x,int l,int r,int val){
    if(l<=T[x].l&&T[x].r<=r){T[x].ret+=val;T[x].tag+=val;return;}
    pushdown(x);
    int mid=T[x].l+T[x].r>>1;
    if(l<=mid)upd(lson,l,r,val);
    if(mid<r)upd(rson,l,r,val);
    pushup(x);
}
int n;
#define pb push_back
vector<pair<int,int>>v[N*2];
signed main(){
    scanf("%d",&n);
    for(int i=1,x,y,w;i<=n;i++)
        scanf("%d%d%d",&x,&y,&w),
        num.pb(x),num.pb(y),
        P[i]=(Point){min(x,y),max(x,y),w};
    sort(num.begin(),num.end());
    num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=1;i<=n;i++){
        int l=lower_bound(num.begin(),num.end(),P[i].l)-num.begin();
        int r=lower_bound(num.begin(),num.end(),P[i].r)-num.begin();
        v[l].pb({r,P[i].w});
    }
    build(1,0,num.size()-1);
    long long ans=0,ansl=2e9,ansr=2e9;
    for(int i=num.size()-1;i>=0;i--){
        for(auto to:v[i])
            upd(1,to.first,num.size()-1,to.second);
        auto ret=query(1,i,num.size()-1);
        ret.first+=num[i];
        if(ret.first>ans)
            ans=ret.first,
            ansl=num[i],ansr=num[ret.second];
    }
    cout<<ans<<"\n"<<ansl<<" "<<ansl<<" "<<ansr<<" "<<ansr;
}