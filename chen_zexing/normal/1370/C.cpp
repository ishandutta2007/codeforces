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
int check(long long x)
{
    while(x!=1&&x%2==0) x/=2;
    return x==1;
}
int check2(long long x)
{
    x/=2;
    int f=0;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0){
            f=1;
            break;
        }
    return f;
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        long long n,t=0;
        scanf("%lld",&n);
        if(n==1)
        {
            printf("FastestFinger\n");
        }
        else if(n%2)
        {
            printf("Ashishgup\n");
        }
        else if(!check(n)&&n%4==0||n==2||check2(n)&&n%4)
            printf("Ashishgup\n");
        else printf("FastestFinger\n");

    }
    return 0;
}