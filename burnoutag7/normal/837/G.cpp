#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
    node *l,*r;
    ll a,b;
    node(){
        l=r=nullptr;
        a=b=0;
    }
};

node *pool;
int poolsz;

node* getnode(){
    if(poolsz==0){
        pool=new node[poolsz=114514];
    }
    poolsz--;
    return pool++;
}

struct SegTree{
    vector<node*> rv;
    SegTree(){
        rv.emplace_back(getnode());
    }
    void upd(node *p,node *&np,int l,int r,int ql,int qr,int a,int b){
        if(r<ql||qr<l){
            np=p;
            return;
        }
        np=getnode();
        if(p!=nullptr){
            np->a=p->a;
            np->b=p->b;
        }
        if(ql<=l&&r<=qr){
            np->a+=a;
            np->b+=b;
            if(p!=nullptr){
                np->l=p->l;
                np->r=p->r;
            }
            return;
        }
        upd(p==nullptr?nullptr:p->l,np->l,l,l+r>>1,ql,qr,a,b);
        upd(p==nullptr?nullptr:p->r,np->r,(l+r>>1)+1,r,ql,qr,a,b);
    }
    void upd(int l,int r,int a,int b){
        node *p=rv.back(),*np=nullptr;
        upd(p,np,0,200001,l,r,a,b);
        rv.emplace_back(np);
    }
    void add(int x1,int x2,int y1,int a,int b,int y2){
        upd(0,x1,0,y1);
        upd(x1+1,x2,a,b);
        upd(x2+1,200001,0,y2);
    }
    ll qry(node *p,int l,int r,int x,ll a,ll b){
        a+=p->a;
        b+=p->b;
        if(l==r)return a*x+b;
        if(l+r>>1>=x){
            if(p->l==nullptr)return a*x+b;
            return qry(p->l,l,l+r>>1,x,a,b);
        }else{
            if(p->r==nullptr)return a*x+b;
            return qry(p->r,(l+r>>1)+1,r,x,a,b);
        }
    }
    ll qry(int ver,int x){
        return qry(rv[ver*3],0,200001,x,0,0);
    }
    ll sum(int l,int r,int x){
        x=min(x,200001);
        return qry(r,x)-qry(l-1,x);
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    SegTree st;
    int n;
    cin>>n;
    while(n--){
        int x1,x2,y1,a,b,y2;
        cin>>x1>>x2>>y1>>a>>b>>y2;
        st.add(x1,x2,y1,a,b,y2);
    }
    cin>>n;
    while(n--){
        int l,r,x;
        static ll last;
        cin>>l>>r>>x;
        x=(x+last)%(int)1e9;
        cout<<(last=st.sum(l,r,x))<<'\n';
    }

    return 0;
}