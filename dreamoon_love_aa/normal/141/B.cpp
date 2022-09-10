#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
void no(){
    puts("-1");
    exit(0);
}
int main(){
    int i,j,k,n,a,x,y,h;
    scanf("%d%d%d",&a,&x,&y);
    if(y<=0)no();
    if(y%a==0)no();
    h=y/a;
    if(h==0||(h-1)%2==0){
        if(abs(x)*2>=a)no();
        if(h==0)puts("1");
        else printf("%d\n",(h-1)/2*3+2);
    }
    else{
        if(abs(x)>=a||x==0)no();
        if(x<0)printf("%d\n",h/2*3);
        else printf("%d\n",h/2*3+1);
    }
    return 0;
}