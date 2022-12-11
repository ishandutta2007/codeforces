#include<cmath>
#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define vec vector<z>
#define LL long long
// #define int LL
#define pb push_back
using namespace std;
const int N=1e5+50,inf=1e9+10;
int n,m,a[N],q;
int op[N],l[N],r[N],k[N];LL ans[N];
struct Laz{
    int ad,fl;
    Laz operator +(const Laz &b){
        return Laz{ad+b.ad,fl|b.fl};
    }
}Y;
struct Mes{
    int mx,cnt;LL abc,ab,ac,bc,a,b,c;Laz laz;
    Mes operator +(const Mes &d){
		return Mes{max(mx,d.mx),cnt+d.cnt,abc+d.abc,ab+d.ab,ac+d.ac,bc+d.bc,a+d.a,b+d.b,c+d.c,Y};
    }
    Mes operator +(const Laz &b){
        Mes c=*this;
        if(b.fl&1){
            c.abc=c.ab;
            c.ac=c.a;
            c.bc=c.b;
            c.c=c.cnt;
        }
        if(b.fl&2){
            c.abc=c.ac;
            c.ab=c.a;
            c.bc=c.c;
            c.b=c.cnt;
        }
        if(b.ad){
            c.mx+=b.ad;
            c.abc+=1ll*b.ad*c.bc;
            c.ab+=1ll*b.ad*c.b;
            c.ac+=1ll*b.ad*c.c;
            c.a+=1ll*b.ad*c.cnt;
        }
        c.laz=c.laz+b;
        return c;
    }
}t[N*4],t2[N*4],Z;
void up(int x){
	int L=x<<1,R=x<<1|1;
	if(t[L].mx==t[R].mx)t[x]=t[L]+t[R],t2[x]=t2[L]+t2[R];
	else if(t[L].mx>t[R].mx)t[x]=t[L]+Z,t2[x]=t[R]+t2[L]+t2[R];
	else t[x]=t[R]+Z,t2[x]=t[L]+t2[L]+t2[R];
}
void down(int x){
	int L=x<<1,R=x<<1|1;
    Laz &d=t[x].laz,&d2=t2[x].laz;
    bool fl=t[L].mx>=t[R].mx,fr=t[R].mx>=t[L].mx;
	if(d.fl||d.ad){
        if(fl)t[L]=t[L]+d;
        if(fr)t[R]=t[R]+d;
        d=Y;
    }
	if(d2.fl||d2.ad){
        if(!fl)t[L]=t[L]+d2;
        if(!fr)t[R]=t[R]+d2;
        t2[L]=t2[L]+d2,t2[R]=t2[R]+d2,d2=Y;
    }
}
void build(int x,int l,int r){
	if(l==r){t[x]=Mes{inf,1,0,0,0,0,inf,0,0,Y};t2[x]=Z;return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	up(x);
}
void change1(int x,int l,int r,int ql,int qr){
	if(l>qr||r<ql)return;
	if(l>=ql&&r<=qr){t[x]=t[x]+Laz{0,2};if(t2[x].cnt)t2[x]=t2[x]+Laz{0,2};return;}
	int mid=(l+r)>>1;down(x);
	change1(x<<1,l,mid,ql,qr);
	change1(x<<1|1,mid+1,r,ql,qr);
	up(x);
}
void change2(int x,int l,int r,int ql,int qr,int d){
	if(l>qr||r<ql||d>=t[x].mx)return;
	if(l>=ql&&r<=qr&&d>t2[x].mx){t[x]=t[x]+Laz{d-t[x].mx,1};return;}
	int mid=(l+r)>>1;down(x);
	change2(x<<1,l,mid,ql,qr,d);
	change2(x<<1|1,mid+1,r,ql,qr,d);
	up(x);
}
Mes query(int x,int l,int r,int ql,int qr){
	if(l>qr||r<ql)return Z;
	if(l>=ql&&r<=qr)return t[x]+t2[x];
	int mid=(l+r)>>1;down(x);
	return query(x<<1,l,mid,ql,qr)+query(x<<1|1,mid+1,r,ql,qr);
}
int main(){
    Y=Laz{0,0};Z=Mes{-inf,0,0,0,0,0,0,0,0,Y};
    scanf("%d",&q);n=1e5;
    build(1,1,n);
	for(int i=1;i<=q;i++){
        scanf("%d%d%d",&op[i],&l[i],&r[i]);
        r[i]--;
        if(op[i]==1){
            scanf("%d",&k[i]);
            if(k[i]>0)change2(1,1,n,l[i],r[i],k[i]);
            else change1(1,1,n,l[i],r[i]);
        }
        else{
            ans[i]=query(1,1,n,l[i],r[i]).abc;
            // printf("%lld\n",ans[i]);
        }
    }
    build(1,1,n);
    for(int i=1;i<=q;i++){
        if(op[i]==1){
            k[i]=-k[i];
            if(k[i]>0)change2(1,1,n,l[i],r[i],k[i]);
            else change1(1,1,n,l[i],r[i]);
        }
        else{
            ans[i]+=query(1,1,n,l[i],r[i]).abc;
            printf("%lld\n",ans[i]);
        }
    }
    return 0;
}