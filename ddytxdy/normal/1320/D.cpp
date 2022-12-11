#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=1003020631,base=233,inv=830828248;
int n,pw[N],q;char s[N];
struct node{
    int len,hsh,fl,fr;
    node operator +(const node &b){
        node c;
        if(!fr||!b.fl)return (node){len+b.len,(1ll*hsh*pw[b.len]+b.hsh)%mod,len?fl:b.fl,b.len?b.fr:fr};
        int dat=(1ll*(hsh-'1')*inv%mod*pw[b.len-1]%mod+b.hsh-1ll*pw[b.len-1]*'1')%mod;
        return (node){len+b.len-2,(dat+mod)%mod,len^1?fl:0,b.len^1?b.fr:0};
    }
}t[N*4];
int power(int x,int y){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
void build(int x,int l,int r){
    if(l==r){t[x]=(node){1,s[l],s[l]^'0',s[l]^'0'};return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    t[x]=t[x<<1]+t[x<<1|1];
}
node query(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr)return t[x];
    int mid=(l+r)>>1;
    if(qr<=mid)return query(x<<1,l,mid,ql,qr);
    if(ql>mid)return query(x<<1|1,mid+1,r,ql,qr);
    return query(x<<1,l,mid,ql,qr)+query(x<<1|1,mid+1,r,ql,qr);
}
int main(){
    scanf("%d%s",&n,s+1);pw[0]=1;
    for(int i=1;i<=n;i++)pw[i]=1ll*pw[i-1]*base%mod;
    build(1,1,n);scanf("%d",&q);
    for(int i=1,x,y,len;i<=q;i++){
        scanf("%d%d%d",&x,&y,&len);
        node d1=query(1,1,n,x,x+len-1),d2=query(1,1,n,y,y+len-1);
        puts(d1.len==d2.len&&d1.hsh==d2.hsh?"Yes":"No");
    }
    return 0;
}