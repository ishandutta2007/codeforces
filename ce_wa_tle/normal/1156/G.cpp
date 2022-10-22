#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+7,mod=998244353,inf=1e18;typedef ll aN[N];
ll cnt=0,tot=0;char s1[1145141],ans[1111][23];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}ll ssh[N];
struct hash{
    #define hs ll now=(b=b?:1e6+8)%mod,x=0;while(now&&key[now]&&key[now]!=b)now=(now+2*x+++1)%mod
    static const ll mod=1e6+7;ll val[mod],key[mod],cg[mod];ll cnt;int count(ll b)const{hs;return key[now]==b;}
    ll operator[](ll b)const{hs;return key[now]==b?val[now]:0;}void clear(){while(cnt)key[cnt--]=0;}
    ll&operator[](ll b){hs;return key[now]!=b?key[now]=b,val[cg[++cnt]=now]=0:val[now];}
}t,t2;const ll mod1=1e9+7,mod2=1e9+9,k1=333,k2=220,mod3=998244353;ll hash_s(const char*s){
    ll a1=0,a2=0;while(*s)a1=(a1*k1+*s)%mod1,a2=(a2*k2+*s)%mod2,s++;return a1*mod2+a2;
};struct lj{ll ls,rs,op;char s[5];lj(){}lj(ll l,ll r,ll o,const char*s_):ls(l),rs(r),op(o),s(""){strcpy(s,s_);}}ml[N];
void link(const char*s1,const char*s2,const char*s3,char op){
//    printf("%s = %s %c %s\n",s1,s2,op,op?s3:"");
    ll h1=hash_s(s1),h2=hash_s(s2),h3=hash_s(s3);if(!t[h2])ml[t[h2]=++cnt]={0,0,0,s2};
    if(op&&!t[h3])ml[t[h3]=++cnt]={0,0,0,s3};ml[++cnt]=op?(lj){t[h2],t[h3],op,s1}:ml[t[h2]];t[h1]=cnt;
}char nows[]="aaa`";void next(char*s){char*t=s;while(*t)t++;t--;while(*t=='z')*t--='a';++*t;}
ll solve(ll u){if(ssh[u])return ssh[u];
    if(!ml[u].ls)return hash_s(ml[u].s)%mod3;ll res=ssh[u]=(((solve(ml[u].ls)*mod1)+solve(ml[u].rs))%mod*137+ml[u].op)%mod3;
    if(t2.count(res)){strcpy(ml[u].s,ml[t2[res]].s);return res;}t2[res]=u;do next(nows);while(t.count(hash_s(nows)));
    strcpy(ml[u].s,nows);sprintf(ans[++tot],"%s=%s%c%s",ml[u].s,ml[ml[u].ls].s,(int)ml[u].op,ml[ml[u].rs].s);return res;
}int main(){
    ll n=readll();rep(i,1,n){scanf("%s",s1);char*s2=s1;while(*s2!='=')s2++;*s2++=0;
    char*s3=s2;while((*s3>='a'&&*s3<='z')||(*s3>='0'&&*s3<='9'))s3++;char ch=*s3;*s3++=0,link(s1,s2,s3,ch);}
//    rep(i,1,cnt)printf("%lld=%lld %lld %c %s\n",i,ml[i].ls,ml[i].rs,(int)ml[i].op,ml[i].s);//exit(0);
    ll root=t[hash_s("res")];if(!root||!ml[root].ls)if(root&&strcmp(ml[root].s,"res"))printf("1\nres=%s",ml[root].s);
    else puts("0");else{solve(root),printf("%lld\n",tot);rep(i,1,tot-1)puts(ans[i]);char*s=ans[tot];
    while(*s++!='=');printf("res=%s\n",s);}return 0; 
}