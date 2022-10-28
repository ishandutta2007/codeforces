#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
int main()
{
    char ss[6],tt[6];
    int s,t,d;
    cin>>ss>>tt;
    s=(ss[0]-48)*600+(ss[1]-48)*60+(ss[3]-48)*10+ss[4]-48;
    t=(tt[0]-48)*600+(tt[1]-48)*60+(tt[3]-48)*10+tt[4]-48;
    d=s-t;
    if(d<0)
        d+=1440;
    printf("%d",d/600);
    d%=600;
    printf("%d",d/60);
    d%=60;
    printf(":");
    if(d<10)
        printf("0");
    printf("%d",d);
    return 0;
}