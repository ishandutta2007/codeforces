#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353,inf=1e18;typedef ll aN[N];aN sa,tp_,rk_,nxt;ll*tp=tp_,*rk=rk_;
ll n,m,k;char s[17][2000],t[2000],pre[2][2000],suc[2][2000];ll g[2][2],f[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void sort(ll*sa,const ll*tp,const ll*rk,ll n,ll m){static aN a;memset(a,0,sizeof(ll)*(m+1));
    rep(i,1,n)a[rk[i]]++;rep(i,1,m)a[i]+=a[i-1];per(i,n,1)sa[a[rk[tp[i]]]--]=tp[i];
}ll calc(const char*s,const char*t,ll p){/*puts(s),puts(t);*/ll n=strlen(s);ll flag=0;
    if(p){nxt[0]=-1;rfor(ll i=1,j=-1;i<n;i++){while(~j&&s[i]!=s[j+1])j=nxt[j];if(s[i]==s[j+1])j++;nxt[i]=j;}}
    rfor(ll i=0,j=-1;t[i];i++){while(~j&&t[i]!=s[j+1])j=nxt[j];if(t[i]==s[j+1])j++;if(j==n-1)flag++;}return flag;
}ll calc(){
    ll n=strlen(t);strcpy(pre[0],s[14]),pre[0][n-1]=0,strcpy(pre[1],s[15]),pre[1][n-1]=0;
    strcpy(suc[0],s[14]+(strlen(s[14])-n-1)),strcpy(suc[1],s[15]+(strlen(s[15])-n-1));rep(i,14,15)f[i]=calc(t,s[i],i==14); 
    char ss[2000];rep(i,0,1)rep(j,0,1)strcpy(ss,suc[i]),strcat(ss,pre[j]),g[i][j]=calc(t,ss,0);
    rep(i,16,::n){f[i]=f[i-1]+f[i-2]+g[i!=16][i&1];if(f[i]>inf)return f[i];}return f[::n];
}int main(){
    strcpy(s[0],"0"),strcpy(s[1],"1");
    rep(i,2,15)strcpy(s[i],s[i-2]),strcat(s[i],s[i-1]);n=readll(),k=readll(),m=readll();if(n<=15){ll t=n;n=strlen(s[t]);
        rep(i,1,n)rk[i]=s[t][i-1]-'0',tp[i]=i;sort(sa,tp,rk,n,2);rfor(ll w=1,m=2,p=0;p=0,w<=n&&(w==1||m<n);m=p,w<<=1){
            rep(i,n-w+1,n)tp[++p]=i;rep(i,1,n)if(sa[i]>w)tp[++p]=sa[i]-w;sort(sa,tp,rk,n,m),std::swap(tp,rk);
            p=rk[sa[1]]=1;rep(i,2,n)rk[sa[i]]=sa[i]+w<=n&&tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w]?p:++p;
        }/*puts(s[t]);rep(i,1,n)printf("%lld\n",sa[i]);*/ll i=sa[k]-1;s[t][i+m]=0;puts(s[t]+i);return 0;
    }ref(i,0,m){t[i]='0';ll s=calc();if(k>s)k-=s,t[i]='1';if(!k){puts(t);return 0;}}puts(t);return 0;
}