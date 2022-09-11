#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1000001
int d[SIZE],an,r[SIZE];
void f(int x,int y){
    while(d[x]!=x)x=d[x];
    while(d[y]!=y)y=d[y];
    if(x==y)return;
    an--;
    if(r[x]>r[y]){
        d[y]=x;
    }
    else if(r[x]<r[y]){
        d[x]=y;
    }
    else{
        d[x]=y;
        r[y]++;
    }
}
main(){
    int n,m,i,x;
    scanf("%d%d",&n,&m);
    if(n<m)swap(n,m);
    for(i=0;i<n;i++)d[i]=i;
    an=n;
    for(i=0;i<n;i++){
        x=i+(m-1)*2;
        if(x>=n)
            x=(n-1)-(x-(n-1));
        if(x<0)
            x=-x;
        f(i,x);
        x=i-(m-1)*2;
        if(x<0)
            x=-x;
        if(x>=n)
            x=(n-1)-(x-(n-1));
        f(i,x);
    }
    printf("%d\n",an);
}