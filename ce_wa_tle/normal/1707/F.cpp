#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,gc=fgc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fout(int c){
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
cll IO_res=IO(),T=1;//200000;
ll pow(ll a,cll b,cll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
int s[10000001],d[1<<25],c[1<<25],pre[33];
void change(ll&a,ll&b,cll x,cll y){
    /*rep(i,0,23)writell(s[i],32);pc(10);
    ref(i,0,8){
        ll c=0;
        rfor(ll j=i;j<24;j+=8)if(s[j]==-1){c=-1;break;}
        else c^=s[j];
        writell(c,i==7?10:32);
    }*/
    //printf("%lld %lld %lld %lld\n",a,b,x,y);
    ll type=(s[x]==-1)<<1|(y==-1),val=s[x]^y^(type==1||type==2?-1:0);
    if(type==3)return;
    s[x]=y,b+=(type==1)-(type==2);
    rfor(ll i=pre[30];~i;i=pre[i]){
        //printf("%lld %lld %lld\n",i,type,val);
        cll w=2<<i|(x&((2<<i)-1)),y=w^1<<i;
        //printf("w=%lld y=%lld c[w]=%d c[y]=%d d[w]=%d d[y]=%d\n",w,y,c[w],c[y],d[w],d[y]);
        d[w]^=val;
        switch(type){
            case 0://val to val
            //if(!val)return;
            if(c[w])return;
            if(!c[y]){
                if((d[w]^d[y])!=val)a--;
                else val^=d[y];
                if(d[w]!=d[y])a++;
                else val^=d[y];
            }
            break;
            case 1://val to -1
            if(c[w]++)return;
            val^=d[w];
            if(!c[y]){
                b--;
                if(val!=d[y])a--,type=0;
                else return;
            }
            break;
            case 2://-1 to val
            if(--c[w])return;
            val=d[w];
            if(!c[y]){
                b++;
                if(val!=d[y])a++,type=0;
                else return;
            }
            break;
        }
    }
}
std::mt19937 rd(432543);
void calc(){
    cll n=readll(),m=readll(),t=std::min(n&-n,readll()),w=1<<readll();
    //cll n=rd()%10+1,m=0,t=std::min(n&-n,(ll)(rd()%10+1)),w=1<<3;
    //printf("%lld %lld %lld %lld\n",n,m,t,w);
    ll lst=30;
    ll a=0,b=n;
    memset(s,-1,(n+1)<<2);
    per(i,30,0)if(t>>i&1){
        cll z=lst==30?n>>(i+1):1<<(lst-i-1),f=lst==30?(n+(1<<i))>>(i+1):1<<(lst-i-1);
        pre[lst]=i,lst=i,b-=1<<i;
        //printf("i=%lld,f=%lld,z=%lld\n",i,f,z);
        ref(j,0,1<<i)c[j+(2<<i)]=f;
        ref(j,0,1<<i)c[j+(3<<i)]=z;
        
        //ref(j,0,1<<i)d[j+(2<<i)]=0;
        //ref(j,0,1<<i)d[j+(3<<i)]=0;
    }
    pre[lst]=-1;
    rep(i,1,m){
        cll x=readll()-1,y=readll();
        //cll x=rd()%n,y=rd()%3?rd()&(w-1):-1;
        change(a,b,x,y);
    }
    cll q=readll();
    //cll q=1000;
    rep(i,1,q){
        cll x=readll()-1,y=readll(),p=readll();
        //cll x=rd()%n,y=rd()%3?rd()&(w-1):-1,p=rd()&((1<<30)-1);
        //printf("%lld %lld %lld\n",x,y,p);
        change(a,b,x,y);
        //printf("a=%lld b=%lld\n",a,b);
        writell(a?0:pow(w,b,p),10);
        /*ll flag=0,sm=0,len=n,g[len*2]={};
        ref(i,0,n){
            g[i]=s[i];
            if(s[i]==-1)sm++;
        }
        rfor(ll i=pre[30];~i;i=pre[i]){
            //ref(j,0,len)printf("%lld ",g[j]);puts("");
            cll n=2<<i,m=1<<i;
            ref(j,n,len)if(g[j]==-1||g[j%n]==-1)g[j%n]=-1;
            else g[j%n]^=g[j];
            ref(j,0,m)if(g[j+m]!=-1){
                if(g[j]!=-1){
                    sm++;
                    if(g[j]!=g[j+m])flag=1;
                }
                g[j]=g[j+m];
            }
            sm-=m;
            len=m;
        }
        ll sum2=flag?0:pow(w,sm,p);
        printf("sum2=%lld sum=%lld %lld %lld\n",sum2,(a?0:pow(w,b,p)),b,sm);
        assert((a?0:pow(w,b,p))==sum2);*/
    }
}
int main(){
    rep(i,1,T)calc();
    return 0;
}