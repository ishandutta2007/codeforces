#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50,mod=1e9+7;
int n,k,p[N],tot,mindiv[N],a[N],num[N],st[N],tp,c[N];LL dat[N],ans;
void pre(){
    for(int i=2;i<N;i++){
        if(!mindiv[i])p[++tot]=mindiv[i]=i;
        for(int j=1,y;j<=tot&&p[j]<=mindiv[i]&&(y=p[j]*i)<N;j++)
            mindiv[y]=p[j];
    }
}
LL power(LL x,int y){
    LL z=1;
    for(;y;y>>=1,x*=x)if(y&1)z*=x;
    return z;
}
int main(){
    scanf("%d%d",&n,&k);pre();
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int x=a[i];dat[i]=1;
        while(x!=1)st[++tp]=mindiv[x],num[mindiv[x]]++,x/=mindiv[x];
        for(int j=1;j<=tp;j++){
            if(num[st[j]]%k&&~dat[i]){
                long double dt=1.0l*dat[i]*pow(st[j]*1.0l,k);
                if(dt>1e10)dat[i]=-1;
                else dat[i]*=power(st[j],k);
            }
            if(num[st[j]]>=k)a[i]/=power(st[j],num[st[j]]/k*k);num[st[j]]=0;
        }
        tp=0;
    }
    for(int i=1;i<=n;i++){if(~dat[i]&&dat[i]/a[i]<N)ans+=c[dat[i]/a[i]];c[a[i]]++;}
    cout<<ans;
    return 0;
}