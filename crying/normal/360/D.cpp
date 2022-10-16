#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e4+10,MAXM=1e5+10;
int mypow(int a,int n,int mod=998244353){
    if(!n)return 1;
    int tmp=mypow(a,n/2,mod);tmp=1ll*tmp*tmp%mod;
    if(n&1)tmp=1ll*tmp*a%mod;return tmp;
}
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int n,m,p,g;
int a[MAXN],b[MAXM];
int s[MAXN],tot,tag[MAXN],f[MAXN],ans;
vector<int>d;
int main(){
    scanf("%d%d%d",&n,&m,&p);g=(p-1);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,m)scanf("%d",&b[i]),g=gcd(g,b[i]);
    rep(i,1,(p-1)){
        if(i*i>(p-1))break;
        if(i*i==(p-1)){
            if((p-1)%i==0)d.pb(i);
        }else{
            if((p-1)%i==0)d.pb(i),d.pb((p-1)/i);
        }
    }
    sort(d.begin(),d.end());
    rep(i,1,n){
        a[i]=mypow(a[i],g,p);
        //a[i]
        int c=0;
        for(auto u:d){
            if(mypow(a[i],u,p)==1){
                c=u;break;
            }
        }
        if(a[i]==1)c=1;
        s[i]=(p-1)/c;
    }
    sort(s+1,s+1+n);
    tot=unique(s+1,s+1+n)-s-1;
    int sz=d.size();
    rep(i,0,sz-1){
        rep(j,1,tot){
            if(d[i]%s[j]==0){
                tag[i]=1;break;
            }
        }
    }
    per(i,sz-1,0){
        if(!tag[i])continue;
        f[i]=(p-1)/d[i];
        rep(j,i+1,sz-1){
            if(d[j]%d[i]==0){
                f[i]-=f[j];
            }
        }
        ans+=f[i];
    }
    printf("%d",ans);
    return 0;
}