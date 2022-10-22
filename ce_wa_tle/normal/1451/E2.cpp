#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=4e5+5,inf=1e9;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
enum oper{AND=0,OR,XOR};char s[3][4]={"AND","OR","XOR"};ll n;
ll query(oper op,ll i,ll j){printf("%s %lld %lld\n",s[op],i,j),fflush(stdout);return readll();}
aN a,t,l,f;void putans(){printf("!");rep(i,1,n)printf(" %lld",a[i]);puts(""),fflush(stdout);}
int main(){
    n=readll();ll x=-1,y;t[0]++,f[0]=1;rep(i,2,n)++t[a[i]=query(XOR,1,i)],!f[a[l[a[i]]=i]]&&(f[a[i]]=i);
    ref(i,0,n)if(t[i]>1){x=i;break;}y=~x?x^query(AND,f[x],l[x]):query(AND,1,f[1])^(query(AND,1,f[2])&1);
    rep(i,1,n)a[i]^=y;putans();
}