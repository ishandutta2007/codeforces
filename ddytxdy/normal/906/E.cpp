#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,inf=0x3f3f3f3f;
int T,n,tp[2];char s[N],a[N],b[N];
struct node{int s,d,sz;int mx(){return s+d*(sz-1);}}st[2][N];
struct Mes{
    int val,fr;
    bool operator <(const Mes &b)const{
        return val!=b.val?val<b.val:fr<b.fr;
    }
    Mes ad(){return (Mes){val+1,fr};}
}f[N],g[N];
void cmin(Mes &x,Mes y){y<x?x=y,0:0;}
void ins1(node *st,int &tp,int x){
    if(!tp)st[++tp]=(node){x,inf,1};
    else{
        int d=x-st[tp].mx();
        if(d==st[tp].d)st[tp].sz++;
        else st[++tp]=(node){x,d,1};
    }
}
void ins2(node *st,int &tp,node x){
    if(tp&&st[tp].d==x.d)st[tp].sz+=x.sz;
    else st[++tp]=x;
}
void trans(node *s1,node *s2,int &t1,int &t2,char c){
    t2=0;
    for(int i=1;i<=t1;i++)
        if(c==s[s1[i].s-1]){
            ins1(s2,t2,s1[i].s-1);
            if(s1[i].sz!=1)ins2(s2,t2,(node){s1[i].s+s1[i].d-1,s1[i].d,s1[i].sz-1});
        }
}
int main(){
    scanf("%s%s",a+1,b+1);n=strlen(a+1);
    for(int i=1;i<=n;i++)s[i*2-1]=a[i],s[i*2]=b[i];n*=2;
    for(int i=1;i<=n;i++)f[i]=g[i]=(Mes){inf,0};
    for(int i=1,p=1,q=0;i<=n;i++,p^=1,q^=1){
        trans(st[p],st[q],tp[p],tp[q],s[i]);
        if(i>1&&s[i]==s[i-1])ins1(st[q],tp[q],i-1),f[i]=(Mes){f[i-2].val,i-2};
        ins1(st[q],tp[q],i);//if(i&1)continue;
        node *a=st[q];
        if(tp[q]&&!(i&1)&&(a[1].s&1))cmin(f[i],(Mes){f[a[1].s-1].val+1,a[1].s-1});
        for(int j=2;j<=tp[q];j++){
            int d=a[j].d,id=a[j].s-d;
            if(a[j].sz==1)g[id]=(Mes){inf,0};
            if(a[j].mx()&1)cmin(g[id],(Mes){f[a[j].mx()-1].val+1,a[j].mx()-1});
            if(!(i&1))cmin(f[i],g[id]);
        }
    }
    if(f[n].val==inf)puts("-1"),exit(0);
    printf("%d\n",f[n].val);int x=n;
    while(x){
        if(f[x].fr!=x-2)printf("%d %d\n",f[x].fr/2+1,x/2);
        x=f[x].fr;
    }
    return 0;
}