#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

using bst=__gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
typedef long long ll;

struct SegTree{
    int sz;
    vector<ll> dat;

    SegTree(int _sz=1){
        sz=1;while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
    }

    void upd(int pos,ll val){
        pos+=sz-1;
        dat[pos]+=val;
        while(pos>1){
            pos>>=1;
            dat[pos]=dat[pos<<1]+dat[pos<<1|1];
        }
    }

    ll qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr)return dat[id];
        return qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr);
    }

    ll qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
}seg;

int n,p[300005],fa[300005];
char s[300005];
bst son[300005];

void deal(int l,int r){
    int x=l+1;
    while(x!=r){
        fa[x]=l;
        son[l].insert(x);
        x=p[x]+1;
    }
    seg.upd(l,1+son[l].size()*(son[l].size()-1ll)/2);
}

void del(int l,int r){
    seg.upd(l,-1);
    ll cnt=son[fa[l]].size();
    if(fa[l])seg.upd(fa[l],-cnt*(cnt-1)/2);
    son[fa[l]].erase(l);
    if(fa[l])seg.upd(fa[l],(cnt-1)*(cnt-2)/2);
}

ll ask(int l,int r){
    ll res=seg.qry(l,r);
    int cnt=son[fa[l]].order_of_key(r)-son[fa[l]].order_of_key(l);
    return res+cnt*(cnt-1ll)/2;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>n>>q>>s+1;
    seg=SegTree(n);
    {
        stack<int> t;
        for(int i=1;i<=n;i++){
            if(s[i]=='(')t.emplace(i);
            else if(!t.empty()){
                p[t.top()]=i;
                p[i]=t.top();
                t.pop();
            }
        }
    }
    memset(fa,-1,sizeof(fa));
    for(int i=1;i<=n;i++)if(p[i]>i){
        if(fa[i]==-1)son[fa[i]=0].insert(i);
        deal(i,p[i]);
    }
    while(q--){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            del(l,r);
        }else{
            cout<<ask(l,r)<<'\n';
        }
    }

    return 0;
}