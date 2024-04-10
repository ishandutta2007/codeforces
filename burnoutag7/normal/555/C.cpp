#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    struct node{
        node *l,*r;
        int laz,dat;

        node(){
            l=r=nullptr;
            laz=dat=0;
        }

        node(const int &x){
            l=r=nullptr;
            laz=dat=x;
        }

        void pullup(){
            if(l!=nullptr){
                dat=max(dat,l->dat);
            }
            if(r!=nullptr){
                dat=max(dat,r->dat);
            }
        }
    };

    int pool_sz,sz;
    node *pool,*new_pos,*root;

    node *get_node(){
        if(new_pos==pool+pool_sz)new_pos=pool=new node[pool_sz];
        return new_pos++;
    }

    SegTree(const int &_sz=114514){
        sz=_sz;
        pool_sz=114514;
        new_pos=pool=new node[pool_sz];
        root=nullptr;
    }

    int qry(node *&p,const int &l,const int &r,const int &q){
        if(r<q||q<l||p==nullptr)return 0;
        if(l==r)return p->dat;
        return max(max(qry(p->l,l,l+r>>1,q),qry(p->r,(l+r>>1)+1,r,q)),p->laz);
    }

    void upd(node *&p,const int &l,const int &r,const int &ql,const int &qr,const int &val){
        if(r<ql||qr<l)return;
        if(p==nullptr)p=get_node();
        if(ql<=l&&r<=qr){
            p->laz=max(p->laz,val);
            p->dat=max(p->dat,val);
            return;
        }
        upd(p->l,l,l+r>>1,ql,qr,val);
        upd(p->r,(l+r>>1)+1,r,ql,qr,val);
        p->pullup();
    }

    int qry(const int &q){
        return qry(root,1,sz,q);
    }

    void upd(const int &l,const int &r,const int &val){
        upd(root,1,sz,l,r,val);
    }
};

int n,q;

int main(){

    scanf("%d %d",&n,&q);
    SegTree hor(n),ver(n);
    while(q--){
        int row,col;
        char dir;
        scanf("%d %d %c",&col,&row,&dir);
        if(dir=='U'){
            int top=hor.qry(col);
            ver.upd(top+1,row,col);
            hor.upd(col,col,row);
            printf("%d\n",row-top);
        }else{
            int lft=ver.qry(row);
            hor.upd(lft+1,col,row);
            ver.upd(row,row,col);
            printf("%d\n",col-lft);
        }
    }

    return 0;
}