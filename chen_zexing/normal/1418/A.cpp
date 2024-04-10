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
long long a[505];
int main() {
    int T;
    cin>>T;
    while(T--){
        long long x,y,k,ans=0;
        scanf("%lld%lld%lld",&x,&y,&k);
        long long p=k-1;
        p+=k*y,ans+=k;
        ans+=p/(x-1)+(p%(x-1)>0);
        printf("%lld\n",ans);
    }
    return 0;
}