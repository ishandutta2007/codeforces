#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1e5+7;typedef ll aN[N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}char s[114514],cs[114514];
ll db=0,db2=0;char q[114514];ll fl[114514];ll n;
ll query(const char*s,ll cs=-1){
    printf("? "),puts(s),fflush(stdout);ll len=strlen(s),sz=0;
    if(db){
        sz=0;ref(i,0,n){ll flag=1;ref(j,0,len)if(q[i+j]!=s[j])flag=0;if(flag)fl[++sz]=i;}
        printf("%lld\n",sz);rep(i,1,sz)printf("%lld ",fl[i]+1);puts("");fflush(stdout);
    }
    ll k=db?sz:readll(),fs=0;
    rep(i,1,k){ll f=db?fl[i]:readll()-1;ref(j,0,len)::s[f+j]=s[j];if(f==cs)fs++;}return ~cs?fs:k;
}
void jh(char*cs,const char*s,char a,char b){char add[]={a,b};/*printf("%c %c\n",a,b);*/ll p=0;ref(i,0,4)cs[i]=s[i]?:add[p++];}
ll putans(const char*s){printf("! "),puts(s),fflush(stdout);if(db){ref(i,0,n)if(s[i]!=q[i])exit(-1);}
return db?puts("1"),1:readll();}
char zh[]="CHO";
int solve(){
    ll n=db2?rand()%(50-4+1)+4,4:readll();if(db==1){ref(i,0,n)q[i]=db2?zh[rand()%3]:readchar();
    if(db2){printf("%lld\n",n);ref(i,0,n)putchar(q[i]);puts("");fflush(stdout);}
    q[::n=n]=0;}rep(i,0,n)s[i]=0;
    ll flag=0;flag|=!!query("CC"),flag|=!!query("CH"),flag|=!!query("CO");
    if(n==4){
        ll ss=0;ref(i,0,n)ss+=!!s[i];if(ss==4)return putans(s);
        if(ss==3){ref(i,0,3)if(jh(cs,s,zh[i],' '),i==2||query(cs))return putans(cs);}
        if(ss==2||query("HO"))ref(i,1,3)ref(j,0,3)if(jh(cs,s,zh[i],zh[j]),(i==2&&j==2)||query(cs))return putans(cs);
        if(query("OO")){s[2]=s[2]?:'H';if(!(s[3]||(s[3]='C',query(s))))s[3]='H';return putans(s);}
        s[1]=s[2]='H';query("HHH"),s[0]=s[0]?:'O',s[3]=s[3]?:'C';return putans(s);
    }else{
        query("HO"),query("OO");ref(i,1,n-1)s[i]=s[i]?:'H';if(!s[0]){s[0]='H';if(!query(s,0))s[0]='O';}
        if(!s[n-1]){s[n-1]='H';if(!query(s))s[n-1]='C';}return putans(s);
    }return 0;
}
int main(){ll T=readll();while(T --> 0)if(!solve())return 0;return 0;}