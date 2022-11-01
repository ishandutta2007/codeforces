#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    static node *pool;
    static int poolsz;
    static node *getnode(){
        if(!poolsz){
            pool=new node[poolsz=12580];
        }
        poolsz--;
        return pool++;
    }
    node *l,*r;
    int pri,val,id,cnt,laz,claz,sz;
    node(){
        l=r=nullptr;
        pri=rng();
        val=id=laz=cnt=claz=0;
        sz=1;
    }
    void pushdown(){
        if(l!=nullptr){
            l->val+=laz;
            l->laz+=laz;
            l->cnt+=claz;
            l->claz+=claz;
        }
        if(r!=nullptr){
            r->val+=laz;
            r->laz+=laz;
            r->cnt+=claz;
            r->claz+=claz;
        }
        laz=claz=0;
    }
    void pullup(){
        sz=(l==nullptr?0:l->sz)+1+(r==nullptr?0:r->sz);
    }
    void buy(int c){
        laz-=c;
        val-=c;
        cnt++;
        claz++;
    }
};

node* node::pool=nullptr;
int node::poolsz=0;

node* getnode(){
    return node::getnode();
}

int size(node *p){
    if(p==nullptr)return 0;
    return p->sz;
}

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
            l->pullup();
            p=l;
        }else{
            r->pushdown();
            merge(r->l,l,r->l);
            r->pullup();
            p=r;
        }
    }
    void split(node *p,int k,int id,node *&l,node *&r){
        if(p==nullptr){
            l=r=nullptr;
        }else if(p->val>k||p->val==k&&p->id>id){
            p->pushdown();
            split(p->l,k,id,l,p->l);
            p->pullup();
            r=p;
        }else{
            p->pushdown();
            split(p->r,k,id,p->r,r);
            p->pullup();
            l=p;
        }
    }
    void ins(int x,int id){
        node *l,*r,*p;
        split(root,x,id,l,r);
        p=getnode();
        p->val=x;
        p->id=id;
        merge(l,l,p);
        merge(root,l,r);
    }
    node* ins(node *rt,node *p){
        node *l,*r;
        split(rt,p->val,p->id,l,r);
        merge(l,l,p);
        merge(rt,l,r);
        return rt;
    }
    node* del(node *rt,node *p){
        node *l,*r,*d;
        split(rt,p->val,p->id,l,r);
        split(l,p->val,p->id-1,l,d);
        merge(rt,l,r);
        return rt;
    }
    node* begin(node *p){
        while(p->l!=nullptr){
            p->pushdown();
            p=p->l;
        }
        return p;
    }
    node* end(node *p){
        while(p->r!=nullptr){
            p->pushdown();
            p=p->r;
        }
        return p;
    }
    void spend(int c){
        node *l,*r;
        split(root,c-1,1e9,l,r);
        if(r==nullptr)return;
        r->buy(c);
        while(l!=nullptr&&r!=nullptr){
            node *p=begin(r),*el=end(l);
            p->pushdown();
            if(p->val<el->val||p->val==el->val&&p->id<el->id){
                r=del(r,p);
                p->l=p->r=nullptr;
                p->pullup();
                l=ins(l,p);
            }else break;
        }
        merge(root,l,r);
    }
    void gans(node *p,int *ans){
        if(p==nullptr)return;
        p->pushdown();
        gans(p->l,ans);
        ans[p->id]=p->cnt;
        gans(p->r,ans);
    }
    void gans(int *ans){
        gans(root,ans);
    }
};

int n,k,ans[200005];
pair<int,int> ts[200005];//ts

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)cin>>ts[i].first>>ts[i].second;
    sort(ts,ts+n,[](const pair<int,int> &a,const pair<int,int> &b){
        if(a.second!=b.second)return a.second>b.second;
        return a.first<b.first;
    });
    cin>>k;
    treap t;
    for(int i=0;i<k;i++){
        int b;
        cin>>b;
        t.ins(b,i);
    }
    for(int i=0;i<n;i++)t.spend(ts[i].first);
    t.gans(ans);
    for(int i=0;i<k;i++)cout<<ans[i]<<' ';

    return 0;
}