#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int a,b,c,d,x[N],n1,n2;
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);n1=a+c;n2=b+d;
    if(abs(n1-n2)>1)puts("NO"),exit(0);
    if(n1>=n2){
        int p=1;
        for(int j=1;j<=a;j++)x[p]=0,p+=2;
        for(int j=1;j<=c;j++)x[p]=2,p+=2;
        p=2;
        for(int j=1;j<=b;j++)x[p]=1,p+=2;
        for(int j=1;j<=d;j++)x[p]=3,p+=2;
    }
    else{
        int p=1;
        for(int j=1;j<=b;j++)x[p]=1,p+=2;
        for(int j=1;j<=d;j++)x[p]=3,p+=2;
        p=2;
        for(int j=1;j<=a;j++)x[p]=0,p+=2;
        for(int j=1;j<=c;j++)x[p]=2,p+=2;
    }
    bool flag=0;
    for(int i=2;i<=n1+n2;i++)if(abs(x[i]-x[i-1])!=1)flag=1;
    if(!flag){
        puts("YES");
        for(int i=1;i<=n1+n2;i++)printf("%d ",x[i]);
    }
    else puts("NO");
    return 0;
}