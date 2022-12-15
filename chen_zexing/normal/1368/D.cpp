#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;
int bin[30];
int main() {
    int n,k,t,now=0;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        t=0;
        scanf("%d",&k);
        while(k)
        {
            bin[t++]+=k%2;
            k/=2;
        }
    }
    while(now<=20)
    {
        if(bin[now]==0)
        {
            now++;
            continue;
        }
        t=now;
        long long cnt=pow(2,t);
        bin[t]--;
        t++;
        while(t<=20)
        {
            if(bin[t]){
                cnt+=pow(2,t);
                bin[t]--;
            }
            t++;
        }
        cnt*=cnt;
        ans+=cnt;
        //cout<<cnt<<endl;
    }
    printf("%lld",ans);
    return 0;
}