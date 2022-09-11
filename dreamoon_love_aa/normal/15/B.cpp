#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
main(){
    int t,n,m,x1,y1,x2,y2;
    long long an;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        if((x2-x1)*2>n||(y2-y1)*2>m)an=(long long)n*m-(long long)(n-x2+x1)*(m-y2+y1)*2;
        else an=(long long)(x2-x1)*(y2-y1)*2;
        cout<<an<<endl;
    }
}