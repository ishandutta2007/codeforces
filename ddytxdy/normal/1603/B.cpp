#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+50;
int T,x,y;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
        if(x>y)printf("%d\n",x+y);
        else printf("%d\n",(y%x)/2+y/x*x);
    }
    return 0;
}