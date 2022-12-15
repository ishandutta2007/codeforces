#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--) {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        if(n%2==0)
        {
            printf("%lld\n",n+k*2);
            continue;
        }
        for(int i=2;i<=n;i++)
            if(n%i==0)
            {
                n+=i;
                k--;
                break;
            }
        printf("%lld\n",n+k*2);
    }
    return 0;
}