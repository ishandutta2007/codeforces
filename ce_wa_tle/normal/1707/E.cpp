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
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;
aN ans,a,st,c,f,ql,qr,ansl,ansr,l[18],r[18];
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
struct node{
    ll l,r,id;
    void read(cll i){
        l=readll(),r=readll(),id=i;
    }
    void calc(ll*res,cll*a){
        //printf("l=%lld find(l)=%lld %lld\n",l,find(l),f[l]);
        res[id]=a[find(l)];
    }
}p[N];
std::mt19937 rd;
void calc(){
    cll n=readll(),m=readll();
    rep(i,1,n)a[i]=readll();
    //cll n=rd()%10+1,m=rd()%10+1;
    //rep(i,1,n)a[i]=rd()%n+1;
    //writell(n),writell(m,10);
    //rep(i,1,n)writell(a[i],i==n?10:32);
    rep(i,1,n-1)l[0][i]=std::min(a[i],a[i+1]),r[0][i]=std::max(a[i],a[i+1])-1;
    rep(i,0,16){
        memset(c,0,(n+1)<<3);
        rep(j,1,n-1)if(l[i][j]&&l[i][j]<=r[i][j])c[r[i][j]]++;else l[i+1][j]=n+1,r[i+1][j]=0;
        rep(j,1,n-1)c[j]+=c[j-1];
        rep(j,1,n-1)if(l[i][j]&&l[i][j]<=r[i][j])p[++c[r[i][j]-1]]=(node){l[i][j],r[i][j],j};
        cll lim=c[n-1];
        //rep(i,1,lim)printf("%lld %lld\n",p[i].l,p[i].r);
        {
            ll k=1,t=0;
            rep(j,1,n-1)f[j]=j;
            rep(j,1,n-1){
                while(t&&r[i][j]>r[i][st[t]])f[st[t--]]=j;
                st[++t]=j;
                while(k<=lim&&p[k].r==j)p[k++].calc(r[i+1],r[i]);
            }
        }
        {
            ll k=1,t=0;
            rep(j,1,n-1)f[j]=j;
            rep(j,1,n-1){
                while(t&&l[i][j]<l[i][st[t]])f[st[t--]]=j;
                st[++t]=j;
                while(k<=lim&&p[k].r==j)p[k++].calc(l[i+1],l[i]);
            }
        }
        //rep(j,1,n-1)writell(l[i][j]),writell(r[i][j],10);
        //pc(10);
    }
    //exit(0);
    //aN tans;
    rep(i,1,m){
        ans[i]=0;
        ql[i]=readll(),qr[i]=readll()-1,ql[i]==1&&qr[i]==n-1?--ans[i]:qr[i]<ql[i]&&(ans[i]=-2);
        //ll l=ql[i],r=qr[i]+1;
        //ll l=rd()%n+1,r=rd()%n+1;
        //if(l>r)std::swap(l,r);
        //writell(l),writell(r,10);
        //ql[i]=l,qr[i]=r-1,ql[i]==1&&qr[i]==n-1?--ans[i]:qr[i]<ql[i]&&(ans[i]=-2);
        /*tans[i]=-1;
        rep(s,0,n){
            if(l==1&&r==n){tans[i]=s;break;}
            ll min=mod,max=-mod;
            rep(j,l,r)min=std::min(min,a[j]),max=std::max(max,a[j]);
            l=min,r=max;
        }*/
    }
    per(i,17,0){
        memset(c,0,(n+1)<<3);
        rep(j,1,m)if(ans[j]>=0)c[qr[j]]++;
        rep(j,1,n-1)c[j]+=c[j-1];
        rep(j,1,m)if(ans[j]>=0)p[++c[qr[j]-1]]=(node){ql[j],qr[j],j};
        cll lim=c[n-1];
        {
            ll k=1,t=0;
            rep(j,1,n-1)f[j]=j;
            rep(j,1,n-1){
                while(t&&r[i][j]>r[i][st[t]])f[st[t--]]=j;
                st[++t]=j;
                while(k<=lim&&p[k].r==j)p[k++].calc(ansr,r[i]);
            }
        }
        {
            ll k=1,t=0;
            rep(j,1,n-1)f[j]=j;
            rep(j,1,n-1){
                while(t&&l[i][j]<l[i][st[t]])f[st[t--]]=j;
                st[++t]=j;
                while(k<=lim&&p[k].r==j)p[k++].calc(ansl,l[i]);
            }
        }
        rep(j,1,m)if(ans[j]>=0){
            if(ansl[j]==0||ansl[j]>ansr[j])ans[j]=-2;
            else if(ansl[j]!=1||ansr[j]!=n-1)ql[j]=ansl[j],qr[j]=ansr[j],ans[j]+=1<<i;
        }
        memset(ansl,0,(n+1)<<3),memset(ansr,0,(n+1)<<3);
    }
    rep(i,1,m)writell(ans[i]+1==1<<18?-1:ans[i]+1,10);
    //writell(tans[i]),writell(ans[i]+1==1<<18?-1:ans[i]+1,10),assert((ans[i]+1==1<<18?-1:ans[i]+1)==tans[i]);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}