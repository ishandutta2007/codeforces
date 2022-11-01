#include<bits/stdc++.h>
using namespace std;

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
    int lv,rv,laz,lb,rb;
    node(){
        l=r=nullptr;
        lv=rv=laz=lb=rb=0;
    }
    void init(int _lb,int _rb){
        lv=lb=_lb;
        rv=rb=_rb;
    }
    void pushdown(){
        if(lb!=rb){
            if(l==nullptr){
                l=getnode();
                l->init(lb,(lb+rb)/2);
            }
            l->lv+=laz;
            l->rv+=laz;
            l->laz+=laz;
            if(r==nullptr){
                r=getnode();
                r->init((lb+rb)/2+1,rb);
            }
            r->lv+=laz;
            r->rv+=laz;
            r->laz+=laz;
            laz=0;
        }
    }
    void pullup(){
        lv=l==nullptr?lb+laz:l->lv;
        rv=r==nullptr?rb+laz:r->rv;
    }
};

node *node::pool=nullptr;
int node::poolsz=0;

node* getnode(){return node::getnode();}

struct segtree{
    node *root;
    segtree(){
        root=getnode();
        root->init(0,1e9);
    }
    int lstl(node *p,int q){
        if(p->lb==p->rb)return p->lb;
        p->pushdown();
        if(p->r->lv<q)return lstl(p->r,q);
        else return lstl(p->l,q);
    }
    int fstg(node *p,int q){
        if(p->lb==p->rb)return p->lb;
        p->pushdown();
        if(p->l->rv>q)return fstg(p->l,q);
        else return fstg(p->r,q);
    }
    void add(node *p,int l,int r,int v){
        if(r<p->lb||p->rb<l)return;
        if(l<=p->lb&&p->rb<=r){
            p->laz+=v;
            p->lv+=v;
            p->rv+=v;
            return;
        }
        p->pushdown();
        add(p->l,l,r,v);
        add(p->r,l,r,v);
        p->pullup();
    }
    void update(int T){
        if(root->lv<T){
            add(root,0,lstl(root,T),1);
        }
        if(root->rv>T){
            add(root,fstg(root,T),1e9,-1);
        }
    }
    int query(node *p,int q){
        if(p->lb==p->rb)return p->lv;
        p->pushdown();
        return query(p->l->rb>=q?p->l:p->r,q);
    }
    int query(int x){
        return query(root,x);
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,lst=0;
    cin>>n;
    segtree s;
    while(n--){
        int T;
        cin>>T;
        s.update(T);
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            x=(x+lst)%1000000001;
            cout<<(lst=s.query(x))<<'\n';
        }
    }

    return 0;
}