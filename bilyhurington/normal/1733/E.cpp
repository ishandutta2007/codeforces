#include<bits/stdc++.h>
using namespace std;
int q,n=120;
long long val[130][130];
long long calc(long long v,int x,int y){
    if(v<0) return 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            val[i][j]=0;
        }
    }
    val[0][0]=v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            val[i][j+1]+=(val[i][j]+1)/2;
            val[i+1][j]+=val[i][j]/2;
        }
    }
    return val[x][y];
}
int main(){
    scanf("%d",&q);
    while(q--){
        long long t;int x,y;
        scanf("%lld %d %d",&t,&x,&y);
        t-=x+y;
        if(calc(t,x,y)<calc(t+1,x,y)) puts("YES");
        else puts("NO");
    }
    return 0;
}