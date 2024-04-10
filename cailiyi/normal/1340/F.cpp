#include<bits/stdc++.h>
#define N 100000
#define mid ((l+r)>>1)
using namespace std;
int n,k,q,s[N+5];
unsigned long long B,powB[N+5];
struct node
{
    bool tag;
    int llen,rlen;
    unsigned long long lhash,rhash;
    node *lson,*rson;
    node() {tag=0,llen=rlen=0,lhash=rhash=0;}
    inline void init(int val)
    {
        if(val>0) llen=0,lhash=0,rlen=1,rhash=val;
        else llen=1,lhash=-val,rlen=0,rhash=0;
    }
    inline unsigned long long getl(int len)
    {
        if(!len) return 0;
        if(llen==len) return lhash;
        if(lson->llen>=len) return lson->getl(len);
        unsigned long long temp=rson->getl((len-=lson->llen)+lson->rlen);
        return temp+(lson->lhash-lson->rhash)*powB[len];
    }
    inline unsigned long long getr(int len)
    {
        if(!len) return 0;
        if(rlen==len) return rhash;
        if(rson->rlen>=len) return rson->getr(len);
        unsigned long long temp=lson->getr((len-=rson->rlen)+rson->llen);
        return temp+(rson->rhash-rson->lhash)*powB[len];
    }
    inline void push_up()
    {
        if((tag=lson->tag || rson->tag)) return;
        llen=lson->llen,lhash=lson->lhash;
        rlen=rson->rlen,rhash=rson->rhash;
        if(lson->rlen<rson->llen)
        {
            unsigned long long temp=rson->getl(lson->rlen);
            if(lson->rhash!=temp) return tag=1,void();
            int len=rson->llen-lson->rlen;
            lhash=rson->lhash+(lhash-temp)*powB[len];
            return llen+=len,void();
        }
        if(lson->rlen>rson->llen)
        {
            unsigned long long temp=lson->getr(rson->llen);
            if(rson->lhash!=temp) return tag=1,void();
            int len=lson->rlen-rson->llen;
            rhash=lson->rhash+(rhash-temp)*powB[len];
            return rlen+=len,void();
        }
        return tag=lson->rhash!=rson->lhash,void();
    }
    inline bool check()
    {
        return !(tag || lhash || rhash);
    }
};
inline node* build(int l,int r)
{
    node *x=new node();
    if(l==r) return x->init(s[l]),x;
    x->lson=build(l,mid);
    x->rson=build(mid+1,r);
    return x->push_up(),x;
}
inline void modify(node* x,int l,int r,int p,int val)
{
    if(l==r) return x->init(val);
    p<=mid?modify(x->lson,l,mid,p,val):
        modify(x->rson,mid+1,r,p,val);
    x->push_up();
}
inline node* query(node *x,int l,int r,int le,int ri)
{
    if(le<=l && r<=ri) return x;
    if(ri<=mid) return query(x->lson,l,mid,le,ri);
    if(le>mid) return query(x->rson,mid+1,r,le,ri);
    node *ret=new node();
    ret->lson=query(x->lson,l,mid,le,ri);
    ret->rson=query(x->rson,mid+1,r,le,ri);
    return ret->push_up(),ret;
}
int main()
{
    scanf("%d %d",&n,&k),B=k+1,powB[0]=1;
    for(int i=1;i<=n;++i) scanf("%d",s+i),powB[i]=powB[i-1]*B;
    node* root=build(1,n);
    scanf("%d",&q);
    for(int opt,a,b;q--;)
    {
        scanf("%d %d %d",&opt,&a,&b);
        if(opt==1) modify(root,1,n,a,b);
        else puts(query(root,1,n,a,b)->check()?"Yes":"No");
    }
    return 0;
}