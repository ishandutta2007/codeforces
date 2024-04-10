#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=3005;
const int MOD=998244353;
int mul(int x,int y){return 1ll*x*y%MOD;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
int qpow(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=mul(ret,x);
        x=mul(x,x);
        y>>=1;
    }
    return ret;
}
int INV(int x){return qpow(x,MOD-2);}

int sum1=0,sum2=0,n,m,a[N],w[N];
void init(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(a[i]==0) sum2+=w[i];
        else sum1+=w[i]; 
    }
}

int P[M][M];
void calc1(){
    P[0][0]=1;
    for(int i=0;i<m;i++){
        for(int ad=0;ad<=i;ad++){
            int sb=i-ad; if(sb>sum2) continue;
            int now1=sum1+ad,now2=sum2-sb,now=now1+now2;
            int inv=INV(now);
            P[i+1][ad+1]=add(P[i+1][ad+1],mul(P[i][ad],mul(now1,inv)));
            P[i+1][ad]=add(P[i+1][ad],mul(P[i][ad],mul(now2,inv)));
        }
    }
}

int dp1[M],dp2[M],ans[N];//1:add 2:sub
void calc2(){
    dp1[0]=1;
    for(int i=1;i<=m;i++) dp1[i]=add(dp1[i-1],mul(dp1[i-1],INV(sum1+i-1)));
    int ans1=0;
    for(int i=0;i<=m;i++) ans1=add(ans1,mul(dp1[i],P[m][i]));
    for(int i=1;i<=n;i++) if(a[i]==1) ans[i]=mul(w[i],ans1);
    
    dp2[0]=1;
    for(int i=1;i<=m;i++) dp2[i]=sub(dp2[i-1],mul(dp2[i-1],INV(sum2-i+1)));
    int ans2=0;
    for(int i=0;i<=m;i++) ans2=add(ans2,mul(dp2[i],P[m][m-i]));
    for(int i=1;i<=n;i++) if(a[i]==0) ans[i]=mul(w[i],ans2);    
}

int main(){
    init(); 
    calc1(); calc2();
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}