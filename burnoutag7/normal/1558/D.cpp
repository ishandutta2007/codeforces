#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int precLen=400000;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[precLen+5],inv[precLen+5];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

void initialization(){
    fact[0]=1;
    for(int i=1;i<=precLen;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    inv[precLen]=qpow(fact[precLen],mod-2);
    for(int i=precLen-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

mt19937 TreapRnd(chrono::steady_clock().now().time_since_epoch().count());

struct Treap{
    struct node{
        node *l,*r;
        int val,pri,sz,laz,lvl;
        node(){
            l=r=nullptr;
            val=laz=lvl=0;
            sz=1;
            pri=TreapRnd();
        }
        void pullup(){
            sz=(l==nullptr?0:l->sz)+1+(r==nullptr?0:r->sz);
        }
        void pushdown(){
            if(l!=nullptr){
                l->laz+=laz;
                l->val+=laz;
            }
            if(r!=nullptr){
                r->laz+=laz;
                r->val+=laz;
            }
            laz=0;
        }
    };

    int size(node *p){
        if(p==nullptr)return 0;
        return p->sz;
    }

    static int poolsz;
    static node *pool;

    node* getnode(){
        if(poolsz==0){
            pool=new node[poolsz=114514];
        }
        poolsz--;
        return pool++;
    }

    node *root;

    Treap(){
        root=nullptr;
    }

    void merge(node *&p,node *l,node *r){
        if(l==nullptr){
            p=r;
        }else if(r==nullptr){
            p=l;
        }else if(l->pri<r->pri){
            l->pushdown();
            merge(l->r,l->r,r);
            l->pullup();
            p=l;
        }else{
            r->pushdown();
            merge(r->l,l,r->l);
            r->pullup();
            p=r;
        }
    }

    void split(node *p,int k,node *&l,node *&r){//l->val <= k
        if(p==nullptr){
            l=r=nullptr;
        }else if(p->val>k){
            p->pushdown();
            split(p->l,k,l,p->l);
            p->pullup();
            r=p;
        }else{
            p->pushdown();
            split(p->r,k,p->r,r);
            p->pullup();
            l=p;
        }
    }

    void ins(int x,int y){
        node *l,*r,*p;
        split(root,x,l,r);
        split(l,x-1,l,p);
        p=getnode();
        p->val=x;
        if(y)p->lvl=y;
        merge(l,l,p);
        merge(root,l,r);
    }

    int fnd(int x){//return true if x is present in the treap
        node *l,*r,*p;
        split(root,x,l,r);
        split(l,x-1,l,p);
        int res=p!=nullptr?p->lvl:0;
        merge(l,l,p);
        merge(root,l,r);
        return res;
    }

    void add(int x){//add 1 to elements geq x
        node *l,*r;
        split(root,x-1,l,r);
        if(r!=nullptr){
            r->val++;
            r->laz++;
        }
        merge(root,l,r);
    }
};

int Treap::poolsz=0;
Treap::node *Treap::pool=nullptr;

void mian(){
    int n,m;
    cin>>n>>m;
    Treap t;
    int cnt=0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(t.fnd(y-1)==1){
            t.add(y);
            t.ins(y,1);
            t.ins(y-1,2);
        }else{
            t.add(y);
            t.ins(y,1);
            cnt++;
        }
    }
    cout<<C(n+n-cnt-1,n-cnt-1)<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}