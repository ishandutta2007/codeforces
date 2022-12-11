#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e6+50;
int t,n,x,y,a[8*300],b[N],c[8*300],num,stck[310];LL xx;bool flag[N];
void init(){
    for(int i=1;i<=num;i++)b[a[i]]=0,c[i]=0;
    for(int i=1;i<=n;i++)flag[stck[i]]=0;
    num=0;xx=1;
}
LL power(LL x,int y){
    LL ret=1;
    while(y){
        if(y&1)ret*=x;
        x*=x;y>>=1;
    }
    return ret;
}
int main(){
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            flag[x]=1;stck[i]=x;
            for(int i=2;i<=sqrt(x);i++){
                if(x%i)continue;
                if(!b[i])a[++num]=i,b[i]=num;
                int numm=0;
                while(x%i==0){
                    numm++;x/=i;
                }
                c[b[i]]=max(c[b[i]],numm);
            }
            if(x!=1&&!b[x]){
                a[++num]=x;b[x]=num;c[num]=1;
            }
        }
        if(num==1&&c[1]==n){
            cout<<power(a[1],n+1)<<endl;continue;
        }
        LL numm=1;
        for(int i=1;i<=num;i++){
            numm*=c[i]+1;
        }
        if(numm-2!=n){
            puts("-1");continue;
        }
        for(int i=1;i<=num;i++)xx*=power(a[i],c[i]);
        if(xx<=1e6&&flag[xx]){
            puts("-1");continue;
        }
        cout<<xx<<endl;
    }
    return 0;
}