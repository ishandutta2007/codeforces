#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef unsigned long long ull;const ll N=216333,e7=1e7+7,inf=1e17,mod=1e9+7;typedef ll aN[N];
ll iabs(ll a){return a<0?-a:a;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct hash{
    const static ll mod=19260817;
    #define hss ll now=b%mod,k=0;while(key[now]&&key[now]!=b)now=(now+2*k+++1)%mod
    ll val[mod];ll key[mod];int count(ll b)const{hss;return!!key[now];}
    ll operator[](ll b)const{hss;return key[now]?val[now]:0;}
    ll&operator[](ll b){hss;return!key[now]?key[now]=b,val[now]:val[now];}
}hs;ll n,m;ll a[500][500],db=0;
ll query(ll i,ll j){
    ll id=i*m+j+1;return!hs.count(id)?printf("? %lld %lld\n",i+1,j+1),fflush(stdout),hs[id]=db?a[i][j]:readll():hs[id];
}
ll pre[114514],nxt[114514],s[1145141],&p=nxt[114513];
struct lk{void reset(ll n){ref(i,0,n)nxt[pre[i+1]=i]=i+1;nxt[pre[0]=114513]=0;}void del(ll x){/*printf("d=%lld\n",x);*/nxt[pre[nxt[x]]=pre[x]]=nxt[x];}}t;
#define X(i) (i)*dX
#define Y(i) Y[i]
#define qnow(i,j) query(X(i),Y(j)) 
void reduce(ll dX,std::vector<ll>&Y){
    ll n=~-::n/dX+1,m=Y.size()/*,p=0*/;t.reset(m);//printf("r=%lld %lld\n",n,m);
    rfor(ll delta=m-n,x=0,y=0;delta>0;){
        if(qnow(x,y)>qnow(x,nxt[y]))t.del(pre[y=nxt[y]]),x?--x,y=pre[y]:0,delta--;
        else x==n-1?t.del(nxt[y]),delta--:y=nxt[x++,y];
//        printf("%lld %lld %lld %lld %lld\n",x,y,n,m,delta);
    }std::vector<ll>res;rfor(ll i=p;i<m;i=nxt[i])res.push_back(Y(i))/*,printf("l=%lld %lld\n",X((res.size()-1)),Y(i))*/;Y=res;//if(n<m)exit(0);
//    ref(i,1,n)
}ll min[1145141];
void SMAWK(ll dX,std::vector<ll>Y){
    reduce(dX,Y);ll n=~-::n/dX+1,m=Y.size();/*printf("s=%lld %lld %lld\n",dX,n,m);*/if(n==1){min[X(0)]=Y(0);return;}
    SMAWK(dX*2,Y);ll l=0,r=0;ref(i,0,n)if(i%2){
//        printf("%lld %lld %lld\n",i,n,m);
        while(Y(l)<min[X(i-1)])l++;r=l;while(r<m-1&&Y(r+1)<=(i==n-1?::m-1:min[X(i+1)]))r++;
        min[X(i)]=l;rep(j,l+1,r)if(qnow(i,j)<qnow(i,min[X(i)]))min[X(i)]=j/*,printf("??")*/;min[X(i)]=Y(min[X(i)]);
//        printf("%lld :min[%lld]<-%lld %lld %lld\n",dX,X(i),min[X(i)],l,r);
    }
}
int main(){
    n=readll(),m=readll();if(db)ref(i,0,n)ref(j,0,m)a[i][j]=readll();std::vector<ll>Y;rep(i,0,m-1)Y.push_back((ll)i);SMAWK(1,Y);
    ll ans=inf;ref(i,0,n)ans=std::min(ans,query(i,min[i]))/*,printf("min[%lld]=%lld\n",i,min[i])*/;printf("! %lld\n",ans),fflush(stdout);return 0;
}
/*
4 4
1 2 3 4
2 7 3 4
1 2 1 4
4 3 9 0
*/