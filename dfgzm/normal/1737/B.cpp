#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
long long work(long long N){
    if(!N)return 0;
    if(N==1)return 1;
    if(N==2)return 2;
    if(N==3)return 3;
    if(N<=5)return 4;
    if(N<=7)return 5;
    long long Ans=6;
    long long t=sqrt(N);
    if(t>=20)Ans+=1ll*3*(t-12);
    for(int i=(t>=20?t-9:3);;i++){
        if(1ll*i*i<=N)Ans++;
        else break;
        if(1ll*i*(i+1)<=N)Ans++;
        if(1ll*i*(i+2)<=N)Ans++;
    }
    // cerr<<"Work "<<N<<' '<<Ans<<endl;
    return Ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",work(r)-work(l-1));
    }
}