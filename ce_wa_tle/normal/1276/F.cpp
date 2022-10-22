#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=4e5+9,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define log LOG
bool p1;
aN log;
struct tree{
    aN next,to,head,st[22],deep,dfn,c;ll top,cnt;tree():top(0),cnt(0){}
    void add(ll u,ll v,ll w){/*printf("%lld %lld %lld\n",u,v,w);*/next[++cnt]=head[u],to[head[u]=cnt]=v,c[cnt]=w;}
    ll min_2(ll x,ll y)const{return deep[x]<deep[y]?x:y;} 
    void dfs(ll u,ll fa,ll w){
    //printf("dfs%lld %lld %lld\n",u,fa,w);
        deep[u]=deep[fa]+w;rfor(ll i=head[st[0][dfn[u]=++top]=u],v;v=to[i],i;i=next[i])
        if(v^fa)dfs(v,u,c[i]),st[0][++top]=u;
    }void calc(){
        dfs(0,0,1);if(!log[top])rep(i,2,top)log[i]=log[i>>1]+1;//rep(i,1,top)printf("d=%lld\n",deep[st[0][i]]);
        rep(j,1,log[top])rep(i,1,top-(1<<j)+1)st[j][i]=min_2(st[j-1][i],st[j-1][i+(1<<(j-1))]); 
    }ll lca(ll u,ll v){
        if(!u||!v)return 0;if(u>v)std::swap(u,v);ll s=log[v-u+1];return min_2(st[s][u],st[s][v-(1<<s)+1]);
    }
}tr;
struct ifm{int lf,rt;ll sum;};struct node{ifm val;ll ls,rs;}sgm[N<<4];
ifm operator+(const ifm&a,const ifm&b){
    return(ifm){a.lf?:b.lf,b.rt?:a.rt,a.sum+b.sum-(int)(a.lf&&b.rt?tr.deep[tr.lca(a.rt,b.lf)]:0)};
}
struct segment{
    aN root;ll cnt;segment():cnt(0){}
    void insert(ll&u,ll l,ll r,ll q){
        u=u?:++cnt;if(l==r){sgm[u].val.sum=tr.deep[tr.st[0][sgm[u].val.lf=sgm[u].val.rt=q]];return;}
        ll mid=(l+r)>>1;q<=mid?insert(sgm[u].ls,l,mid,q):insert(sgm[u].rs,mid+1,r,q);
        sgm[u].val=sgm[sgm[u].ls].val+sgm[sgm[u].rs].val;
    }void merge(ll&u,ll v,ll w){
        u=!v||!w?v|w:++cnt;if(v&&w)merge(sgm[u].ls,sgm[v].ls,sgm[w].ls),merge(sgm[u].rs,sgm[v].rs,sgm[w].rs),
        sgm[u].val=sgm[sgm[u].ls].val+sgm[sgm[u].rs].val;;
    }void insert(ll u,ll c){insert(root[u],1,tr.top,tr.dfn[c]);}
    void merge(ll u,ll v){if(!v)return;/*printf("%lld %lld\n",u,v);*/merge(root[u],root[u],root[v]);}
}t;
struct sam{
    aN len,v[26],link,itov;ll cnt,cur;sam():cnt(0),cur(0){link[0]=-1;}
    ll insert(int c){
        ll p=cur,q=0,*son=v[c-'a'];for(len[cur=++cnt]=len[p]+1;~p&&!son[p];son[p]=cur,p=link[p]);
        if(!~p||len[p]+1==len[q=son[p]])return link[cur]=q,cur;link[link[cur]=++cnt]=link[q],link[q]=cnt;
        rep(i,0,25)v[i][cnt]=v[i][q];for(len[cnt]=len[p]+1;~p&&son[p]==q;son[p]=cnt,p=link[p]);return cur;
    }
}z,f;char s[N];int cmp(ll a,ll b){return z.len[a]>z.len[b];}aN p;bool p2;
int main(){//IO(1276F);
//fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0);
    scanf("%s",s+1);ll n=strlen(s+1),sum=1,x;rep(i,1,n)z.itov[i]=x=z.insert(s[i]),sum+=z.len[x]-z.len[z.link[x]];
    //printf("%lld\n",sum); 
    per(i,n,1)/*printf("%lld\n",*/f.itov[i]=x=f.insert(s[i])/*)*/;
    rep(i,1,f.cnt)tr.add(f.link[i],i,f.len[i]-f.len[f.link[i]]);tr.calc();
    rep(i,0,n-1)t.insert(z.itov[i],f.itov[i+2]);rep(i,0,z.cnt)p[i]=i;std::sort(p+1,p+z.cnt+1,cmp);
    rep(i,0,z.cnt)t.merge(z.link[p[i]],p[i]);rep(i,0,z.cnt)sum+=(z.len[i]-z.len[z.link[i]]+!i)*sgm[t.root[i]].val.sum
    /*,printf("%lld %lld\n",(z.len[i]-z.len[z.link[i]]),sgm[t.root[i]].val.sum)*/;printf("%lld\n",sum);
    return 0;
}