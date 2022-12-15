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
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        if(n==1) printf("1\n");
        else if(n%2) printf("%lld\n",min((n-3)/4+((n-3)%4>0)+1+n/4+(n%4>0),(n-2)/4+((n-2)%4>0)+1+(n-1)/4+((n-1)%4>0)));
        else printf("%lld\n",(n-2)/4+((n-2)%4>0)+1+n/4+(n%4>0));
    }
}