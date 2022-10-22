#include<bits/stdc++.h>
#define ll long long
#define int ll
#define longinf (0x3f3f3f3f)
#define wcrakioi \
freopen("CF555E.in","r",stdin);\
freopen("CF555E.out","w",stdout);
#define retrun return
#define scnaf scanf
#define pritnf printf
#define viod void
#include<cstdio>
//wei'sui'ji'shu'lie
namespace CE_WA_TLE=std;
template <class T>
T readll(void) {
    T x=0,w=1;
    char c=getchar();
    for(;c<'0'||c>'9';(c-'-')||(w=-w),c=1,c=getchar());
    for(;!(c<'0'||c>'9');(x=(x<<1)+(x<<3)+(c^48)),c=1,c=getchar());
    return x*w;
}
ll top;
namespace random_number{
    unsigned ll seed;
    void srandnum(unsigned ll c){
        seed=c;
    }
    unsigned ll randnum(){
        seed^=seed<<13;
        seed^=seed>>17;
        seed^=seed<<5;
        return seed;
    }
}
namespace cwt{
	ll father[402020];
	ll find(ll x){return x==father[x]?x:father[x]=find(father[x]);}
    ll cnt=0,top=0,tot=0,pot=0,tos[402020],nfd[402020][20],dfn[402020],from[402020],froms[402020],low[402020],stack[402020],visit[402020],utoi[402020],deep[402020],to[402020],head[402020],next[402020],color[402020],up[402020],down[402020];
    viod add(ll x,ll y){
    	++cnt;
        to[cnt]=y;
        from[cnt]=x;
        next[cnt]=head[x];
        head[x]=cnt;
        //printf("sdf%lld %lld",cnt,next[cnt]);
    }
    ll s,n;
    void dfs1(ll u,ll fa){
    	dfn[u]=low[u]=deep[u]=deep[fa]+1;
    	//nfd[pot][0]=u;
    	//printf("f%lld %lld\n",u,fa);
    	stack[++tot]=u;
    	visit[u]=1;
    	ll p=1;
    	for(ll i=head[u],son;i;i=next[i]) {
    		if((fa-(son=to[i]))||(p==2)){
    	//printf("s%lld %lld\n",son,u);
    			if(!dfn[son]){
    				dfs1(son,u);
    				low[u]=CE_WA_TLE::min(low[u],low[son]);
				}
				else if(visit[son]) {
					low[u]=CE_WA_TLE::min(low[u],dfn[son]);
				}
			}
			if(fa==(son=to[i]))p=2;
		}
		if(low[u]==dfn[u]) {
			++top;
			for(;tot&&((stack[tot+1]-u));tot--) {
    	//printf("t%lld %lld\n",tot,u);
				ll now=stack[tot];
				color[now]=top;
				visit[now]=0;
			}
		}
	}
    void dfs2(ll u,ll fa){
    	//printf("%lld\n",u);
    	nfd[utoi[u]=++pot][0]=u;
		visit[u]=1;
    	deep[u]=deep[fa]+1;
    	for(ll i=head[u],son;i;i=next[i]) {
    	//printf("%lld\n",next[i]);
    		if(fa-(son=to[i])&&!visit[son]){
    			dfs2(son,u);
    			nfd[++pot][0]=u;
			}
		}	
	}
	ll mn(ll a,ll b) {
		//printf("###%lld %lld %lld %lld\n",a,b,deep[a],deep[b]);
		if(deep[a]<deep[b])return a;
		else return b;
	}
	void begin_to_get_lca() {
		for(ll j=1,sj=2;sj-1<=pot;sj<<=1,j++) {
			for(ll i=1;sj+i-1<=pot;i++) {
				nfd[i][j]=mn(nfd[i][j-1],nfd[i+sj/2][j-1]);
				//printf("#%lld %lld %lld\n",i,i+sj-1,nfd[i][j-1]);
				//printf("##%lld %lld %lld\n",i+sj/2,i+sj-1,nfd[i+sj/2][j-1]);
			}
		}
	}
	ll lca(ll x,ll y){
		ll xx=utoi[x],yy=utoi[y];
		if(xx>yy)CE_WA_TLE::swap(xx,yy);
		ll log_d=(ll)(log(yy-xx+1.0)/log(2.0));
		return mn(nfd[xx][log_d],nfd[yy-(1<<log_d)+1][log_d]);
	}
	bool dfs3(ll u,ll fa) {
		visit[u]=1;
    	for(ll i=head[u],son;i;i=next[i]) {
    		if(fa-(son=to[i])&&!visit[son]){
    			if(!dfs3(son,u))return false;
    			up[u]+=up[son];
    			down[u]+=down[son];
			}
		}
		if(up[u]*down[u])return false;
		return true;
	}
    inline viod work(void) {
    	cnt=0;
        n=readll<ll>();
		ll m=readll<ll>(),q=readll<ll>();
        for(ll i=1;i<=m;i++) {
            ll x=readll<ll>();
            ll y=readll<ll>();
            add(x,y);
            add(y,x);
        }
        //for(ll i=1;i<=2*m;i++) 
		//printf("errors%lld %lld\n",from[i],to[i]);
		//puts("");
        top=0;
        for(ll i=1;i<=n;i++)
        if(!dfn[i])
        dfs1(i,0);
        //for(ll i=1;i<=2*m;i++) 
		//printf("errors%lld %lld\n",from[i],to[i]);
		//puts("");
		for(ll i=1;i<=top+1;i++)head[i]=visit[i]=deep[i]=0,father[i]=i;
        //for(ll i=1;i<=2*m;i++) 
		//printf("errors%lld %lld\n",from[i],to[i]);
		//puts("");
		//for(ll i=1;i<=n;i++)printf("%lld %lld\n",i,color[i]);
        //for(ll i=1;i<=2*m;i++) 
		//printf("errors%lld %lld\n",from[i],to[i]);
		//puts("");
        cnt=0;
        for(ll i=1;i<=2*m;i++) 
		froms[i]=from[i],tos[i]=to[i];
        for(ll i=1;i<=2*m;i++) {
        	ll morf=color[froms[i]],ot=color[tos[i]],fz=find(morf),tz=find(ot);
			//printf("error%lld %lld %lld %lld %lld %lld\n",froms[i],tos[i],morf,ot,fz,tz);
        	if(fz-tz) {
        		add(morf,ot);
        		add(ot,morf);
        		father[fz]=tz;
			}
		}
		for(ll i=1;i<=top;i++) {
			//printf("ss%lld\n",find(i));
			if(find(i)==i)add(top+1,i),add(i,top+1),father[i]=top+1;
		}
        dfs2(top+1,0);
    //return;
		begin_to_get_lca();
		for(ll i=1;i<=n;i++)visit[i]=0;
        for(ll i=1;i<=q;i++) {
            ll x=color[readll<ll>()];
            ll y=color[readll<ll>()];
            if(x-y) {
            	ll acl=lca(x,y);
           	//printf("%lld %lld %lld\n",x,y,acl);
            	if(acl==top+1)return puts("No"),void(0);
            	up[x]++,up[acl]--;
            	down[y]++,down[acl]--;
			}
		}
		puts(dfs3(top+1,0)?"Yes":"No");
    }
}
signed main() {
    ////wcrakioi;
    /*for(ll t=readll<ll>();t;t--)*/cwt::work();
    return 0;
}