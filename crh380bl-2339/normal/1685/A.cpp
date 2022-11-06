#include<bits/stdc++.h>
using namespace std;
#define N 100005
int a[N],b[N];
bool chk(int n){
    b[n+1]=b[1];
    b[n+2]=b[2];
    for(int i=2;i<=n+1;++i){
        if(1LL*(b[i]-b[i-1])*(b[i]-b[i+1])<=0)return 0;
    }
    return 1;
}
void work(){
    int n,i,num=0,j=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&a[i]);
    if(n&1){
        puts("NO");
        return;
    }
    sort(a+1,a+1+n);
    for(i=1;i*2<=n;++i){
        b[2*i-1]=a[i];
    }
    for(;i<=n;++i){
        j+=2;
        b[j]=a[i];
    }
    if(chk(n)){
        puts("YES");
        for(i=1;i<=n;++i)printf("%d " ,b[i]);puts("");
    }
    else puts("NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}