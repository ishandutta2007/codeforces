#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x"in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1!=o2)fout();
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
void writell(ll u,int c=32){
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
typedef long double ld;
const ll p[]={2,3,5,7,11,13,17,19,31};
ll mul(ll a,ll b,ll p){
    if(a>p)a%=p;
    if(b>p)b%=p;
    ll c=(ull)a*b-(ull)((ld)a*b/p)*p;
    if((c%=p)<0)c+=p;
    return c;
}
ll pow(ll a,ll b,ll p){
    ll res=1;
    red(i,b){
        if(i&1)res=mul(res,a,p);
        a=mul(a,a,p);
    }
    return res;
}
ll is_prime(ll n){
    if(n==1)return 0;
    if(~n&1)return n==2;
	ll c=__builtin_ctzll(n-1),u=(n-1)>>c;
	rep(k,0,8){
		ll a=pow(p[k],u,n);
		if(a<=1||a==n-1)continue;
		rep(i,1,c-1){
			a=mul(a,a,n);
			if(a==n-1)break;
			if(a==1)return 0;
		}
		if(a!=n-1)return 0;
	}
	return 1;
}
aN c,a,mp;
int cmp(ll x,ll y){
    return mp[x]>mp[y];
}
int qmin(ll&a,ll b){
    return a>b?a=b,1:0;
}
int main(){
    IO();
    ll n=readll(),k=readll();
    rep(i,1,n){
        ld m=logl(a[c[i]=i]=readll());
        per(j,60,1){
            ll x=expl(m/j)+0.001;
            if(pow(x,j,a[i]+1)==a[i]){
                if(is_prime(x))mp[i]=x;
                break;
            }
        }
    }
    std::sort(c+1,c+n+1,cmp);
    rep(i,3,n)if(mp[c[i]]&&mp[c[i]]==mp[c[i-2]])mp[c[i-2]]=0;
    rep(i,1,n)if((i==1||mp[c[i]]!=mp[c[i-1]])&&(i==n||mp[c[i]]!=mp[c[i+1]]))mp[c[i]]=0;
    std::sort(c+1,c+n+1,cmp);
    ll t=0,min=mod,mini=0,tot=n;
    while(mp[c[2*t+1]])t++;
    rep(i,1,n)if(!mp[i]){
        ll now=a[i],s=0; 
        rep(j,1,t){
            ll p=mp[c[2*j]];
            if(now%p==0){
                s++;
                while(now%p==0)now/=p;
            }
        }
        mp[i]=-1,tot--;
        if(now!=1)continue;
        mp[i]=0,tot++;
        if(qmin(min,s))mini=i;
    }
    std::sort(c+1,c+n+1,cmp);
    if(k>=t*2?k>tot:k&1&&k<min*2+1)return!myputs("0");
    if(k>t*2||~k&1){
        rep(i,1,k)writell(a[c[i]]);
        return 0;
    }
    k--,writell(a[mini]);
    rep(i,1,2*t)if(0==a[mini]%mp[c[i]])writell(a[c[i]]),k--;
    rep(i,1,2*t)if(k&&a[mini]%mp[c[i]])writell(a[c[i]]),k--;
    return 0;
}