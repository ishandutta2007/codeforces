#include<bits/stdc++.h>
using namespace std;
const int N=2020;
int n,m,x,y;double ans[N],a[N],b[N];
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    if(x==n)puts("0.0000000000"),exit(0);
    for(int i=n-1;i;i--){
        if(m==1)ans[1]+=2;
        else{
            a[1]=0.5;b[1]=(ans[1]+3)/2;
            for(int j=2;j<m;j++)
                a[j]=1/(3-a[j-1]),b[j]=(ans[j]+b[j-1]+4)/(3-a[j-1]);
            ans[m]=(b[m-1]+ans[m]+3)/(2-a[m-1]);
            for(int j=m-1;j;j--)ans[j]=a[j]*ans[j+1]+b[j];
        }
        if(i==x)printf("%.10f",ans[y]),exit(0);
    }
    return 0;
}