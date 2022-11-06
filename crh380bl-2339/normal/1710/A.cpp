#include<bits/stdc++.h>
using namespace std;
int a[100005];
void work(){
    int n,m,k,i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;++i){
        scanf("%d",&a[i]);
    }
    bool flg1=0,flg2=0;
    long long cnt=0;
    for(i=1;i<=k;++i){
        int tmp=a[i]/n;
        if(tmp>=2)cnt+=tmp;
    }
    flg1 = (cnt>=m);cnt=0;
    if(m&1){
        bool flg3=0; 
        for(i=1;i<=k;++i){
            int tmp=a[i]/n;
            if(tmp>2)flg3=1;
        }
        flg1&=flg3;
    }
    for(i=1;i<=k;++i){
        int tmp=a[i]/m;
        if(tmp>=2)cnt+=tmp;
    }
    flg2 = (cnt>=n);
    if(n&1){
        bool flg4=0;
        for(i=1;i<=k;++i){
            int tmp=a[i]/m;
            if(tmp>2)flg4=1;
        }
        flg2&=flg4;
    }
    if(flg1||flg2){
        puts("Yes");
    }
    else puts("No");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}