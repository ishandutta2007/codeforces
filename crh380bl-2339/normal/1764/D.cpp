#include<bits/stdc++.h>
using namespace std;
int fac[10002];
int ifac[10002];
int qpow(int x,int y, int p){
    int t=1;
    for(;y;y>>=1){
        if(y&1)t=1LL*t*x%p;
        x=1LL*x*x%p;
    }
    return t;
}
int C(int n, int m, int p){
    if(n<m||m<0)return 0;
    return 1LL*fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int A[100004];
int main(){
    int n, p, i, j;
    long long ans = 0;
    scanf("%d%d",&n,&p);
    fac[0]=1;
    for(i=1;i<=10000;++i)fac[i]=1LL*i*fac[i-1]%p;
    for(i=0;i<=10000;++i)ifac[i]=qpow(fac[i], p-2, p);
    for(int d2=1;d2<=n-2;++d2){
        int s=0,t1;
        for(j=0;j<d2;++j){
            t1 = 1LL*C(d2-1, j, p)*fac[j+n-d2-2]%p;
            s=(s+t1)%p;
        }
        A[d2]=s;
        //printf("%d ",A[d2]);
    }
    for(i=1;i<=n;++i){
        for(j=i+1;j<=n;++j){
            if(n%2==0 && (j-i)%(n/2) == 0){
                ans += 2LL*fac[n-2];
                //puts("haha");
                ans%=p;
            }
        }
    }
    long long tmp = 0;
    for(i=1;i<n;++i){
        for(j=i+1;j<n;++j){
            int d1 = i, d2 = j-i;
            int d3 = n-j;
            if(max(d1, d3)*2<=n && d2*2<n){
                tmp = (tmp + A[d2])%p;
                //printf("%d %d %d\n",0,i,j);
            }
        }
    }
    ans = (ans + 1LL*tmp*n)%p;
    printf("%lld\n",ans);
    return 0;
}