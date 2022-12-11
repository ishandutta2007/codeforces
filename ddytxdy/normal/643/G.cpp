#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=5e5+50;
int n,m,p,cnt[N],st[20],tp,q;pii a[20];
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
struct Laz{
    int cov,add;
    Laz operator +(const Laz &b){
        if(b.cov)return b;
        if(cov)return (Laz){cov+b.add,0};
        return (Laz){0,add+b.add};
    }
};
struct node{
    int x[10],y[10],n,len;Laz la;
    void init(){x[1]=read();y[1]=n=len=1;la=(Laz){0,0};}
    node operator +(const node &b){
        node c;c.n=0;
        for(int i=1;i<=n;i++)
            !cnt[x[i]]&&(st[++tp]=x[i]),cnt[x[i]]+=y[i];
        for(int i=1;i<=b.n;i++)
            !cnt[b.x[i]]&&(st[++tp]=b.x[i]),cnt[b.x[i]]+=b.y[i];
        if(tp<=q){
        	c.n=tp;
        	for(int i=1;i<=tp;i++)
				c.x[i]=st[i],c.y[i]=cnt[st[i]],cnt[st[i]]=0;
		}
        else{
            for(int i=1;i<=tp;i++)a[i]=mp(cnt[st[i]],st[i]),cnt[st[i]]=0;
            nth_element(a+1,a+tp-q,a+tp+1);
            for(int i=tp-q+1;i<=tp;i++)if(a[i].fi>a[tp-q].fi)
                c.x[++c.n]=a[i].se,c.y[c.n]=a[i].fi-a[tp-q].fi;
        }c.la=(Laz){0,0};
        tp=0;c.len=len+b.len;return c;
    }
    node operator +(const Laz &b){
        node c;
        if(b.cov)c.x[1]=b.cov,c.n=1,c.y[1]=len;
        else{
            c.n=n;
            for(int i=1;i<=n;i++)c.x[i]=x[i]+b.add,c.y[i]=y[i];
        }
        c.la=la+b;c.len=len;return c;
    }
}t[N*4];
void build(int x,int l,int r){
    if(l==r){t[x].init();return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    t[x]=t[x<<1]+t[x<<1|1];
};
void change(int x,int l,int r,int ql,int qr,Laz la){
    if(l>=ql&&r<=qr){t[x]=t[x]+la;return;}
    int mid=(l+r)>>1;
    if(t[x].la.cov||t[x].la.add)
        t[x<<1]=t[x<<1]+t[x].la,
        t[x<<1|1]=t[x<<1|1]+t[x].la,
        t[x].la=(Laz){0,0};
    if(ql<=mid)change(x<<1,l,mid,ql,qr,la);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,la);
    t[x]=t[x<<1]+t[x<<1|1];
}
node query(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr)return t[x];
    int mid=(l+r)>>1;
    if(t[x].la.cov||t[x].la.add)
        t[x<<1]=t[x<<1]+t[x].la,
        t[x<<1|1]=t[x<<1|1]+t[x].la,
        t[x].la=(Laz){0,0};
    if(qr<=mid)return query(x<<1,l,mid,ql,qr);
    if(ql>mid)return query(x<<1|1,mid+1,r,ql,qr);
    return query(x<<1,l,mid,ql,qr)+query(x<<1|1,mid+1,r,ql,qr);
}
int main(){
	// freopen("war.in","r",stdin);
	// freopen("war.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);q=100/p;build(1,1,n);
    for(int i=1,op,l,r;i<=m;i++){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)change(1,1,n,l,r,(Laz){read(),0});
        else{
            node y=query(1,1,n,l,r);printf("%d ",y.n);
            for(int i=1;i<=y.n;i++)printf("%d ",y.x[i]);puts("");
        }
    }
    return 0;
}