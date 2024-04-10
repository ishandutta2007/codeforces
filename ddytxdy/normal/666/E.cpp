#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int N=1e5+50,M=1e6+50,K=M*4;
int m,q,mxlen[N],trans[N][26],par[N],cnt=1,lst=1,rt[N],tot,lc[K],rc[K];char s[M],t[N];
int d[N],st[N],tp,f[N][18];
struct node{
    int l,r,pl,pr,id;
    void init(int x){scanf("%d%d%d%d",&l,&r,&pl,&pr);id=x;}
    bool friend operator <(node a,node b){return a.pr<b.pr;}
}Q[M];
pii dat[K],ans[M];
void extend(int c){
    int cur=0,p=lst;if(!trans[p][c])lst=cur=++cnt;
    for(;p&&!trans[p][c];p=par[p])trans[p][c]=cur;
    if(!p)par[cur]=1;
    else{
        int q=trans[p][c];
        if(mxlen[q]==mxlen[p]+1)cur?par[cur]=q:lst=q;
        else{
            int nq=++cnt;
            memcpy(trans[nq],trans[q],sizeof(trans[q]));
            mxlen[nq]=mxlen[p]+1;par[nq]=par[q];
            for(;p&&trans[p][c]==q;p=par[p])trans[p][c]=nq;
            par[q]=nq;cur?par[cur]=nq:lst=nq;
        }
    }
}
void change(int &x,int l,int r,int p){
    if(!x)x=++tot;
    if(l==r){dat[x].fi++;dat[x].se=-l;return;}
    int mid=(l+r)>>1;
    if(p<=mid)change(lc[x],l,mid,p);
    else change(rc[x],mid+1,r,p);
    dat[x]=max(dat[lc[x]],dat[rc[x]]);
}
int merge(int x,int y,int l,int r){
    if(!x||!y)return x|y;
    int z=++tot,mid=(l+r)>>1;
    if(l==r)dat[z].fi=dat[x].fi+dat[y].fi,dat[z].se=-l;
    else{
        lc[z]=merge(lc[x],lc[y],l,mid);
        rc[z]=merge(rc[x],rc[y],mid+1,r);
        dat[z]=max(dat[lc[z]],dat[rc[z]]);
    }
    return z;
}
pii query(int x,int l,int r,int ql,int qr){
    if(!x||l>=ql&&r<=qr)return dat[x];
    int mid=(l+r)>>1;
    if(qr<=mid)return query(lc[x],l,mid,ql,qr);
    if(ql>mid)return query(rc[x],mid+1,r,ql,qr);
    return max(query(lc[x],l,mid,ql,qr),query(rc[x],mid+1,r,ql,qr));
}
int main(){
    scanf("%s%d",s+1,&m);
    for(int i=1;i<=m;i++){
        scanf("%s",t+1);int p=strlen(t+1);lst=1;
        for(int j=1;j<=p;j++)extend(t[j]-'a'),change(rt[lst],1,m,i);
    }
    for(int i=2;i<=cnt;i++)d[par[i]]++,f[i][0]=par[i];
    for(int i=0;i<16;i++)
        for(int j=2;j<=cnt;j++)
            f[j][i+1]=f[f[j][i]][i];
    for(int i=1;i<=cnt;i++)if(!d[i])st[++tp]=i;
    while(tp){
        int x=st[tp--],y=par[x];
        rt[y]=merge(rt[y],rt[x],1,m);
        if(!--d[y])st[++tp]=y;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)Q[i].init(i);
    sort(Q+1,Q+q+1);
    for(int i=1,j=0,nowp=1,len=0;i<=q;i++){
        while(j<Q[i].pr){
            int c=s[++j]-'a';
            while(nowp!=1&&!trans[nowp][c])
                nowp=par[nowp],len=mxlen[nowp];
            if(trans[nowp][c])len++,nowp=trans[nowp][c];
        }
        int L=Q[i].pr-Q[i].pl+1;
        if(len<L){ans[Q[i].id]=make_pair(0,-Q[i].l);continue;}
        int P=nowp;
        for(int k=16;~k;k--)if(mxlen[f[P][k]]>=L)P=f[P][k];
        ans[Q[i].id]=query(rt[P],1,m,Q[i].l,Q[i].r);
        if(!ans[Q[i].id].fi)ans[Q[i].id].se=-Q[i].l;
    }
    for(int i=1;i<=q;i++)printf("%d %d\n",-ans[i].se,ans[i].fi);
    return 0;
}