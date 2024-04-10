#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;n;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e5+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(cll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
cll IO_res=IO();
//cll n=100000,S=0,C=100000,T=100000;
cll n=readll(),S=readll(),C=readll(),T=readll();
cll K=n/sqrt(T);
struct que{
    ll l,r,id;
    void read(cll i){
        l=readll(),r=readll(),id=i;
        //l=rand()%n+1,r=rand()%n+1,id=i;
        //if(l>r)std::swap(l,r);
    }
    operator ll()const{
        return(l/K)*mod+(((l/K)&1)?-r:r);
    }
}q[N];
bool p1; 
aN p,m,s[67],a,tt,res;
ll num[67],hz[333];
std::map<ull,ll>ma;
cll A=41,B=313;
ll count[1<<20];
ll tp[333];
struct bitset{
    ull val[23];
    int z[23];
    void merge(const bitset&a,const bitset&b){
        ref(i,0,22)val[i]=a.val[i]|b.val[i];
    }
    void init(){
        ll x=0;
        ref(i,0,22)z[i]=x,x+=__builtin_popcountll(val[i]);
    }
    void set(cll u){
        val[u>>6]|=1ull<<(u&63);
    }
    ll query(cll u)const{
        return z[u>>6]+__builtin_popcountll(val[u>>6]<<(63-(u&63)));
    }
}lf[1<<10],rt[1<<10];
void add(cll u){
    cll x=m[u];
    x>64&&!tt[x]++&&--tp[C/p[x]];
}
void del(cll u){
    cll x=m[u];
    x>64&&!--tt[x]&&++tp[C/p[x]];
}
ll G[20];
bool p2;
int main(){
    //fprintf(stderr,"%fMiB\n",(&p2-&p1)/1048576.0);
    {
        ll*t=p,k,z=0;
        rep(i,2,1e5){
            if(!p[i])*t++=i,m[i]=z++;
            rfor(ll*j=p;j!=t&&(k=i**j)<=1e5;j++){
                p[k]=1,m[k]=m[i];
                if(i%*j==0)break;
            }
        }
        rfor(ll*i=p+65;i!=t;)++tp[C/ *i++];
    }
    ll small=0,mid=0;
    ref(i,0,10)rfor(ll j=p[i];j<=1408;j+=p[i])if(m[j]<65)lf[1<<i].set(j);
    ref(i,0,10)rfor(ll j=p[i+10];j<=1408;j+=p[i+10])if(m[j]<65)rt[1<<i].set(j);
    ref(i,3,1<<10)if(i&~-i)lf[i].merge(lf[i&~-i],lf[i&-i]),rt[i].merge(rt[i&~-i],rt[i&-i]);
    rep(i,2,C)if(m[i]<=19){
        ll S=0;
        rfor(ll x=i,j=m[x];x!=1;j=m[x/=p[j]])S|=1<<j;
        //printf("S=%lld\n",S);
        count[(1<<20)-1-S]++,small++;
    }else if(m[i]<=64&&++mid)rfor(ll x=i,lst=0,j=m[x];j>19;lst=j,j=m[x/=p[j]])j!=lst&&++num[j];
    rfor(ll i=1;i!=1<<20;i<<=1)rfor(ll*j=count;j!=count+(1<<20);j+=i<<1)
    rfor(ll*x=j,*y=j+i;x!=j+i;)*x+++=*y++;
    //writell(count[0]);
    rep(i,1,n)a[i]=readll();
    //rep(i,1,n)a[i]=rand();
    rep(i,0,64)rep(j,1,n)s[i][j]=s[i][j-1]+(a[j]%p[i]==0);
    rep(i,1,T)q[i].read(i);
    std::sort(q+1,q+T+1);
    ll l=1,r=0;
    cll up=std::max(71ll,C/p[65]);
    rep(i,20,64){
        cll Z=C/p[i];
        rep(j,i+1,64)G[Z/p[j]]++;
    }
    per(i,18,1)G[i]+=G[i+1];
    rep(i,1,T){
        while(r<q[i].r)add(a[++r]);
        while(l>q[i].l)add(a[--l]);
        while(r>q[i].r)del(a[r--]);
        while(l<q[i].l)del(a[l++]);
        hz[1]=1;
        ll*now=p,z=0,ans=mid+tp[1],S=0,shz=1;
        ll st[67],t=0,k;
        bitset bS;
        #if 0
        {
            ll scnt=0;
            rep(i,1,C)if(m[i]>=20&&m[i]<=64&&i%2!=0/*&&m[i/p[m[i]]]>=20&&m[i]!=m[i/p[m[i]]]*/)scnt++;
            writell(scnt,10);
            ll gcnt=mid;
            lf[1].init();
            rep(i,20,64)gcnt-=lf[1].query(C/p[i]);//rep(j,1,C/p[i])if(m[j]<=64)gcnt-=j%2==0;
            //ll gcnt=0;
            rep(i,1,18)if(i%2==0)gcnt+=G[i];
            writell(gcnt,10);
        }
        {
            ll scnt=0;
            rep(i,1,C)if(m[i]>=65&&i%2!=0/*&&m[i/p[m[i]]]>=20&&m[i]!=m[i/p[m[i]]]*/)scnt++;
            writell(scnt,10);
            ll gcnt=0;//,x=0;
            ll zt[999]={};
            rep(i,p[65],C)if(p[m[i]]==i){/*gcnt+=(C/i+1)/2;*/++zt[C/i];}
            rep(i,1,331)assert(tp[i]==zt[i]);
            writell(p[64]);
            //rep(i,p[65],C)if(p[m[i]]==i)gcnt+=;
            rep(i,1,332)gcnt+=(i+1)/2*zt[i];
            writell(gcnt,10);
        }
        #endif
        rep(i,2,std::max(p[64],up)){
            if(i==*now){
                now++,hz[i]=s[z][r]==s[z][l-1];
                if(z<20&&!hz[i])S|=1<<z;
                if(z>19)ans-=!hz[i]?st[++t]=i,num[z]:bS.query(C/i);//,printf("%lld %lld\n",C/i,bS.query(C/i));
                z++;
            }
            if(i>up){
                i=(*now-1);
                continue;
            }
            rfor(ll*j=p;j!=now&&(k=i**j)<=up;j++){
                hz[k]=hz[i]&&hz[*j];
                if(i%*j==0)break;
            }
            if(i==p[19])ans+=count[S],bS.merge(lf[S&1023],rt[S>>10]),bS.init();
            ans+=(shz+=hz[i])*tp[i];
        }
        ll cs=t;
        //writell(ans,10);
        rep(i,1,19)if(hz[i]){
            while(cs&&st[cs]*i*st[1]>C)cs--;
            if(!cs)continue;
            ll j=cs;
            rep(k,1,t){
                while(j&&st[j]*i*st[k]>C)j--;
                if(!j)break;
                ans+=std::min(k-1,j);
                //printf("j=%lld\n",j);
            }
        }
        else ans+=G[i];
        //writell(ans,10);
        res[q[i].id]=ans;
        /*{
            ll ans2=C;
            static aN vis;
            static ll cnt;
            ++cnt;
            rep(i,l,r){
                rfor(ll x=a[i],j=m[x];x!=1;j=m[x/=p[j]])if(vis[p[j]]!=cnt){
                    rfor(ll k=p[j];k<=C;k+=p[j])if(vis[k]!=cnt)--ans2,vis[k]=cnt;
                }
            }
            writell(l),writell(r),
            writell(ans+1),writell(ans2,10);
            assert(ans+1==ans2);
        }*/
    }
    rep(i,1,T)writell(res[i]+1,10);
    return 0;
}
/*
5 0 100000 3
2 313 71 5 6
1 1
2 4
4 5
*/