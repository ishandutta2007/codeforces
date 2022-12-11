#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50,M=2e7;
int n,cnt=1,lst=1,trans[N][26],par[N],mxlen[N],lc[M],rc[M],rt[N],tot,d[N],st[N],tp;char s[N];
int f[N][20],pos[N],ans[N],anss;
vector<int>v[N];
void extend(int c){
    int p=lst,cur=++cnt;lst=cur;
    mxlen[cur]=mxlen[p]+1;
    for(;p&&!trans[p][c];p=par[p])trans[p][c]=cur;
    if(!p)par[cur]=1;
    else{
        int q=trans[p][c];
        if(mxlen[q]==mxlen[p]+1)par[cur]=q;
        else{
            int nq=++cnt;
            memcpy(trans[nq],trans[q],sizeof(trans[q]));
            mxlen[nq]=mxlen[p]+1;par[nq]=par[q];
            for(;p&&trans[p][c]==q;p=par[p])trans[p][c]=nq;
            par[q]=par[cur]=nq;
        }
    }
}
void change(int &x,int l,int r,int p){
    x=++tot;
    if(l==r)return;int mid=(l+r)>>1;
    if(p<=mid)change(lc[x],l,mid,p);
    else change(rc[x],mid+1,r,p);
}
int merge(int x,int y,int l,int r){
    if(!x||!y)return x^y;
    int z=++tot,mid=(l+r)>>1;
    if(l!=r)lc[z]=merge(lc[x],lc[y],l,mid),
            rc[z]=merge(rc[x],rc[y],mid+1,r);
    return z;
}
bool query(int x,int l,int r,int ql,int qr){
    if(!x)return 0;if(l>=ql&&r<=qr)return 1;
    int mid=(l+r)>>1,ret=0;
    if(ql<=mid)ret=query(lc[x],l,mid,ql,qr);
    if(qr>mid)ret|=query(rc[x],mid+1,r,ql,qr);
    return ret;
}
void dfs(int x){
    if(x!=1){
        int y=x;
        for(int i=18;~i;i--){
            int z=f[y][i];
            if(z&&!query(rt[z],1,n,pos[x]-mxlen[x]+mxlen[z],pos[x]-1))y=z;
        }
        anss=max(anss,ans[x]=ans[f[y][0]]+1);
    }
    for(int i=0,y;i<v[x].size();i++)dfs(v[x][i]);
}
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)extend(s[i]-'a'),change(rt[lst],1,n,i),pos[lst]=i;
    for(int i=2;i<=cnt;i++)d[par[i]]++,f[i][0]=par[i],v[par[i]].push_back(i);
    for(int i=2;i<=cnt;i++)if(!d[i])st[++tp]=i;
    while(tp){
        int x=st[tp--],y=par[x];
        pos[y]=pos[x];rt[y]=merge(rt[y],rt[x],1,n);
        if(!--d[y])st[++tp]=y;
    }
    for(int i=0;i<18;i++)
        for(int j=2;j<=cnt;j++)
            f[j][i+1]=f[f[j][i]][i];
    dfs(1);cout<<anss;
    return 0;
}