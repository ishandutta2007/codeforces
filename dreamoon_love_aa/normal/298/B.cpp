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
char s[100010];
int main(){
    int i,j,k,n,sx,sy,ex,ey;
    scanf("%d%d%d%d%d",&n,&sx,&sy,&ex,&ey);
    scanf("%s",s);
    for(i=0;i<n;i++){
        if(s[i]=='E'&&ex>sx)ex--;
        if(s[i]=='W'&&ex<sx)ex++;
        if(s[i]=='N'&&ey>sy)ey--;
        if(s[i]=='S'&&ey<sy)ey++;
        if(ex==sx&&ey==sy)break;
    }
    if(i<n)printf("%d\n",i+1);
    else puts("-1");
    return 0;
}