#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define log fsjkfl
#define lca(u,v) dfsaj(u,v)
bool p1;typedef int ll;const ll N=1e5+7,inf=998244353;typedef ll aN[2*N],a40N[140*N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,w;ll cnt=0;void add(ll u,ll v,int c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
struct ds{
    a40N val,ls,rs;aN root;ll cnt,n;void set(ll n_){cnt=0,n=n_;}
    void update(ll&u,ll l,ll r,ll q,ll c){
        if(!u)u=++cnt;if(l==r){val[u]+=c;return;}ll mid=(l+r)>>1;
        if(q<=mid)update(ls[u],l,mid,q,c);else update(rs[u],mid+1,r,q,c);val[u]=val[ls[u]]+val[rs[u]];
    }void update(ll u,ll q,ll c){/*printf("[%d][%d]+=%d\n",u,q,c);*/update(root[u],1,n,q,c);}
    ll mg(ll u,ll v){
        if(!u||!v)return u^v;ll w=++cnt;val[w]=val[u]+val[v];return ls[w]=mg(ls[u],ls[v]),rs[w]=mg(rs[u],rs[v]),w;
    }void merge(ll u,ll v){/*printf("[%d]+=[%d]\n",u,v);*/root[u]=mg(root[u],root[v]);}
    ll query(ll u,ll l,ll r,ll ql,ll qr)const{
        if(!u||r<ql||qr<l)return 0;if(ql<=l&&r<=qr)return val[u];ll mid=(l+r)>>1;
        return query(ls[u],l,mid,ql,qr)+query(rs[u],mid+1,r,ql,qr);
    }ll query(ll u,ll l,ll r){return l<=r&&u?query(root[u],1,n,l,r):0;}
}t;
struct SAM{typedef ll aN[2*N];
    aN len,v[26],link,cur,q;ll cnt;SAM():cnt(0){link[0]=-1;}
    ll insert(ll p,int c){//printf("--------------->%d %c\n",p,c);
        ll*son=v[c-'a'],q,u,t;if(len[p]+1==len[q=son[p]])return q;len[u=++cnt]=len[p]+1;
        if(q){ref(i,0,26)v[i][u]=v[i][q];for(link[u]=link[q];~p&&son[p]==q;son[p]=u,p=link[p]);return link[q]=u;}
        for(;~p&&!son[p];son[p]=u,p=link[p]);if(!~p||len[p]+1==len[q=son[p]])return link[u]=q,u;link[t=++cnt]=link[q];
        link[q]=link[u]=t;ref(i,0,26)v[i][t]=v[i][q];for(len[t]=len[p]+1;~p&&son[p]==q;son[p]=t,p=link[p]);return u;
    }void bfs(){
        rfor(ll h=1,t=q[1]=1,u;h<=t;)rfor(ll i=head[u=q[h++]];i;i=next[i])
        if(to[i]!=1&&!cur[to[i]])cur[q[++t]=to[i]]=insert(cur[u],w[i])/*,print()*/;
    }ll getw(char*s){ll u=v[*++s-'a'][0];while(*++s&&u)u=v[*s-'a'][u];return u;}
}sam;int cmp(ll x,ll y){return sam.len[x]<sam.len[y];}
ll t1=0,t2=0,*ix[N];aN st[23],in,out,dfn,l,son,f[23],deep,nxt,top,upc,log,p;
void dfs0(ll u,ll fa){
    st[0][dfn[u]=++t1]=u,in[u]=++t2,deep[u]=deep[f[0][u]=fa]+1,l[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])
    if(v^fa)dfs0(v,u),upc[v]=w[i],st[0][++t1]=u,l[v]>=l[u]&&(l[u]=l[son[u]=v]+1);out[u]=++t2;
}ll min2(ll u,ll v){return deep[u]<deep[v]?u:v;}ll t3=0;aN h;
void dfs2(ll u,ll fa){//h+t3+l[u]-deep[u]==ix
    son[fa]!=u?ix[top[u]=u]=h+t3+l[u]-deep[u],t3+=(l[u]<<1)-1:ix[top[u]=top[fa]][deep[u]]=u;
    if(top[u]==u){ll now=u;rep(i,1,l[u])ix[u][deep[now]]=now,now=f[0][now];}
    if(son[u])dfs2(son[u],u);rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa&&v^son[u])dfs2(v,u);
}ll lca(ll u,ll v){
    if((u=dfn[u])>(v=dfn[v]))std::swap(u,v);ll lg=log[v-u+1];return min2(st[lg][u],st[lg][v-(1<<lg)+1]);
}ll kfa(ll u,ll k){return k?ix[top[f[log[k]][u]]][deep[u]-k]:u;}char s[N],e[N],g[N];bool p2;
ll kmp(char*s,char*t){//s in t
    ll ns=strlen(s+1),nt=strlen(t+1),flag=0;nxt[1]=0;
    rfor(ll i=2,j=0;i<=ns;i++){while(j&&s[j+1]!=s[i])j=nxt[j];nxt[i]=s[j+1]==s[i]?++j:j;}
    rfor(ll i=1,j=0;i<=nt;i++){while(j&&s[j+1]!=t[i])j=nxt[j];if((s[j+1]==t[i]?++j:j)==ns)flag++,j=nxt[j];}return flag;
}int main(){fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0);
    ll n=readll(),u,v;int c;rep(i,2,n)u=readll(),v=readll(),c=readchar(),add(u,v,c),add(v,u,c);sam.bfs();//sam.print();
    dfs0(1,0),dfs2(1,0);rep(i,2,t1)log[i]=log[i>>1]+1;rep(i,1,log[n])rep(j,1,n)f[i][j]=f[i-1][f[i-1][j]];
    t.set(t2);rep(i,1,log[t1])rep(j,1,t1-(1<<i)+1)st[i][j]=min2(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    rep(i,1,n)t.update(sam.cur[i],in[i],1),t.update(sam.cur[i],out[i],-1);rep(i,1,sam.cnt)p[i]=i;
    std::sort(p+1,p+sam.cnt+1,cmp);per(i,sam.cnt,1)t.merge(sam.link[p[i]],p[i]);ll m=readll();//if(n>=60000)exit(0);
    rep(i,1,m){
        ll u=readll(),v=readll(),lca=lca(u,v);scanf("%s",s+1);ll n=strlen(s+1);rep(i,1,n)e[i]=s[n-i+1];e[n+1]=g[1]=0;
        ll u_=kfa(u,std::max(0,deep[u]-deep[lca]-n)),v_=kfa(v,std::max(0,deep[v]-deep[lca]-n)),
        fu=deep[u_]-deep[lca]==n?f[0][u_]:u_,fv=deep[v_]-deep[lca]==n?f[0][v_]:v_; 
        ll top=0;rfor(ll w=fu;deep[w]>deep[lca];w=f[0][w])g[++top]=upc[w];top+=deep[fv]-deep[lca],g[top+1]=0;
        rfor(ll w=fv;deep[w]>deep[lca];w=f[0][w])g[top--]=upc[w];
        printf("%d\n",t.query(fv==v_?0:sam.getw(s),in[v_],in[v])+t.query(fu==u_?0:sam.getw(e),in[u_],in[u])+kmp(s,g));
    }return 0;
}/*if(l!=r)printf("[%lld][%lld,%lld]=%lld\n",u,l,r,u?query(root[u],1,n,l,r):0);*/
//        printf("%lld %lld %lld\n",t.query(sam.getw(s),in[v_],in[v]),t.query(sam.getw(e),in[u_],in[u]),kmp(s,g));
//    rep(i,1,n)printf("%lld ",top[i]);rep(i,1,n)if(top[i]==i)
//    {rep(j,deep[i]-l[i]+1,deep[i]+l[i]-1)printf("%lld %lld %lld\n",i,j,ix[i][j]);}puts("");
//        top=g[1]=0;rfor(ll w=u;deep[w]>deep[lca];w=f[0][w])g[++top]=upc[w];top+=deep[v]-deep[lca],g[top+1]=0;
//        rfor(ll w=v;deep[w]>deep[lca];w=f[0][w])g[top--]=upc[w];
//        printf("%d\n",kmp(s,g));
//    void print()const{
//        rep(i,0,cnt){printf("node %d:%d %d\n",i,len[i],link[i]);
//        rep(j,0,25)if(v[j][i])printf("-%c->%d\n",(int)j+'a',v[j][i]);}
//    }
//        printf("%d %d\n",sam.getw(s),sam.getw(e));puts(s+1);puts(e+1);puts(g+1); 
//        printf("u=%d v=%d lca=%d u_=%d v_=%d n=%d [%d,%d] [%d,%d] %d %d\n",u,v,lca,u_,v_,n,in[v_],in[v],in[u_],in[u],fu,fv);
//    rep(i,1,n)printf("%d %d\n",in[i],out[i]);
//    rep(i,0,sam.cnt){rep(j,1,t2)printf("%d ",t.query(i,j,j));puts("");}