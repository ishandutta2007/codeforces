#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6,P=1e9+7;
int a[N];
ll fpw(ll x,ll y){
    ll s=1; for (;y;y>>=1,x*=x) if (y&1) s*=x; return s;
}
int fpw(int x,int y,int P){
    ll s=1;
    for (;y;y>>=1,x=(ll)x*x%P) if (y&1) s=(ll)s*x%P;
    return s;
}
int main(){
    int T; scanf("%d",&T);
    while (T--){
         int n,p; scanf("%d%d",&n,&p);
         rep(i,1,n) scanf("%d",&a[i]);
         if (p==1){ printf("%d\n",n&1); continue; }
         sort(a+1,a+1+n),reverse(a+1,a+1+n);
         int lst=-1,c=0,t=0,ans=0,mx=0;
         for (int tmp=n;tmp;tmp/=p) ++mx;
         rep(i,1,n){
             int x=fpw(p,a[i],P);
             if (a[i]==lst||t){
                ans=(ans+P-x)%P;
                if (!--c) lst=-1;
             }
             else if (lst!=-1){
                ans=(ans+P-x)%P;
                ll tmp=c*fpw(p,lst-a[i])-1;
                if (lst-a[i]>mx||tmp>n) t=1;
                else lst=a[i],c=tmp;
             }
             else ans=(ans+x)%P,lst=a[i],c=1;
         }
         printf("%d\n",ans);
    }
    return 0;
}