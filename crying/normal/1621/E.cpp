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
#define int ll
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=3e5+10;
int T,n,m,a[MAXN];
int info[MAXN],idx[MAXN],sum[MAXN],sz[MAXN];
int d[MAXN];
pi tmp[MAXN];
int front[MAXN],back[MAXN],qwq[MAXN];
bool cmp(pi& p1,pi& p2){return 1ll*p1.fr*sz[p2.se]>1ll*p2.fr*sz[p1.se];}
int qry(int* s,int l,int r){
    if(l>r)return 0;
    if(l==0)return s[r];
    return s[r]-s[l-1];
}
int bs(int s,int c){ 
    int l=1,r=m,ret=m+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(1ll*tmp[mid].fr*c<1ll*s*sz[tmp[mid].se]){
            ret=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ret;
}
void solve(){
    scanf("%lld%lld",&n,&m);
    rep(i,1,n)scanf("%lld",&a[i]);
    int tot=0;
    rep(i,1,m){
        scanf("%lld",&sz[i]);
        sum[i]=0;
        rep(j,1,sz[i]){
            tot++;scanf("%lld",&info[tot]);idx[tot]=i;
            sum[i]+=info[tot];
        }
        tmp[i]=mp(sum[i],i);
    }
    sort(a+1,a+1+n,greater<int>());
    sort(tmp+1,tmp+1+m,cmp);
    rep(i,1,m)d[tmp[i].se]=i;
    rep(i,0,m+1)front[i]=back[i]=qwq[i]=0;
    rep(i,1,m)qwq[i]=qwq[i-1]+(bool)(1ll*a[i]*sz[tmp[i].se]>=tmp[i].fr);
    rep(i,1,m-1)front[i]=front[i-1]+(bool)(1ll*a[i+1]*sz[tmp[i].se]>=tmp[i].fr);
    rep(i,2,m)back[i]=back[i-1]+(bool)(1ll*a[i-1]*sz[tmp[i].se]>=tmp[i].fr);
//    rep(i,1,m)printf("%lld    ",a[i]);printf("\n");
//    rep(i,1,m)printf("%.2f ",1.00*tmp[i].fr/sz[tmp[i].se]);printf("\n");
    rep(i,1,tot){
        int flag=1;
        int x=idx[i];
        int c=sz[x]-1,s=sum[x];x=d[x];
        s-=info[i];
      //  printf("\ns:%d c:%d\n",s,c);
        //xs/c
        //
    //    printf("\ngroup %d become (%d,%d):%.2f\n",x,s,c,1.00*s/c);
        int pos=bs(s,c); //[pos-1,pos]      
      //  printf("group:%d->between %d %d\n",x,pos-1,pos);
        if(pos==x || pos==x+1){
      //      printf("TMP:%d\n",qry(qwq,1,x-1)+qry(qwq,x+1,m));
            flag=(bool)(qry(qwq,1,x-1)+qry(qwq,x+1,m)==m-1)&&(1ll*a[x]*c>=s);
        }else{
            if(pos<x){
                flag=(bool)(qry(front,pos,x-1)==x-pos)&&(1ll*a[pos]*c>=s)
                &&(qry(qwq,1,pos-1)==pos-1)&&(qry(qwq,x+1,m)==m-x);
            }else{
                flag=(bool)(qry(back,x+1,pos-1)==pos-x-1)&&(1ll*a[pos-1]*c>=s)
                &&(qry(qwq,1,x-1)==x-1)&&(qry(qwq,pos,m)==m-pos+1);
            }
        }
        putchar('0'+flag);
    }
    putchar('\n');
}
signed main(){
//    freopen("in.txt","r",stdin);
//   freopen("out.txt","w",stdout);
    scanf("%lld",&T);
    while(T--)solve();
    return 0;
}