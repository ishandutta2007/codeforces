#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout),0))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e5+7,B=107,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(/),T=readll();
char s[N][11],k[N],lst[N];
ll min(cll a,cll b){
    return a<b?a:b;
}
ll max(cll a,cll b){
    return a<b?b:a;
}
void dec(char*lst,ll&t){
    ll s=t;
    while(s&&lst[s]==0)lst[s--]=9;
    lst[s]--;
    if(!lst[1])lst[1]=9,t--;
}
void inc(char*lst,ll&t){
    ll s=t;
    while(s&&lst[s]==9)lst[s--]=0;
    lst[s]++;
    if(s==0)lst[++t]=0,lst[1]=1;
}
void print(char*lst,cll t,int c=10){
    if(!t)pc(48);
    rep(i,1,t)pc(lst[i]^48);
    c&&pc(c);
}
ll h[21];
void calc(){
    cll n=readll();
    mygets(k);
    ref(i,0,n)mygets(s[i]);
    ll t=0;
    ref(i,0,n){
        cll u=k[i]^48;
        h[20]=0;
        per(j,19,0)h[j]=s[i][j%10]==s[i][u]?h[j+1]+1:0;
        //rep(i,0,19)writell(h[i]);pc(10);
        ll flag=1;
        if(h[0]==20){
            if(u)flag=0;
            else lst[++t]=9;
        }else if(t==0){
            rep(i,10,19)if(i!=u+10&&h[i]>=h[u+10])flag=0;//,printf("=%lld\n",i);
            if(flag)lst[++t]=h[u+10]-1;
        }else if(t==1&&lst[1]==1){
            rep(i,0,19)if(i!=u&&h[i]>=h[u])flag=0;
            if(flag)lst[t]=h[u]-1;
        }else flag=0;
        t==1&&lst[1]==0&&t--;
        //printf("flag=%lld\n",flag);
        if(!flag){
            ll a=0,b=0;
            ref(j,0,10)if(j!=u&&s[i][u]==s[i][j]){
                ll now=0;
                while(s[i][u+now]==s[i][j+now])now++;
                a=std::max(a,now);
                while(now<=9&&s[i][(u+now)%10]==s[i][(j+now)%10])now++;
                b=std::max(b,now);
            }
            if(t==0||b==10)lst[++t]=a;
            else if(t==1&&lst[1]==1)lst[1]=max(10-u,b);
            else dec(lst,t),lst[++t]=10-u;
            t==1&&lst[1]==0&&t--;
            
            dec(lst,t);
            ref(j,i+1,n)lst[++t]=9-(k[j]^48),t==1&&lst[1]==0&&t--;
            inc(lst,t);
            break;
        }
    }
    print(lst,t);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
1
1
1
aaaabbaaba
*/