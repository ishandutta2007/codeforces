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
char a[1000005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%s",a);
        long long cnt=0,mn=0,ans=0;
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]=='+') cnt++;
            else cnt--;
            if(cnt<mn)
            {
                mn=cnt;
                ans+=i+1;
            }
        }
        printf("%lld\n",ans+strlen(a));
    }
    return 0;
}