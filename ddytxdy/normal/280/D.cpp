#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,ql,qr,q,ll[N],rr[N],tp;bool fl[N*4];
struct node{
    int sum,lm,rm,mm,l,r,ll,rr;
    void init(int x,int p){sum=lm=rm=mm=x;l=r=ll=rr=p;}
    node operator +(const node &b){
        node c;
        c.sum=sum+b.sum;
        if(lm>=sum+b.lm)c.ll=ll,c.lm=lm;
        else c.ll=b.ll,c.lm=sum+b.lm;
        if(b.rm>=rm+b.sum)c.rr=b.rr,c.rm=b.rm;
        else c.rr=rr,c.rm=rm+b.sum;
        c.mm=max(rm+b.lm,max(mm,b.mm));
        if(mm==c.mm)c.l=l,c.r=r;
        else if(b.mm==c.mm)c.l=b.l,c.r=b.r;
        else c.l=rr,c.r=b.ll;
        return c;
    }
}t[N*4],it[N*4];
int read(){
    int x=0,c,f=1;
    while(!isdigit(c=getchar()))c=='-'?f=-1:0;
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x*f;
}
void up(int x){
    t[x]=t[x<<1]+t[x<<1|1];
    it[x]=it[x<<1]+it[x<<1|1];
}
void build(int x,int l,int r){
    if(l==r){int y=read();t[x].init(y,l);it[x].init(-y,l);return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    up(x);
}
void re(int x){swap(t[x],it[x]);fl[x]^=1;}
void change(int x,int l,int r,int p){
    if(l==r){int y=read();t[x].init(y,l);it[x].init(-y,l);return;}
    if(fl[x])re(x<<1),re(x<<1|1),fl[x]=0;
    int mid=(l+r)>>1;
    if(p<=mid)change(x<<1,l,mid,p);
    else change(x<<1|1,mid+1,r,p);
    up(x);
}
void change(int x,int l,int r){
    if(l>=ql&&r<=qr){re(x);return;}
    if(fl[x])re(x<<1),re(x<<1|1),fl[x]=0;
    int mid=(l+r)>>1;
    if(ql<=mid)change(x<<1,l,mid);
    if(qr>mid)change(x<<1|1,mid+1,r);
    up(x);
}
node query(int x,int l,int r){
    if(l>=ql&&r<=qr)return t[x];
    if(fl[x])re(x<<1),re(x<<1|1),fl[x]=0;
    int mid=(l+r)>>1;
    if(qr<=mid)return query(x<<1,l,mid);
    if(ql>mid)return query(x<<1|1,mid+1,r);
    return query(x<<1,l,mid)+query(x<<1|1,mid+1,r);
}
int main(){
    n=read();build(1,1,n);q=read();
    for(int i=1,op,l,r,k,sum;i<=q;i++){
        op=read();
        if(!op)change(1,1,n,read());
        else{
            l=read();r=read();k=read();sum=0;
            for(int j=1;j<=k;j++){
                ql=l;qr=r;
                node x=query(1,1,n);
                if(x.mm<=0)break;
                sum+=x.mm;ql=x.l;qr=x.r;
                change(1,1,n);
                ll[++tp]=ql;rr[tp]=qr;
            }
            printf("%d\n",sum);
            while(tp)ql=ll[tp],qr=rr[tp--],change(1,1,n);
        }
    }
    return 0;
}