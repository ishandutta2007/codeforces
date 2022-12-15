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
long long ans[2000005];
int main() {
    ans[1]=ans[2]=0;
    ans[3]=ans[4]=4;
    for(int i=5;i<=2000000;i++)
        ans[i]=(2*ans[i-2]+ans[i-1]+(i%3==0)*4)%1000000007;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}