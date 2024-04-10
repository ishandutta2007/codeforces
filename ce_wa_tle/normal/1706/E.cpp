#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,iz=1<<21,oz=1<<22;
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
cll T=readll();
//cll T=10000000;
aN l,r,u,v,p,f,s,c,q,e,a,k;
ll find(ll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
void calc(){
    cll n=readll(),m=readll(),g=readll();
    //cll n=rand()%10+1,m=rand()%100+1,g=rand()%100+1;
    //writell(n),writell(m),writell(g,10);
    memset(p,0,(n+1)<<3),memset(c,0,(n+1)<<3);
    rep(i,1,n)f[i]=i,s[i]=1;
    rep(i,1,m){
        ll u=find(readll()),v=find(readll());
        //ll u=find(rand()%n+1),v=find(rand()%n+1);
        //writell(u),writell(v,10);
        ::u[i]=u,::v[i]=v;
        if(u==v)continue;
        if(s[u]>s[v])std::swap(u,v);
        rfor(ll j=u;j;j=p[j]){
            if(find(j-1)==v)a[j-1]=i;
            if(find(j+1)==v)a[j]=i;
            if(!p[j]){
                p[j]=p[v],p[v]=u;
                break;
            }
        }
        s[v]+=s[u],f[u]=v;
    }
    rep(i,1,g)l[i]=readll(),r[i]=readll()-1,l[i]<=r[i]?++c[r[i]]:e[i]=0;
    /*rep(i,1,g){
        ll sl=rand()%n+1,sr=rand()%n+1;
        if(sl>sr)std::swap(sl,sr);
        //writell(sl),writell(sr,10);
        l[i]=sl,r[i]=sr-1,l[i]<=r[i]?++c[r[i]]:e[i]=0;
    }*/
    rep(i,1,n)c[i]+=c[i-1];
    ll j=1,t=0,z=c[n];
    rep(i,1,g)l[i]<=r[i]&&(q[++c[r[i]-1]]=i);
    rep(i,1,n)f[i]=i;
    rep(i,1,n-1){
        while(t&&a[i]>a[k[t]])f[k[t--]]=i;
        k[++t]=i;
        while(j<=z&&r[q[j]]==i)e[q[j]]=a[find(l[q[j]])],j++;
    }
    rep(i,1,g)writell(e[i],i==n?10:32);
    /*rep(i,1,n-1){
        rep(j,1,n)f[j]=j;
        rep(j,0,m){
            if(j)f[find(u[j])]=find(v[j]);
            ll flag=1;
            if(find(i)!=find(i+1))flag=0;//,printf("k=%lld a=%lld b=%lld\n",k,find(k),find(k+1));
            if(flag){
                //printf("a=%lld j=%lld\n",a[i],j);
                assert(a[i]==j);
                break;
            }
        }
    }
    rep(i,1,g){
        rep(j,1,n)f[j]=j;
        rep(j,0,m){
            if(j)f[find(u[j])]=find(v[j]);
            ll flag=1;
            rep(k,l[i],r[i])if(find(k)!=find(k+1))flag=0;//,printf("k=%lld a=%lld b=%lld\n",k,find(k),find(k+1));
            if(flag){
                //printf("e=%lld j=%lld\n",e[i],j);
                assert(e[i]==j);
                break;
            }
        }
    }*/
}
int main(){
    rep(i,1,T)calc();
    return 0;
}