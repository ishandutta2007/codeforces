#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    typedef long long ll;
    struct node{
        node *l,*r;
        ll val;
        int len,swp;
        node(){
            l=r=nullptr;
            val=len=swp=0;
        }
        void pushdown(){
            if(swp&len>>1){
                node tmp=*r;
                *r=*l;
                *l=tmp;
                swp^=len>>1;
            }
            l->swp^=swp;
            r->swp^=swp;
            swp=0;
        }
        void pullup(){
            val=l->val+r->val;
        }
    };

    int sz;
    node *root;
    void build(node *id,const int &l,const int &r,const vector<int> &a){
        id->len=r-l+1;
        if(l==r){
            id->val=a[l-1];
            return;
        }
        id->l=new node;
        id->r=new node;
        build(id->l,l,l+r>>1,a);
        build(id->r,(l+r>>1)+1,r,a);
        id->pullup();
    }
    SegTree(const int &n,const vector<int> &a){
        sz=1<<n;
        root=new node;
        build(root,1,sz,a);
    }
    
    void upd(node *id,const int &l,const int &r,const int &pos,const int &val){
        if(pos<l||r<pos)return;
        if(pos<=l&&r<=pos){
            id->val=val;
            return;
        }
        id->pushdown();
        upd(id->l,l,l+r>>1,pos,val);
        upd(id->r,(l+r>>1)+1,r,pos,val);
        id->pullup();
    }

    void upd(const int &pos,const int &val){
        upd(root,1,sz,pos,val);
    }

    ll qry(node *id,const int &l,const int &r,const int &ql,const int &qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr){
            return id->val;
        }
        id->pushdown();
        return qry(id->l,l,l+r>>1,ql,qr)+qry(id->r,(l+r>>1)+1,r,ql,qr);
    }

    ll qry(const int &l,const int &r){
        return qry(root,1,sz,l,r);
    }

    void reverse(const int &k){
        root->swp^=(1<<k)-1;
    }

    void swap(const int &k){
        root->swp^=1<<k;
    }
};

int n,q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    vector<int> a(1<<n);
    for(int i=0;i<1<<n;i++){
        cin>>a[i];
    }
    SegTree t(n,a);
    while(q--){
        int typ,x,y;
        cin>>typ>>x;
        if(typ==1){
            cin>>y;
            t.upd(x,y);
        }else
        if(typ==2){
            t.reverse(x);
        }else
        if(typ==3){
            t.swap(x);
        }else
        if(typ==4){
            cin>>y;
            cout<<t.qry(x,y)<<'\n';
        }
    }

    return 0;
}