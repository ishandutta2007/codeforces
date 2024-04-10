#include<bits/stdc++.h>
using namespace std;

mt19937 rng(1982357817);

struct node{
    static node *pool;
    static int poolsz;
    static node* getnode(){
        if(!poolsz){
            pool=new node[poolsz=12306];
        }
        poolsz--;
        return pool++;
    }
    node *l,*r;
    int pri,sz,val,hav;
    node(){
        l=r=nullptr;
        pri=rng();
        sz=1;
        val=hav=0;
    }
    void pushdown(){
    }
    node* pullup(){
        sz=(l!=nullptr?l->sz:0)+1+(r!=nullptr?r->sz:0);
        hav=1<<val|(l!=nullptr?l->hav:0)|(r!=nullptr?r->hav:0);
        return this;
    }
};

node *node::pool=nullptr;
int node::poolsz=0;
node* getnode(){return node::getnode();}
int size(node *p){return p!=nullptr?p->sz:0;}

struct treap{
    node *root;
    treap(){
        root=nullptr;
    }
    void merge(node *&p,node *l,node *r){
        if(l==nullptr)p=r;
        else if(r==nullptr)p=l;
        else if(l->pri<r->pri){
            l->pushdown();
            merge(l->r,l->r,r);
            p=l->pullup();
        }else{
            r->pushdown();
            merge(r->l,l,r->l);
            p=r->pullup();
        }
    }
    void split(node *p,int k,node *&l,node *&r){
        if(k<=0){
            l=nullptr;
            r=p;
        }else if(size(p)<=k){
            l=p;
            r=nullptr;
        }else if(size(p->l)>=k){
            p->pushdown();
            split(p->l,k,l,p->l);
            r=p->pullup();
        }else{
            p->pushdown();
            split(p->r,k-size(p->l)-1,p->r,r);
            l=p->pullup();
        }
    }
    void ins(int x,int y){
        node *l,*r;
        split(root,x-1,l,r);
        node *p=getnode();
        p->val=y;
        p->hav=1<<y;
        merge(l,l,p);
        merge(root,l,r);
    }
    void del(int x){
        node *l,*r,*p;
        split(root,x,l,r);
        split(l,x-1,l,p);
        merge(root,l,r);
    }
    int fst(int p,int v){
        node *l,*r;
        split(root,p-1,l,r);
        if(!size(r)||r->hav>>v&1^1){
            return -1;
            merge(root,l,r);
        }
        int lf=size(l);
        node *c=r;
        while(true){
            if(c->l!=nullptr&&c->l->hav>>v&1){
                c=c->l;
            }else if(c->val==v){
                break;
            }else{
                lf+=size(c->l)+1;
                c=c->r;
            }
        }
        lf+=1+size(c->l);
        merge(root,l,r);
        return lf;
    }
    int fleq(int p,int v){
        node *l,*r;
        split(root,p-1,l,r);
        if(!size(r)||!(r->hav&(1<<v+1)-1)){
            merge(root,l,r);
            return -1;
        }
        int lf=size(l);
        node *c=r;
        while(true){
            if(c->l!=nullptr&&c->l->hav&(1<<v+1)-1){
                c=c->l;
            }else if(c->val<=v){
                break;
            }else{
                lf+=size(c->l)+1;
                c=c->r;
            }
        }
        lf+=1+size(c->l);
        merge(root,l,r);
        return lf;
    }
};

typedef long long ll;

void mian(){
    int n;
    string s;
    treap t;
    cin>>n>>s;
    for(char c:s)t.ins(n,c-'a');
    cin>>s;
    s='#'+s;
    ll ans=1e18,cur=0;
    for(int i=1;i<=n;i++){
        if(s[i]!='a'){
            int nsmall=t.fleq(i,s[i]-'a'-1);
            if(nsmall!=-1)ans=min(ans,cur+nsmall-i);
        }
        int nsame=t.fst(i,s[i]-'a');
        if(nsame==-1)break;
        t.del(nsame);
        cur+=nsame-i;
        t.ins(i,s[i]-'a');
    }
    if(ans==1e18)ans=-1;
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}