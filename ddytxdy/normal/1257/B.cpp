#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace ZBK{
int t,x,y;
void main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        if(x==1)puts(y==1?"Yes":"No");
        else if(x==2||x==3)puts(y<=3?"Yes":"no");
        else puts("Yes");
    }
}
}
int main(){ZBK::main();return 0;}