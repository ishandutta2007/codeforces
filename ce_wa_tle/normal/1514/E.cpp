#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e6+77,inf=1e18+7;typedef ll aN[N];const ll db=0;
ll f[111][111],ans[111][111],sans[111][111],p[111];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll rd(const char*s,ll a,ll b){if(!db){return readll();}ll res=0;
    switch(s[1]){case'1':res=f[a][b];break;case'2':rep(i,1,b)if(f[a][p[i]])res=1;break;case'3':
    res=1;ref(i,0,a)ref(j,0,b)if(ans[i][j]^sans[i][j])res=0,printf("%lld %lld\n",i,j);}
    printf("%lld\n",res);return res;
}
#define readll() rd(__func__,a,b)
int q1(ll a,ll b){printf("1 %lld %lld\n",a,b),fflush(stdout);return readll();}
int q2(ll a,ll b){if(!b)return 0;printf("2 %lld %lld",a,b);rep(i,1,b)printf(" %lld",p[i]);putchar('\n'),fflush(stdout);return readll();}
int q3(ll a,ll b=0){b=b?:a;puts("3");ref(i,0,a){ref(j,0,b)putchar(ans[i][j]^48);putchar('\n');}fflush(stdout);return readll();}
#undef readll
void calc(int cases){
    ll n=readll();if(db){ref(i,0,n)ref(j,0,n)sans[i][j]=f[i][j]=readchar()^48,i==j&&(sans[i][j]=1);
    ref(k,0,n)ref(i,0,n)ref(j,0,n)sans[i][j]|=sans[i][k]&&sans[k][j];puts("");
    ref(i,0,n){ref(j,0,n)putchar(sans[i][j]^48);putchar('\n');}}rep(i,1,n){ll l=0,r=i;
    while(l<r-1){ll mid=(l+r)>>1;if(q1(p[mid],i-1))l=mid;else r=mid;}per(j,i,r+1)p[j]=p[j-1];p[r]=i-1;}
    ll lst=n,now=n;per(i,n,1){while(now!=1&&q2(p[i],now-1))now--;
	if(now==i){rep(j,i,lst)rep(k,1,n)ans[p[j]][p[k]]=k>=i;now=lst=i-1;}}q3(n);(void)cases;
}int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}
/*
2
6
011111
001101
000111
000010
010001
000100
6
011111
001110
000111
000010
000001
010100
*/