#include<stdio.h>
#include<algorithm>
using namespace std;
long long N,M;
long long C(long long x,long long y){
    if(y==1)return x;
    long long res=C(x-1,y-1);
    res*=x;
    res/=y;
    return res;
}
bool valid(int n){
    long long now=1,need=0;
    for(int i=1;i<=n;i++){
        long long tmp=C(n,i);
        need+=min(tmp,N-now)*i;
        if(need>n*M)return 0;
        now+=tmp;
        if(now>=N)return 1;
    }
    return 0;
}
int f(){
    M=min(M,N-M);
    int ll=1,rr=N;
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(valid(mm))rr=mm;
        else ll=mm+1;
    }
    return ll;
}
int main(){
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&N,&M);
        if(N==1){
            puts("0");
            continue;
        }
        int an=2000000000;
        if(M<=N-M)an=f();
        else{
            if(N/2+1<=M){
                M=N/2+1;
                an=f();
            }
            M=N/2;
            an=min(an,f());
        }
        printf("%d\n",an);
    }
    return 0;
}