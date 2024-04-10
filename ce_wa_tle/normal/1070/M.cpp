#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=7333,inf=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll x,y,d;void read(){x=readll(),y=readll();}int bl()const{return y==0?x<0:y<0;}}p[N];ll n,m;
ll operator*(const node&a,const node&b){return a.x*b.y-a.y*b.x;}
int operator<(const node&a,const node&b){ll c=a.bl(),d=b.bl();return c^d?c<d:a*b>0;}
void solve(std::vector<ll>&a){ll n=a.size();//ref(i,0,n)printf("=%lld %lld\n",a[i],p[a[i]].d);puts("");
    std::vector<ll>v;ref(i,1,n)if(p[a[i]].d>p[a[0]].d)std::swap(a[0],a[i]);
    /*ref(i,0,n)printf("=%lld %lld\n",a[i],p[a[i]].d);puts("");*/std::vector<node>c;c.resize(n);
    if(p[a[0]].d==1)ref(i,0,n)if(!p[a[i]].d){ref(j,0,n)if(p[a[j]].d)printf("%lld %lld\n",a[j]-::n,a[i]);return;}
    ref(i,1,n)c[i]=(node){p[a[i]].x-p[a[0]].x,p[a[i]].y-p[a[0]].y,a[i]};std::sort(c.begin()+1,c.end());
//    ref(i,1,n)printf("=%lld ==%lld\n",c[i].d,1-p[c[i].d].d); 
    ll s=0,r=p[a[0]].d,g=0;ll j=0;ref(i,1,n){while(!g||c[i]*c[j%(n-1)+1]>0)s+=1-p[c[j=j%(n-1)+1].d].d,g++;//printf("ij=%lld %lld %lld\n",i,j,s); 
    if(s>=1&&s<=r-1){v.push_back(a[0]);rfor(ll k=i;k!=j%(n-1)+1;k=k%(n-1)+1)v.push_back(c[k].d);p[a[0]].d=s,solve(v);v.clear();
    v.push_back(a[0]);rfor(ll k=j%(n-1)+1;k!=i;k=k%(n-1)+1)v.push_back(c[k].d);p[a[0]].d=r-s,solve(v);return;}s-=1-p[c[i].d].d,g--;}
}void calc(int cases){(void)cases;n=readll(),m=readll();rep(i,1,n+m)p[i].d=i>n?readll():0;std::vector<ll>v;
    rep(i,1,n+m)p[i].read(),v.push_back((ll)i);puts("YES");solve(v);
}int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}
/*
1
2 3
1 2 1
4 0
0 0
1 1
1 2
3 2
1 1
1
0 0
0 1
*/