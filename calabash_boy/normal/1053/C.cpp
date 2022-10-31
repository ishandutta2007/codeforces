#include<bits/stdc++.h>
#define N 400005
#define P 1000000007
using namespace std;
long long p,i,j,k,l,s,n,m,sum,x,y,a[N],b[N];
struct node {
    long long sum,val;
}f[N*4];
inline node up(node x,node y) {
    return node{(x.sum+y.sum),(x.val+y.val)%P};
}
inline void change(long long o,long long l,long long r,long long ll,long long p) {
    if (l==ll&&r==ll) {
        f[o].val=a[l]*p%P;
        f[o].sum=p;
        return ;
    }
    long long mid=(l+r)>>1;
    if (ll<=mid) change(o*2,l,mid,ll,p);
    else change(o*2+1,mid+1,r,ll,p);
    f[o]=up(f[o*2],f[o*2+1]);
}
inline node ask(long long o,long long l,long long r,long long ll,long long rr) {
    if (l==ll&&r==rr) return f[o];
    long long mid=(l+r)>>1;
    if (rr<=mid) return ask(o*2,l,mid,ll,rr);
    else if (ll>mid) return ask(o*2+1,mid+1,r,ll,rr);
    else return up(ask(o*2,l,mid,ll,mid),ask(o*2+1,mid+1,r,mid+1,rr));
}
inline long long get(long long o,long long l,long long r,long long ll,long long rr) {
    if (p*2>=sum) return 0;
    if (l>=ll&&r<=rr) {
        if (p*2>=sum) return 0;
        if ((p+f[o].sum)*2<sum) {
            p+=f[o].sum;
            return 0;
        }
        if (l==r) {
            p+=f[o].sum;
            return l;
        }
        long long mid=(l+r)>>1;
        if (2*(f[o*2].sum+p)>=sum) return get(o*2,l,mid,ll,rr);
        else {
            p+=f[o*2].sum;
            return get(o*2+1,mid+1,r,ll,rr);
        }
    }
    long long mid=(l+r)>>1;
    if (rr<=mid) return get(o*2,l,mid,ll,rr);
    else if (ll>mid) return get(o*2+1,mid+1,r,ll,rr);
    else {
        long long xx=get(o*2,l,mid,ll,mid);
        long long yy=get(o*2+1,mid+1,r,mid+1,rr);
        return max(xx,yy);
    }
}
inline long long ask(long long x,long long l,long long r) {
    node gt=ask(1,1,n,l,x);
    node gtw=ask(1,1,n,x,r);
    return (gt.sum%P*a[x]%P-gt.val+gtw.val-gtw.sum%P*a[x]%P)%P;
}
int main() {
    scanf("%I64d%I64d",&n,&m);
    for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]),a[i]-=i;
    for (long long i=1;i<=n;i++) {
        scanf("%I64d",&b[i]);
        change(1,1,n,i,b[i]);
    }
    for (long long i=1;i<=m;i++) {
        scanf("%I64d%I64d",&x,&y);
        if (x>0) {
            sum=ask(1,1,n,x,y).sum;
            p=0;
            long long gt=get(1,1,n,x,y);
            printf("%I64d\n",(((ask(gt,x,y))%P)+P)%P);
        }
        else {
            x=-x;
            b[x]=y;
            change(1,1,n,x,b[x]);
        }
    }
}